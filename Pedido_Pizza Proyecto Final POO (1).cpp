#include <iostream>
#include <string>
using namespace std;

//1. Definicion de una clase
class PedidoPizza
{
	private:
		//2. Atributos (privados para encapsulación)
		string tamano;
		string tipoMasa;
		string estado;
		float precio;
		string ingredientes[10];
		int cantIngredientes;
		
	public:
		//4. Constructores
		PedidoPizza() // Constructor por defecto
		{
			tamano = "Desconocido";
			tipoMasa = "Desconocido";
			precio = 100.0; // Precio base por defecto
			estado = "Desconocido";
			cantIngredientes = 0;
		}
		
		PedidoPizza(string tam) // Constructor con un parametro (sobrecarga)
		{
			tamano = tam;
			tipoMasa = "Desconocido";
			precio = 100.0; // Precio base por defecto
			estado = "Desconocido";
			cantIngredientes = 0;
		}
		
		PedidoPizza(string tam, string masa) // Constructor con dos parametros (sobrecarga)
		{
			tamano = tam;
			tipoMasa = masa;
			precio = 120.0; // Precio ajustado por masa especial
			estado = "Desconocido";
			cantIngredientes = 0;
		}
		
		PedidoPizza(string tam, string masa, int prec) // Constructor con tres parametros (sobrecarga)
		{
			tamano = tam;
			tipoMasa = masa;
			precio = prec;
			estado = "Desconocido";
			cantIngredientes = 0;
		}
	
		PedidoPizza(string tam, string masa, int prec, string est) // Constructor con cuatro parametros (sobrecarga)
		{
			tamano = tam;
			tipoMasa = masa;
			precio = prec;
			estado = est;
			cantIngredientes = 0;
		}
		
		void mostrarDatos()
		{
			cout << "Pizza: " << tamano << "\nMasa: " << tipoMasa << "\nPrecio: $" << precio << endl;
			cout << "Estado: " << estado << endl;
			
			// Mostrar ingredientes si existen
			if (cantIngredientes > 0)
			{
				cout << "Ingredientes extra: ";
				for(int i = 0; i < cantIngredientes; i++)
				{
					cout << "[" << ingredientes[i] << "] ";
				}
				cout << endl;
			}
			else 
			{
				cout << "(Sin ingredientes extra)" << endl;
			}
			cout << endl;
		}
		
		// Metodo auxiliar para agregar ingredientes
		void agregarIngrediente(string ingrediente)
		{
			if (cantIngredientes < 10)
			{
				ingredientes[cantIngredientes] = ingrediente;
				cantIngredientes++;
				precio = precio + 15.0; // Aumenta precio automáticamente
			}
			else
			{
				cout << "No caben mas ingredientes." << endl;
			}
		}
		
		// 6. Metodos de acceso (getters y setters) para encapsulacion
		string getTamano()
		{
			return tamano;
		}
		
		void setTamano(string tam)
		{
			tamano = tam;
		}
		
		string getTipoMasa()
		{
			return tipoMasa;
		}
		
		void setTipoMasa(string masa)
		{
			tipoMasa = masa;
		}
		
		int getPrecio()
		{
			return precio;
		}
		
		void setPrecio(int prec)
		{
			if (prec >= 0)
			{
				precio = prec;
			}
			else
			{
				cout << "El precio no puede ser negativo." << endl;
			}
		}
		
		string getEstado()
		{
			return estado;
		}
		
		void setEstado(string est)
		{
			estado = est;
		}
		
		// Sobrecarga de metodos
		// Metodo sin argumentos
		void entregarPedido()
		{
			estado = "Entregado";
			cout << "\nEl pedido ha sido entregado al cliente en mostrador." << endl;
		}
		
		// Metodo con un argumento (sobrecargado)
		void entregarPedido(string cliente)
		{
			estado = "Entregado";
			cout << "\nEl pedido ha sido entregado a " << cliente << "." << endl;
		}
		
		// Metodo con dos argumentos (sobrecargado)
		void entregarPedido(string cliente, string repartidor)
		{
			estado = "En camino";
			cout << "\nEl pedido va en camino a " << cliente << ", por medio de " << repartidor << "." << endl;
		}
};

int main ()
{
	// Instanciacion de objetos
	PedidoPizza p1;														// Llama a constructor por defecto
	PedidoPizza p2("Grande");											// Llama a constructor con un parametro
	PedidoPizza p3("Mediana", "Orilla Queso");							// Llama a constructor con dos parametros
	PedidoPizza p4("Familiar", "Crunchy", 200.0);						// Llama a constructor con tres parametros
	PedidoPizza p5("Jumbo", "Tradicional", 250.0, "En Preparacion");	// Llama a constructor con cuatro parametros
	
	p5.agregarIngrediente("Peperoni");
	p5.agregarIngrediente("Champinones");
	
	// Mostrar datos usando un metodo
	p1.mostrarDatos();
	p2.mostrarDatos();
	p3.mostrarDatos();
	p4.mostrarDatos();
	p5.mostrarDatos();
	
	// Uso de metodos de acceso
	p1.setTamano("Grande");
	p1.setTipoMasa("Sarten");
	p1.setPrecio(150.0);
	
	cout << "\nNuevos datos de pedido 1 (p1): " << p1.getTamano() << ", " << p1.getTipoMasa() << ", $" << p1.getPrecio() << endl;
	
	// Uso de metodos sobrecargados
	p1.entregarPedido(); 
	p2.entregarPedido("Maria");
	p4.entregarPedido("Carlos", "UberEats");
	
	return 0;
}
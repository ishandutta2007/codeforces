#include <iostream>
using namespace std;

int main() 
{
	int a,b,c; 
	cin >> a >> b >> c; 
	if ( ( a + b + c )  % 2 == 1 ) 
	{
		cout << "Impossible" << endl;
		return 0; 
	}
	
	int e =  ( a + b + c ) / 2; 
	if ( e - a < 0 || e - b < 0 || e - c < 0 ) 
	{
		cout << "Impossible" << endl;
		return 0; 
	}

	cout << e - c << ' ' << e - a << ' ' << e - b << endl;

}
#include <iostream>
using namespace std;

int main()
{
	long long n ; 
	cin >> n; 

	long long counter =0 ; 
	while ( n != 0 ) 
	{
		long long x = n; 
		int b = -1;
		while ( x != 0 ) 
		{
			if ( x % 10 > b ) 
				b = x % 10; 
			x /= 10;
		}

		n-= b; 
		counter++;
	}
	cout << counter << endl;
}
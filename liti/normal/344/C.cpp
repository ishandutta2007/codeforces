#include <iostream>
using namespace std;

int main() 
{
	long long  a,b; 
	cin >> a >> b; 

	long long sum = 0 ; 
	while ( a != 1 ) 
	{
		sum += a/b; 
	//	cout << a << ' ' << b << ' ' << a/b << endl;
		a = a - b*( a/b ); 
		swap(a,b);
	}
	sum += b ; 
	cout << sum << endl;
}
#include <iostream>
using namespace std;

int main() 
{
	long long n; 
	cin >> n; 
	if ( n == 1 ) 
	{
		cout << 0 << endl << 0 << endl << 0 << endl;
		return 0;
	}
	if ( n % 2 == 0 ) 
	{
		cout << -1 << endl;
		return 0;
	}

	long long a[n];
	long long index = -1;
	for(long long i = 1 ; i <=  n ; i++ ) 
	{
		cout << i - 1 << ' ' ;
		index += n/2; 
	//	cout << index % n << endl;
		a[index%n] = i % n; 
	}
	cout << endl;
	for(long long i = 0 ; i < n ; i++ )
		cout << a[i] << ' ';
	cout << endl;
	for(long long i = 0 ; i < n ; i++ )
		cout << (  a[i] + i ) % n << ' ';
	cout << endl;
}
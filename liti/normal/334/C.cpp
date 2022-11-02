#include <iostream>
using namespace std;

int main() 
{
	long long n,m;  
	cin >> n ; 

	m= n ; 
	long long c = 3; 
	while ( m % 3 == 0 ) 
	{
		m/=3;
		c*= 3;
	}

//	cout << c << endl;
	cout <<n / c +1 << endl;
}
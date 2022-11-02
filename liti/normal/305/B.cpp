#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long p, q;
	cin >> p >> q;

	int n ;
	cin >> n ; 

	int i;
	for(i =0 ;i < n; i++ )
	{
		long long a;
		cin >> a; 

		long long b = p / q; 
		p = p - (  b * q );
		swap ( p, q ) ;


		if ( b != a && q != 0 ) 
		{
			cout << "NO" << endl;
			return 0;
		}
		if ( b!= a && q == 0 ) 
		{
			if ( i == n - 2 ) 
			{
				long long s;
				cin >> s;
				if ( s == 1 ) 
				{
					cout << "YES" << endl;
					return 0;
				}
			}
			cout << "NO" << endl;
			return 0;
		
		}
		if ( q == 0 && i != n -1 ) 
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	if ( q == 0 ) 
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
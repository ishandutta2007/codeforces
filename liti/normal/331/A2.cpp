#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n ; 
	cin >> n;

	long long a[n],c[n],sum=0;
	int b[n],u= 0 ,d[n];
	map<long long,int> m;

	for(int i = 0 ; i < n ;i++ )
	{
		c[i] = sum;
		d[i] =u;
		cin >> a[i];
		if ( a[i] >= 0 ) 
			sum += a[i];
		else
			u++;

		if ( m.find( a[i] ) == m.end() ) 
		{
			b[i] = -1;
			m.insert(make_pair( a[i], i ) ) ;
		}
		else
			b[i] = m[a[i]] ;
	}

	int s=-1; 
	long long max = - 1e18;
	for(int i = n-1 ; i>= 0 ; i-- ) 
	{
		if ( b[i] != -1 ) 
		{
			
			if ( a[i] + a[ b[i] ] + c[i] - c[ b[i] + 1 ] > max ) 
			{

				max = a[i] + a[ b[i] ] + c[i] - c[ b[i] + 1 ];
				s = i; 
			}
		}
	}

	cout << max << ' ' << ( n - s - 1 ) + b[s] + d[s] - d[ b[s] + 1 ] << endl;

	
	for(int i = 0 ; i < n ; i++ )
	{
		if ( i < b[s] || i > s ) 
		{
			cout << i + 1 << ' ';
			continue;
		}
		if ( i == s || i == b[s] ) 
			continue;
		if ( a[i] < 0 ) 
			cout << i + 1 << ' ';
	}
	cout << endl;
}
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long a[100001], b[100001];
	long long n, m, k;
	cin >> n >> m >> k;

	long long sum1 = 0, sum2 = 0;
	for(long long i = 0 ; i < n;i++)
	{
		cin >> a[i];
	}	   
	for(long long i = 0 ; i < m ; i++)
	{
		cin >> b[i];
	}
	sort ( a, a + n );
	sort ( b, b + m );
	
	if ( n > m ) 
	{
		cout << "YES" << endl;
		return 0;
	}
	if ( n <= m ) 
	{
		long long sum1 = 0, sum2 = 0;
		for(long long i = n - 1 ; i >= 0 ; i-- )
		{
			sum1 += a[i];
			sum2 += b[i + ( m - n )];

			if ( sum1 > sum2 ) 
			{
				cout << "YES" << endl;
				return 0;
			}
			if ( i != n - 1  && b[i + ( m - n ) ] < b[i + ( m - n ) + 1] )
			{
				sum2 -= (n-1) - i;
			}
			if ( i != n -1 && a[i] < a[i+1] ) 
			{
				sum1 -= (n-1) - i;
			}
		}
	
		cout << "NO" << endl;
		return 0;
	}
	
}
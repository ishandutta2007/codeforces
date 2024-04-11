#include <iostream>
#include <cmath>
using namespace std;

const int limit = 1e5 + 1;
long long a[limit],c[limit],d[limit],e[limit],f[limit];
int main() 
{
	int n;  
	cin>> n ; 
	for(int i = 0 ;i < n - 1 ; i++ )
	{
		cin >> a[i]; 
	}

	long long ans = 0; 
	for(int i = 1 ; i < n ;i++ ) 
	{
		c[i] = max(c[i-1],d[i-1]) + a[i-1] - ( a[i-1] % 2 == 0 ) ; 
		d[i] = d[i-1] + a[i-1] - ( a[i-1] % 2 == 1 ) ;
		if ( a[i-1] < 2 ) 
			d[i] = 0 ; 
	}
	
	for(int i = n-2 ; i >= 0 ;i-- ) 
	{
		e[i] = max(e[i+1],f[i+1]) + a[i] - ( a[i] % 2 == 0 ) ; 
		f[i] = f[i+1] + a[i] - ( a[i] % 2 == 1 )   ; 
		if ( a[i] < 2 ) 
			f[i] = 0; 
	}

	for(int i = 0 ; i < n ;i++ ) 
	{
		long long val = max( c[i],d[i] ) + max ( e[i] , f[i] ) ; 
		if ( val > ans ) 
		{
			ans = val;
//			cout << i << ' ' << c[i] << ' ' << d[i] << ' ' << e[i] << ' ' << f[i] << endl;
		}
	}
	cout << ans << endl;
}
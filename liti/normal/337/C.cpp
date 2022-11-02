#include <iostream>
#include <cmath>

using namespace std;

const long long limit = 1e9 + 9;
long long n,m,k,x,j,a,ans;
long long exp( long long c,long long d ) 
{
	long long b = c,ans = 1; 
	while ( d != 0 ) 
	{
		if ( d % 2 == 1 ) 
		{
			ans = ( ans * b) % limit;
		}
		b = ( b * b ) % limit;
		d = d/2;
	}
	return ans;
}
int main() 
{
	cin >> n >> m >> k; 

//	cout << exp(2, 14) << endl;
	x = n - m ; 

	j = n /  k  ; 

	if ( x >= j ) 
	{
		cout << m << endl;
		return 0; 
	}

	a = j-x; 

//	cout << a << endl;
//	cout << exp(2,a+1) << endl;
	long long ans = ( exp( 2, a + 1 ) - a + limit - 2) % limit; 
	
//	cout << ans << endl;
	ans = ( ans * k ) % limit; 

	ans = ( ans +  m ) % limit; 
	cout << ans << endl;
}
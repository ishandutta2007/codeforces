#include <iostream>
using namespace std;

long long a[1000][1000];
const long long limit = 1e9+7;

int main()
{
	for(int i = 0 ; i < 1000 ;i++ ) 
	{
		a[i][0] = 1; 
	}

	for(int i = 1 ; i < 1000 ; i++ ) 
	{
		for(int j = 1 ; j <= i ; j++ ) 
		{
			a[i][j] = ( a[i-1][j] + a[i-1][j-1] ) % limit;;
		}
	}
	long  n,m,k; 

	cin >> n >> m >> k;
	if ( 2 * k >= m || 2 * k >= n ) 
	{
		cout << 0 << endl;
		return 0;
	}
	cout << (a[m-1][2*k]*a[n-1][2*k]) % limit << endl;
}
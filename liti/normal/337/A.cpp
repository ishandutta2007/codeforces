#include <iostream>
#include <algorithm>
using namespace std;

int a[50];
int main() 
{
	int n,m; 
	cin >> n >> m ; 

	for(int i = 0 ; i < m ;i++ )
		cin >> a[i]; 
	sort( a, a + m ) ; 
	
	
	int ans = 10000;
	for(int i =0  ;i < m ; i++ ) 
	{
		if ( i >= n - 1 ) 
		{

			//	cout << a[i] << ' ' << a[i-n+ 1] << endl;
			if ( a[i] - a[i - n + 1 ] < ans ) 
			{
				ans = a[i] - a[i-n+1];
			}
		}
	}
	cout << ans << endl;
}
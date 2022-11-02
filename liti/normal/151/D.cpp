#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <iomanip>
#include <string>
#include <stack>
#include <cstring>

#define SZ(x) (( (int) x.size() ))

using namespace std;

const long long limit = 1e9 + 7;
int main()
{
	long long n,m,k;
	cin >> n >> m >> k;

	if ( k == 1 || k > n ) 
	{
		long long ans = 1; 
		for(int j =0; j < n ; j++ )
			 ans = ( ans * m ) % limit;
		cout << ans << endl;
		return 0;
	}
	if ( n == k ) 
	{
		long long ans = 1;
		for ( int j  = 0 ; j < n / 2 + ( n % 2 ) ; j++ ) 
			ans = ( ans * m ) % limit;
		cout << ans << endl;
		return 0 ; 
	}
	if ( k % 2 == 0 ) 
	{
		cout << m << endl;
		return 0;
	}
	
	long long ans = m*m  ; 
	cout << ans << endl;
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int n, a[ 100100 ], ans = 0; 
vector< int > cur;

void solve()
{
	cur.clear();
	for ( int i = 1; i <= n; i++ )
	{
		while ( true )
		{
			if ( cur.size() == 0 || cur.back() > a[i] )
			{
				cur.push_back( a[i] );
				break;
			}
			ans = max( ans, cur.back() ^ a[i] );
			cur.pop_back();
		}
	}
}

int main(int argc, char **argv)
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n; for ( int i = 1; i <= n; i++ ) scanf("%d", &a[i]);
	solve();
	reverse( a + 1, a + n + 1 );
	solve();
	cout << ans << endl;
	return 0;
}
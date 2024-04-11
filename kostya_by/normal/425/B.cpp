#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <stack>
#include <bitset>
#include <sstream>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, m, k, a[ 111 ][ 111 ], answer = 11;
bitset< 111 > f[ 111 ], g[ 111 ]; 

void greedy()
{
	for ( int i = 0; i < n; i++ )
	{
		int cur = 0;
		for ( int j = 0; j < n; j++ )
		{
			bitset< 111 > b1 = f[i] ^ f[j];
			bitset< 111 > b2 = f[i] ^ g[j];
			cur += min( b1.count(), b2.count() );
		}
		answer = min( answer, cur );
	}
}

void solve1()
{
	for ( int msk = 0; msk < ( 1 << n ); msk++ )
	{
		bitset< 111 > ff;
		for ( int i = 0; i < n; i++ )
		{
			if ( msk & ( 1 << i ) ) ff.flip( i );
		}
		int cur = 0;
		for ( int j = 0; j < m; j++ )
		{
			bitset< 111 > b1, b2;
			for ( int i = 0; i < n; i++ )
			{
				if ( a[i][j] ) b1.flip(i); else b2.flip(i);
			}
			b1 ^= ff;
			b2 ^= ff;
			cur += min( b1.count(), b2.count() );
		}
		answer = min( answer, cur );
	}
}

int main (int argc, const char * argv[])
{
	cin >> n >> m >> k;
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < m; j++ )
		{
			cin >> a[i][j];
			if ( a[i][j] ) f[i].flip(j); else g[i].flip(j);
		}
	greedy();
	if ( n <= k ) solve1(); 
	if ( answer > k ) answer = -1;
	cout << answer << "\n";
    return 0;
}
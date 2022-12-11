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
#include <stack>
#include <bitset>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const int inf = 1e9;

using namespace std;

int n, lim[ 44 ], nn[ 44 ], nxt[ 26 ], id[ 22 ][ 22 ];
char st[ 22 ][ 22 ];
int f[ 44 ][ 1048576 ];

char ch( int i, int j )
{
	return st[i - 1][j - 1];
}

int main (int argc, const char * argv[])
{
	scanf("%d", &n); gets( st[0] );
	for ( int i = 0; i < n; i++ ) gets( st[i] );
	for ( int i = 1; i <= n; i++ ) lim[i] = (1 << i), nn[i] = i;
	for ( int i = 1; i <= n; i++ ) lim[2 * n - i] = (1 << i), nn[i] = i;	
	for ( int i = 1; i <= 2 * n - 1; i++ )
	{
		int val = ( i & 1 ? inf : -inf );
		for ( int msk = 0; msk < lim[i]; msk++ ) f[i][msk] = val;
		int ii, jj, kk = 1;
		if ( i <= n ) ii = 1, jj = i;
		else ii = i - n + 1, jj = n;
		while ( ii <= n && jj >= 0 ) id[ii++][jj--] = kk++;
	}
	f[2 * n - 1][1] = 0;
	if ( ch( n, n ) == 'a' ) f[2 * n - 1][1]++; 
	if ( ch( n, n ) == 'b' ) f[2 * n - 1][1]--;
	for ( int i = 2 * n - 2; i >= 1; i-- )
		for ( int msk = 1; msk < lim[i]; msk++ )
		{
			for ( int j = 0; j < 26; j++ ) nxt[j] = 0;
			int ii, jj;
			if ( i <= n ) ii = 1, jj = i;
			else ii = i - n + 1, jj = n;
			char c = '0';
			while ( ii <= n && jj >= 0 )
			{
				if ( msk & ( 1 << ( id[ii][jj] - 1 ) ) )
				{
					if ( c == '0' ) c = ch( ii, jj );
					if ( c != ch( ii, jj ) ) c = '-';
 					int i1 = ii + 1, j1 = jj;
					if ( i1 <= n ) nxt[ ch( i1, j1 ) - 'a' ] |= 1 << ( id[i1][j1] - 1 );
					int i2 = ii, j2 = jj + 1;
					if ( j2 <= n ) nxt[ ch( i2, j2 ) - 'a' ] |= 1 << ( id[i2][j2] - 1 );
				}
				ii++; jj--;
			}
			if ( !(i & 1) ) f[i][msk] = -inf; else f[i][msk] = inf;
			if ( c == '-' ) continue;
			for ( int j = 0; j < 26; j++ ) 
			{
				if ( nxt[j] == 0 ) continue;
				if ( !(i & 1) ) f[i][msk] = max( f[i][msk], f[i + 1][nxt[j]] );
				else f[i][msk] = min( f[i][msk], f[i + 1][nxt[j]] );
			}
			if ( c == 'a' ) f[i][msk]++;
			if ( c == 'b' ) f[i][msk]--;
		}
	int ans = f[1][1];
	if ( ans > 0 ) puts("FIRST");
	if ( ans == 0 ) puts("DRAW");
	if ( ans < 0 ) puts("SECOND");
    return 0;
}
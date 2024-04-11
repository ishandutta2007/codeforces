#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>


using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 5050;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn][maxn];
int ans[maxn];
char t[maxn];
int z[maxn];

inline int getC( int l, int r, int AllLen, int CurLen ) {
	return a[l + AllLen - CurLen][r + AllLen - CurLen];
}

void solve( string cur, int len ) {
	for ( int j = 0; j < maxn; j++ )
		z[j] = 0;
	int n = cur.size();
	for ( int i = 1, l = 0, r = 0; i < n; ++i ) {
		if ( i <= r )
			z[i] = min ( r - i + 1, z[i - l] );
		while ( i + z[i] < n && cur[z[i]] == cur[i + z[i]] )
			++z[i];
		if ( i + z[i] - 1 > r )
			l = i,  r = i + z[i] - 1;
	}
	for ( int j = 0; j < n; j++ ) {
		if ( z[j] >= j - 1 ) {
			int cnt1 = getC( 0, j - 2, len, n );
			int cnt2 = getC( j, j + j - 2, len, n );
			int cnt = min( cnt1, cnt2 );
			if ( cnt )
				a[len - n][j + j - 2 + len - n] = max( a[len - n][j + j - 2 + len - n], ++cnt );
		}
		if ( z[j] >= j ) {
			int cnt1 = getC( 0, j - 1, len, n );
			int cnt2 = getC( j, j + j - 1, len, n );
			int cnt = min( cnt1, cnt2 );
			if ( cnt )
				a[len - n][j + j - 1 + len - n] = max( a[len - n][j + j - 1 + len - n], ++cnt );
		}
	}
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    gets( t );
    int n = strlen( t );
    for ( int center = 0; center < n; center++ ) {
    	a[center][center] = 1;
    	int l = center - 1;
    	int r = center + 1;
    	while ( l >= 0 && r < n && a[l + 1][r - 1] && t[l] == t[r] ) {
    		a[l][r] = 1;
    		--l;
    		++r;
    	}
    }
    for ( int center = 0; center < n - 1; center++ ) {
    	if ( t[center] == t[center + 1] )
    		a[center][center + 1] = 1;
    	int l = center - 1;
    	int r = center + 2;
    	while ( l >= 0 && r < n && a[l + 1][r - 1] && t[l] == t[r] ) {
    		a[l][r] = 1;
    		--l;
    		++r;
    	}
    }
    string cur = "";
    for ( int j = n - 1; j >= 0; j-- ) {
    	cur = t[j] + cur;
    	solve( cur, n );
    }
    for ( int j = 0; j < maxn; j++ )
    	for ( int i = 0; i < maxn; i++ )
    		for ( int y = 1; y <= a[j][i]; y++ )
    			++ans[y];
    for ( int j = 1; j <= n; j++ )
    	printf( "%d ", ans[j] );
    return 0;
}
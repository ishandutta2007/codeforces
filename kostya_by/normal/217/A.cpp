//task1

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

int n, x[ 1111 ], y[ 1111 ], p[ 1111 ];
bool used[ 1111 ];

int prev( int x )
{
	int pp;
	if ( p[x] == x ) pp = x; else pp = prev( p[x] );
	p[x] = pp;
	return pp;
} 

void unite( int a, int b )
{
	a = prev( a );
	b = prev( b );
	p[ a ] = b;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) p[i] = i;
	for (int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if ( x[i] == x[j] || y[i] == y[j] ) unite( i, j ); 
		}
	for ( int i = 0; i < n; i++ ) used[ prev( i ) ] = true;
	int ans = 0;
	for ( int i = 0; i < n; i++ ) ans += used[ i ];
	cout << ans - 1;
	return 0;
}
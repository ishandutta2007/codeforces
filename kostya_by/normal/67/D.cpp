#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

struct tv
{
	int l, r, mx;
};

tv tree[ 4000004 ];
int n, x[ 1000001 ], y[ 1000001 ];

void init( int id, int l, int r )
{
	tree[id].l = l;
	tree[id].r = r;
	if ( l == r ) return;
	int x = (l + r) / 2;
	init( id + id, l, x );
	init( id + id + 1, x + 1, r );
}

int fmax( int id, int l, int r )
{
	int ll = tree[id].l;
	int rr = tree[id].r;
	if ( ll == l && r == rr ) return tree[id].mx;
	int res = 0;
	int xx = (ll + rr) / 2;
	if ( l <= xx ) res = max( res, fmax( id + id, l, min( xx, r ) ) );
	if ( xx + 1 <= r ) res = max( res, fmax( id + id + 1, max( xx + 1, l ), r ) );
	return res;
} 

void update( int id, int pos, int val )
{
	if ( tree[id].l == tree[id].r )
	{
		tree[id].mx = val;
		return;
	}
	int x = ( tree[id].l + tree[id].r ) / 2;
	if ( pos <= x ) update( id + id, pos, val ); else update( id + id + 1, pos, val );
	tree[id].mx = max( tree[id + id].mx, tree[id + id + 1].mx );
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &n); 
	for ( int i = 1; i <= n; i++ ) scanf("%d", &x[i]);  
	for ( int i = 1; i <= n; i++ ) 
	{
		int yy;
		scanf("%d", &yy);
		y[yy] = i;
	}
	init( 1, 1, n );
	int ans = 0;
	for ( int i = 1; i <= n; i++ )
	{
		int ff = fmax( 1, y[x[i]], n ) + 1;
		ans = max( ans, ff );
		update( 1, y[x[i]], ff );
	}
	cout << ans << endl;
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back

struct query
{
	int l, r, id;
	query() : l( 0 ), r( 0 ), id( 0 ) {};
	query( int l, int r, int id ) : l( l ), r( r ), id( id ) {};
};

int n, t, a[ 202020 ], num[ 1000001 ], bb[ 202020 ], ll, rr; 
vector< query > qq[ 400 ];
long long ans[ 202020 ], cur = 0;

bool cmp( query q1, query q2 )
{
	if ( q1.r < q2.r ) return true;
	return false;
}

void inc_r()
{
	++rr;
	cur += (long long) a[rr] * ( 2 * num[ a[rr] ] + 1 );
	num[ a[rr] ]++;
}

void dec_l()
{
	--ll;
	cur += (long long) a[ll] * ( 2 * num[ a[ll] ] + 1 );
	num[ a[ll] ]++;
}

void inc_l()
{
	cur += (long long) a[ll] * ( -2 * num[ a[ll] ] + 1 );
	num[ a[ll] ]--;
	++ll;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	for ( int it = 0; it < 400; it++ )
	{
		int ll = it * 500 + 1;
		int rr = ( it + 1 ) * 500;
		for ( int i = ll; i <= rr; i++ ) bb[i] = it;
	}
	scanf("%d%d", &n, &t);
	for ( int i = 1; i <= n; i++ ) scanf("%d", &a[i]);
	for ( int i = 1; i <= t; i++ )
	{
		int l, r;
		scanf("%d%d", &l, &r);
		qq[ bb[l] ].pb( query( l, r, i ) );
	}
	for ( int it = 0; it < 400; it++ ) 
	{
		if ( qq[it].size() == 0 ) continue;
		sort( qq[it].begin(), qq[it].end(), cmp );
		ll = it * 500 + 1;
		rr = it * 500;
		inc_r();
		for ( int i = 0; i < qq[it].size(); i++ )
		{
			while ( rr < qq[it][i].r ) inc_r();
			while ( ll < qq[it][i].l ) inc_l();
			while ( ll > qq[it][i].l ) dec_l();
			ans[ qq[it][i].id ] = cur;
		}
		cur = 0;
		for ( int i = ll; i <= rr; i++ ) num[ a[i] ] = 0; 
	}
	for ( int i = 1; i <= t; i++ ) printf("%I64d\n", ans[i]);
	return 0;
}
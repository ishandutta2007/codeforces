#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

const int mod = 1000000009;

struct tv
{
	int go[4];
	int link, prev, ch, depth, ff;
	bool ok;
	tv()
	{
		for ( int i = 0; i < 4; i++ ) go[i] = -1;
		link = -1;
		prev = -1;
		ch = -1;
		depth = 0;
		ok = false;
		ff = -1;
	}
};

int n, m, h = 1, id[ 555 ];
string s;
tv tree[ 111 ];
int f[ 1010 ][ 111 ][ 11 ];

void add( int v, int pos )
{
	if ( pos == s.size() )
	{
		tree[v].ok = true;
		return;
	}
	int ch = id[ s[pos] ];
	if ( tree[v].go[ch] == -1 )
	{
		tree[h].prev = v;
		tree[h].depth = tree[v].depth + 1;
		tree[h].ch = ch;
		tree[v].go[ch] = h++;
	}
	add( tree[v].go[ch], pos + 1 );
}

int getlink( int v );
int go( int v, int c );

int getlink( int v )
{
	if ( tree[v].link != -1 ) return tree[v].link;
	if ( v == 0 || tree[v].prev == 0 )
	{
		tree[v].link = 0;
		return 0;
	}
	tree[v].link = go( getlink( tree[v].prev ), tree[v].ch );
	return tree[v].link;
}

int go( int v, int c )
{
	if ( tree[v].go[c] != -1 ) return tree[v].go[c];
	if ( v == 0 )
	{
		tree[v].go[c] = 0;
		return 0;
	}
	tree[v].go[c] = go( getlink( v ), c );
	return tree[v].go[c];
}

int fun( int v )
{
	if ( tree[v].ff != -1 ) return tree[v].ff;
	if ( v == 0 )
	{
		tree[v].ff = 0;
		return 0;
	}
	if ( tree[v].ok == true )
	{
		tree[v].ff = tree[v].depth;
		return tree[v].ff;
	}
	tree[v].ff = fun( getlink( v ) );
	return tree[v].ff;
}

int main()
{
	id['A'] = 0;
	id['C'] = 1;
	id['G'] = 2;
	id['T'] = 3;
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	cin >> n >> m;
	for ( int i = 0; i < m; i++ )
	{
		cin >> s;
		add( 0, 0 );
	}
	//for ( int i = 0; i < h; i++ ) cout << i << " -> " << fun( i ) << endl;
	f[0][0][0] = 1;
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < h; j++ )
			for ( int k = 0; k <= 10; k++ )
			{
				if ( f[i][j][k] == 0 ) continue;
				//cout << i << " " << j << " " << k << " " << f[i][j][k] << endl;
				for ( int ch = 0; ch < 4; ch++ )
				{
					int ii = i + 1;
					int jj = go( j, ch );
					int kk = k + 1;
					if ( fun( jj ) >= kk ) kk = 0;
					if ( kk == 11 ) continue;
					f[ii][jj][kk] = ( f[ii][jj][kk] + f[i][j][k] ) % mod;
				}
			}
	int answer = 0;
	for ( int i = 0; i < h; i++ ) answer += f[n][i][0], answer %= mod;
	cout << answer << endl;
	return 0;
}
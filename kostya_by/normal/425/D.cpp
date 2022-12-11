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
const int mod = 1159424;

using namespace std;

long long htable[ mod ];
int n, x[ 100100 ], y[ 100100 ];
long long answer = 0;
vector< int > xx[ 100100 ], yy[ 100100 ];

void add( int x, int y )
{
	long long value = 100001ll * x + 1ll * y;
	int pos = value % mod;
	while ( true )
	{
		if ( htable[ pos ] == -1 )
		{
			htable[ pos ] = value;
			break;
		} 
		pos = pos + 1;
		if ( pos == mod ) pos = 0;
	}
}

bool check( int x, int y )
{
	long long value = 100001ll * x + 1ll * y;
	int pos = value % mod;
	while ( true )
	{
		if ( htable[ pos ] == -1 ) return false;
		if ( htable[ pos ] == value ) return true;
		pos = pos + 1;
		if ( pos == mod ) pos = 0;
	}
}

void check_x( int x1, int y1, int y2 )
{
	int x2 = x1 + (y2 - y1);
	if ( !check( x2, y1 ) ) return;
	if ( !check( x2, y2 ) ) return;
	answer++; 
}

void check_y( int x1, int y1, int x2 )
{
	int y2 = y1 + (x2 - x1);
	if ( !check( x1, y2 ) ) return;
	if ( !check( x2, y2 ) ) return;
	answer++; 
}

void solve( int x, int y )
{
	int pos_x = (int)( lower_bound( xx[x].begin(), xx[x].end(), y ) - xx[x].begin() );
	int pos_y = (int)( lower_bound( yy[y].begin(), yy[y].end(), x ) - yy[y].begin() );
	if ( xx[x].size() - pos_x < yy[y].size() - pos_y ) 
	{
		for ( int i = pos_x + 1; i < xx[x].size(); i++ ) check_x( x, y, xx[x][i] );
	} else
	{
		for ( int i = pos_y + 1; i < yy[y].size(); i++ ) check_y( x, y, yy[y][i] );
	}
}

int main (int argc, const char * argv[])
{
	time_t start = clock();
	for ( int i = 0; i < mod; i++ ) htable[i] = -1;
	scanf("%d", &n);
	for ( int i = 0; i < n; i++ )
	{
		scanf("%d%d", &x[i], &y[i]);
		xx[ x[i] ].push_back( y[i] );
		yy[ y[i] ].push_back( x[i] );
		add( x[i], y[i] );
	}
	for ( int i = 0; i < 100100; i++ )
	{
		sort( xx[i].begin(), xx[i].end() );
		sort( yy[i].begin(), yy[i].end() );
	}
	for ( int i = 0; i < n; i++ ) solve( x[i], y[i] );
	cout << answer << "\n";
	cerr << fixed << setprecision(6) << "Time: " << 1.0 * ( clock() - start ) / CLOCKS_PER_SEC << "\n";
    return 0;
}
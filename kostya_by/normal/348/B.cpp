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
const long long inf = 1e18;

using namespace std;

int n;
long long s[ 100100 ], sum = 0;
vector< int > graf[ 100100 ];

long long gcd( long long a, long long b )
{
	if ( a != 0 ) return gcd( b % a, a ); else return b;
} 

long long nok( long long a, long long b )
{
	long long g = gcd( a, b );
	if ( 1.0 * a / g * b > 1e12 ) return 1e9;
	return a / g * b;
}

pair< long long, long long > dfs( int v, int p )
{
	vector< long long > sons; 
	long long nn = 1;
	for ( int i = 0; i < graf[v].size(); i++ )
	{
		int next = graf[v][i];
		if ( next == p ) continue;
		pair< long long, long long > pp = dfs( next, v );
		sons.pb( pp.first );
		nn = nok( nn, pp.second );
	}
	if ( sons.size() == 0 ) return mp( s[v], 1 );
	long long alpha = inf;
	for ( int i = 0; i < sons.size(); i++ ) alpha = min( alpha, sons[i] / nn );
	//cout << v << ": " << alpha * nn << " " << nn * sons.size() << endl;
	return mp( alpha * nn * sons.size(), nn * sons.size() );
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ )
    {
    	int ss; scanf("%d", &ss);
    	s[i] = ss;
    	sum += s[i];
    }
    for ( int i = 1; i < n; i++ )
    {
    	int a, b; scanf("%d%d", &a, &b);
    	graf[a].pb(b);
    	graf[b].pb(a);
    }
    pair< long long, long long > p = dfs( 1, -1 );
    cout << sum - p.first << endl;
    return 0;
}
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

struct node
{
    int next[ 26 ];
    node()
    {
        memset( next, -1, sizeof( next ) );
    }    
};

node tree[ 100500 ]; int h = 0;
int n, k, len;
char st[ 100500 ];

void add( int v, int pos )
{
    if ( pos == len ) return;
    int c = st[ pos ] - 'a';
    if ( tree[v].next[c] == -1 ) tree[v].next[c] = ++h;
    add( tree[v].next[c], pos + 1 );  
}

int solve1( int v )
{
    bool is_leaf = true;
    for ( int i = 0; i < 26; i++ ) if ( tree[ v ].next[ i ] != -1 ) is_leaf = false;
    if ( is_leaf ) return 0;
    for ( int i = 0; i < 26; i++ )
    {
        if ( tree[v].next[i] == -1 ) continue;
        if ( solve1( tree[v].next[i] ) == 0 ) return 1;
    }
    return 0;
}

int solve2( int v )
{
    bool is_leaf = true;
    for ( int i = 0; i < 26; i++ ) if ( tree[ v ].next[ i ] != -1 ) is_leaf = false;
    if ( is_leaf ) return 1;
    for ( int i = 0; i < 26; i++ )
    {
        if ( tree[v].next[i] == -1 ) continue;
        if ( solve2( tree[v].next[i] ) == 0 ) return 1;
    }
    return 0;
}

void print( string s )
{
    cout << s << "\n";
    exit( 0 );
}

int main (int argc, const char * argv[])
{
    scanf("%d%d\n", &n, &k);
    for ( int i = 0; i < n; i++ )
    {
        gets( st ); len = strlen( st );
        add( 0, 0 );
    }
    int a = solve1( 0 );// cout << a << "\n";
    int b = solve2( 0 );// cout << b << "\n";
    if ( a == 1 && b == 1 ) print( "First" );
    if ( a == 1 && b == 0 ) print( ( k % 2 == 1 ? "First" : "Second" ) );
    if ( a == 0 && b == 1 ) print( "Second" );
    if ( a == 0 && b == 0 ) print( "Second" );
    return 0;
}
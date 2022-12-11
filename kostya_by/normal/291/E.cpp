#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

#define pb push_back
#define mp make_pair
typedef unsigned long long ull;

const long long inf = 1e18;
const long double eps = 1e-9;

struct tv
{
    int prev, next[ 26 ], link;
    int c;
    int pls;
    tv()
    {
        for ( int i = 0; i < 26; i++ ) next[i] = -1;
        link = -1;
        pls = 0;
    }
};

tv tree[ 500300 ];
int n, p[ 500100 ], ht = 1, answer = 0;
vector< int > g[ 500100 ];
string s[ 500100 ], t;

void add( int v, int pos )
{
    if ( pos == t.size() )
    {
        tree[v].pls = 1;
        return;
    }
    int c = t[ pos ] - 'a';
    if ( tree[v].next[c] == -1 )
    {
        tree[v].next[c] = ht;
        tree[ht].prev = v;
        tree[ht].c = c;
        ht++;
    }
    add( tree[v].next[c], pos + 1 );
}

int getlink( int v );

int go( int v, int c )
{
    if ( tree[v].next[c] != -1 ) return tree[v].next[c];
    if ( v == 0 )
    {
        tree[v].next[c] = 0;
        return 0;
    }
    tree[v].next[c] = go( getlink( v ), c );
    return tree[v].next[c];
}

int getlink( int v )
{
    if ( tree[v].link != -1 ) return tree[v].link;
    if ( v == 0 || tree[v].prev == 0 )
    {
        tree[v].link = 0;
        return 0;
    }
    tree[v].link = go( getlink( tree[v].prev ), tree[v].c );
    return tree[v].link;
}

void dfs( int v, int prev, int pos )
{
    for ( int i = 0; i < g[v].size(); i++ )
    {
        int id = g[v][i];
        int next = v ^ id ^ p[id];
        if ( prev == next ) continue;
        int pp = pos;
        for ( int j = 0; j < s[id].size(); j++ )
        {
            pp = go( pp, s[id][j] - 'a' );
            if ( tree[pp].pls )
            {
                answer++;
            }
        }
        dfs( next, v, pp );
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for ( int i = 2; i <= n; i++ )
    {
        scanf("%d", &p[i]);
        cin >> s[i];
        g[ i ].pb( i );
        g[ p[i] ].pb( i );
    }
    cin >> t;
    add( 0, 0 );
    dfs( 1, -1, 0 );
    cout << answer << endl;
    return 0;
}
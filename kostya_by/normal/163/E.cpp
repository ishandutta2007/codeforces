#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

#define pb push_back
#define mp make_pair
typedef unsigned long long ull;
typedef unsigned int ui;

struct tv
{
       int go[26], ch, prev, link;
       tv()
       {
           for ( int i = 0; i < 26; i++ ) go[i] = -1;
           ch = 0;
           prev = 0;
           link = -1; 
       }
};

tv tree[ 1000010 ];
char st[ 1000010 ];
int n, k, l, h = 0, ii, where[ 100001 ], tin[ 1000010 ], tout[ 1000010 ], timer = 0, pls[ 8000004 ], nn[ 1000001 ], hh, d, res;
bool state[ 100001 ], name[ 1000001 ];
vector< int > graf[ 1000001 ];

void add(int v, int pos)
{
     if ( pos == l )
     {
          name[ v ] = true;
          where[ ii ] = v;
          return;
     }
     int ch = st[ pos ] - 'a';
     if ( tree[v].go[ch] == -1 )
     {
          ++h;
          tree[v].go[ch] = h;
          tree[h].prev = v;
          tree[h].ch = ch;
     }
     add( tree[v].go[ch], pos + 1 );
}

int go( int v, int c );
int getlink( int v );

int go( int v, int c )
{
    //cout << v << " " << c << " -> " << tree[v].go[c] << endl;
    if ( tree[v].go[c] != -1 ) return tree[v].go[c];
    if ( v == 0 )
    {
         tree[v].go[c] = 0;
         return 0;
    }
    tree[v].go[c] = go( getlink( v ), c );
    return tree[v].go[c];
}

int getlink( int v )
{
    if ( tree[v].link != -1 ) return tree[v].link;
    if ( v == 0 || tree[v].prev == 0)
    {
         tree[v].link = 0;
         return 0;
    }
    tree[v].link = go( getlink( tree[v].prev ), tree[v].ch );
    //cout << v << " -> " << tree[v].link << endl;
    return tree[v].link;
}

void dfs( int v )
{
     tin[v] = timer++;
     if ( name[v] == true ) ++hh;
     nn[v] = hh;
     for ( int i = 0; i < graf[v].size(); i++ ) dfs( graf[v][i] );
     if ( name[v] == true ) --hh;
     tout[v] = timer++;
}

int getnum()
{
    int res = 0;
    for ( int i = 1; i < l; i++ ) res *= 10, res += st[i] - '0';
    return res;
}

void modify( int id, int l, int r, int ll, int rr )
{
     if ( l == ll && rr == r )
     {
        pls[id] += d;
        return;
     }
     int xx = (ll + rr) / 2;
     if ( l <= xx ) modify( id + id, l, min(r, xx), ll, xx );
     if ( xx + 1 <= r ) modify( id + id + 1, max(l, xx + 1), r, xx + 1, rr );
}

void fsum( int ll, int rr )
{
    int id = 1;
    while ( true )
    {
          res += pls[ id ]; 
          if ( ll == rr ) break;
          int xx = (ll + rr) / 2;
          id *= 2;
          if ( d <= xx ) rr = xx; else ++id, ll = xx + 1;   
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d\n", &n, &k);
    for ( int i = 0; i < k; i++ )
    {
        state[ i ] = true;
        gets( st );
        l = strlen( st );
        ii = i;
        add( 0, 0 );
    }
    for ( int i = 1; i <= h; i++ )
    {
        int a = getlink( i ), b = i;
        graf[ a ].pb( b );
    }
    
    hh = 0;
    dfs( 0 );
    
    for ( int q = 0; q < n; q++ )
    {
        gets( st );
        l = strlen( st );
        if ( st[0] == '+' )
        {
             int num = getnum();
             --num;
             d = 1;
             int id = where[ num ];
             if ( state[num] == false ) modify( 1, tin[id], tout[id], 0, timer - 1 );
             state[num] = true;
        }
        if ( st[0] == '-' )
        {
             int num = getnum();
             --num;
             d = -1;
             int id = where[ num ];
             if ( state[num] == true ) modify( 1, tin[id], tout[id], 0, timer - 1 );
             state[num] = false;
        }
        if ( st[0] == '?' )
        {
             int cur = 0;
             long long ans = 0;
             for ( int i = 1; i < l; i++ )
             {
                 cur = go( cur, st[i] - 'a' );
                 res = 0;
                 d = tin[ cur ];
                 fsum( 0, timer - 1 );
                 //cout << i << " " << cur << " " << nn[cur] + res << endl;
                 ans += nn[ cur ] + res;
             }
             printf("%I64d\n", ans);
        }
        //cout << "-----------------------------" << endl;
    }
    
    return 0;
}
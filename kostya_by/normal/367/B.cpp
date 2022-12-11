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

int n, m, p, a[ 200200 ], b[ 200200 ], h = 0, num = 0, dn = 0;
int cnt[ 400400 ], f[ 400400 ];
map< int, int > cmp;
vector< int > q, now, id;

void add( int x )
{
    if ( f[x] == cnt[x] ) num--;
    f[x]++;
    if ( f[x] == cnt[x] ) num++;
}

void del( int x )
{
    if ( f[x] == cnt[x] ) num--;
    f[x]--;
    if ( f[x] == cnt[x] ) num++; 
}

int main (int argc, const char * argv[])
{
    scanf("%d%d%d", &n, &m, &p);
    for ( int i = 1; i <= n; i++ )
    {
        scanf("%d", &a[i]);
        if ( cmp[ a[i] ] == 0 ) cmp[ a[i] ] = ++h;
        a[i] = cmp[ a[i] ];
    }
    for ( int i = 1; i <= m; i++ )
    {
        scanf("%d", &b[i]);
        if ( cmp[ b[i] ] == 0 ) cmp[ b[i] ] = ++h;
        b[i] = cmp[ b[i] ];
        cnt[ b[i] ]++;
    }
    for ( int i = 0; i < 400400; i++ ) dn += ( cnt[i] > 0 );
    for ( int i = 1; i <= p; i++ )
    {
        now.clear(); id.clear();
        for ( int j = i; j <= n; j += p )
        {
            now.push_back( a[j] );
            id.push_back( j );
        }
        if ( now.size() < m ) continue;
        for ( int j = 0; j < m; j++ ) add( now[j] );
        int l = 0, r = m - 1;
        if ( num == dn ) q.push_back( id[0] );
        while ( true )
        {
            if ( r + 1 == now.size() ) break;
            r++; add( now[r] );
            del( now[l] ); l++;
            if ( num == dn ) q.push_back( id[l] );
        }
        for ( int j = 0; j < now.size(); j++ ) f[ now[j] ] = 0; num = 0;
    }
    sort( q.begin(), q.end() );
    cout << q.size() << "\n";
    for ( int i = 0; i < q.size(); i++ ) printf("%d ", q[i]);
    return 0;
}
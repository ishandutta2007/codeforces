#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <ext\hash_set>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>


using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 550;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

vector < int > edge[maxn];
int type[maxn] = { 0 };
bool a[maxn][maxn];

void init() {
    for ( int j = 0; j < maxn; j++ )
        for ( int i = 0; i < maxn; i++ )
            a[j][i] = false;
}

bool need( int j, int i ) {
    if ( type[j] == 'a' && type[i] == 'c' ) return 0;
    swap( j, i );
    if ( type[j] == 'a' && type[i] == 'c' ) return 0;
    return 1;
}

bool valid( int n ) {
    init();
    for ( int j = 0; j < n; j++ ) {
        int sz = edge[j].size();
        for ( int i = 0; i < sz; i++ )
            a[j][edge[j][i]] = true;
    }
    for ( int j = 0; j < n; j++ )
        for ( int i = j + 1; i < n; i++ ) {
            if ( need( j, i ) && !a[j][i] )
                return 0;
            if ( !need( j, i ) && a[j][i] )
                return 0;
        }
    return 1;
}

void put( int n ) {
    if ( !valid( n ) ) {
        printf ( "No" );
        exit( 0 );
    }
    printf ( "Yes\n" );
    for ( int j = 0; j < n; j++ )
        printf ( "%c", type[j] );
    exit( 0 );
}

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, m, j, x, y;
    scanf ( "%d%d", &n, &m );
    for ( j = 0; j < m; j++ ) {
        scanf ( "%d%d", &x, &y );
        x--;
        y--;
        edge[x].pb( y );
        edge[y].pb( x );
    }
    for ( j = 0; j < n; j++ )
        if ( edge[j].size() == n - 1 ) type[j] = 'b';
    int cnt = 0;
    while ( cnt < n && type[cnt] )
        cnt++;
    if ( cnt == n )
        put( n );
    type[cnt] = 'a';
    int sz = edge[cnt].size();
    for ( j = 0; j < sz; j++ )
        if ( !type[edge[cnt][j]] )
            type[edge[cnt][j]] = 'a';
    while ( cnt < n && type[cnt] )
        cnt++;
    if ( cnt == n )
        put( n );
    type[cnt] = 'c';
    sz = edge[cnt].size();
    for ( j = 0; j < sz; j++ ) {
        if ( type[edge[cnt][j]] == 'a' ) {
            printf ( "No" );
            return 0;
        }
        if ( !type[edge[cnt][j]] )
            type[edge[cnt][j]] = 'c';
    }
    bool correct = true;
    for ( j = 0; j < n; j++ )
        if ( !type[j] )
            correct = false;
    if ( !correct ) {
        printf ( "No" );
        return 0;
    }
    put( n );
    return 0;
}
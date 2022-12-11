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
const long long mod = 1000000007;

using namespace std;

int prev[ 333333 ];
long long fi[ 333333 ], se[ 333333 ], th[ 333333 ];
long long current = 0;
//------------------------------------
int n, p[ 20 ][ 333333 ], c[ 333333 ];
string s1, s2, s3, S;
vector< ull > cur; 
vector< pair< int, int > > add_edge[ 333333 ]; 
long long answer[ 333333 ]; 

ull compose( int a, int b, int c )
{
    ull result = a;
    result *= 524288;
    result += b;
    result *= 524288;
    result += c;
    return result;
}

void suffix_array()
{
    n = S.size();
    for ( int i = 0; i < n; i++ ) cur.push_back( compose( S[i], S[i], i ) );
    sort( cur.begin(), cur.end() );
    long long _last = -1;
    int id = -1;
    for ( int i = 0; i < n; i++ )
    {
        long long first = cur[ i ] / 524288;
        int second = cur[ i ] % 524288;
        if ( _last < first )
        {
            _last = first;
            id += 1;
        }
        c[i] = second;
        p[ 0 ][ c[i] ] = id;
    }
    for ( int it = 1; it < 20; it++ )
    {
        cur.clear();
        for ( int i = 0; i < n; i++ )
        {
            int j = ( i + ( 1 << ( it - 1 ) ) ) % n;
            cur.push_back( compose( p[it - 1][i], p[it - 1][j], i ) ); 
        }
        sort( cur.begin(), cur.end() );
        long long _last = -1;
        int id = -1;
        for ( int i = 0; i < n; i++ )
        {
            long long first = cur[ i ] / 524288;
            int second = cur[ i ] % 524288;
            if ( _last < first )
            {
                _last = first;
                id += 1;
            }
            c[i] = second;
            p[ it ][ c[i] ] = id;
        }
    }
    for ( int i = 1; i < n; i++ )
    {
        int weight = 0;
        int ii = c[i - 1];
        int jj = c[i];
        for ( int j = 19; j >= 0; j-- )
            if ( p[j][ii] == p[j][jj] )
            {
                weight += ( 1 << j );
                ( ii += ( 1 << j ) ) %= n;
                ( jj += ( 1 << j ) ) %= n;
            }
        add_edge[ weight ].push_back( make_pair( i - 1, i ) );
    }
}

int get_prev( int v )
{
    if ( v == prev[v] ) return v;
    prev[v] = get_prev( prev[v] );
    return prev[v];
}

void add( int a, int b )
{
    a = get_prev( a );
    b = get_prev( b );
    if ( a == b ) return;
    current -= fi[ a ] * se[ a ] * th[ a ];
    current -= fi[ b ] * se[ b ] * th[ b ];
    prev[ a ] = b;
    fi[ b ] += fi[ a ];
    se[ b ] += se[ a ];
    th[ b ] += th[ a ];
    current += fi[ b ] * se[ b ] * th[ b ];
}

int main (int argc, const char * argv[])
{
   /* time_t start = clock();
    srand( 2318 );
    for ( int i = 0; i < 100000; i++ )
    {
        char c1 = 'a';
        //if ( rand() % 1000 == 0 ) c1 += 1;
        s1 += c1;

        char c2 = 'a';
        //if ( rand() % 1000 == 0 ) c2 += 1;
        s2 += c2;

        char c3 = 'a';
        //if ( rand() % 1000 == 0 ) c3 += 1;
        s3 += c3;
    }*/
    cin >> s1 >> s2 >> s3;
    S = s1 + ' ' + s2 + '\0' + s3 + '#';
    suffix_array();
    //----------------------------------
    for ( int i = 0; i < n; i++ )
    {
        prev[i] = i;
        if ( c[i] < s1.size() ) fi[i] = 1;
        if ( s1.size() < c[i] && c[i] < s1.size() + s2.size() + 1 ) se[i] = 1;
        if ( s1.size() + s2.size() + 1 < c[i] && c[i] < s1.size() + s2.size() + s3.size() + 2 ) th[i] = 1;
    }
    for ( int i = n; i > 0; i-- )
    {
        for ( int j = 0; j < add_edge[i].size(); j++ )
            add( add_edge[i][j].first, add_edge[i][j].second );
        answer[i] = current;
    }
    for ( int i = 1; i <= min( s1.size(), min( s2.size(), s3.size() ) ); i++ ) printf("%d ", (int)( answer[i] % mod ) );
    //cout << fixed << setprecision( 6 ) << "Time: " << 1.0 * ( clock() - start ) / CLOCKS_PER_SEC << "\n";
    return 0;
}
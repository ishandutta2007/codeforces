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
const int c = 1;

using namespace std;

int n, m;
double answer = -1.0;
int p1, p2, p3, p4;
double dist[ 150 ][ 150 ];
vector< pair< int, int > > p;
bool marked[ 1010 ][ 1010 ];

void print( int x )
{
    cout << p[x].first << " " << p[x].second << "\n";
} 

int main (int argc, const char * argv[])
{
    cin >> n >> m;
    for ( int i = 0; i <= min( n, c ); i++ )
        for ( int j = 0; j <= min( m, c ); j++ )
                marked[i][j] = true;
    //--------------------------------------
    for ( int i = max( 0, n - c ); i <= n; i++ )
        for ( int j = max( 0, m - c ); j <= m; j++ )
                marked[i][j] = true;
    //--------------------------------------
    for ( int i = 0; i <= min( n, c ); i++ )
        for ( int j = max( 0, m - c ); j <= m; j++ )
                marked[i][j] = true;
    //--------------------------------------
    for ( int i = max( 0, n - c ); i <= n; i++ )
        for ( int j = 0; j <= min( m, c ); j++ )
                marked[i][j] = true;
    //--------------------------------------
    for ( int i = 0; i <= n; i++ )
        for ( int j = 0; j <= m; j++ )
            if ( marked[i][j] )
                p.push_back( make_pair( i, j ) );
    //--------------------------------------
    for ( int i = 0; i < p.size(); i++ )
        for ( int j = 0; j < p.size(); j++ )
        {
            int dx = p[i].first - p[j].first;
            int dy = p[i].second - p[j].second;
            dist[i][j] = sqrt( dx * dx + dy * dy );
        }
    //--------------------------------------
    for ( int i = 0; i < p.size(); i++ )
        for ( int j = 0; j < p.size(); j++ )
        {
            if ( i == j ) continue;
            for ( int k = 0; k < p.size(); k++ )
            {
                if ( i == k || j == k ) continue;
                for ( int l = 0; l < p.size(); l++ )
                {
                    if ( i == l || j == l || k == l ) continue;
                    double current = dist[i][j] + dist[j][k] + dist[k][l];
                    if ( current > answer )
                    {
                        answer = current;
                        p1 = i; p2 = j; p3 = k; p4 = l;
                    }
                }
            }
        }
    print( p1 );
    print( p2 );
    print( p3 );
    print( p4 );
    return 0;
}
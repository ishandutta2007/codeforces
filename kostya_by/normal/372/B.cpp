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
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, m, q, a[ 44 ][ 44 ], lvl[ 44 ];
int f[ 44 ][ 44 ][ 44 ][ 44 ];
char st[ 44 ][ 44 ];

int main (int argc, const char * argv[])
{
    scanf("%d%d%d\n", &n, &m, &q);
    for ( int i = 0; i < n; i++ ) gets( st[i] );
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
        {
            a[i][j] = ( st[i - 1][j - 1] == '0' );
        }
    for ( int i1 = 1; i1 <= n; i1++ )
        for ( int j1 = 1; j1 <= m; j1++ )
            for ( int j2 = j1; j2 <= m; j2++ )
            {
                f[i1][j1][i1 - 1][j2] = 0;
                for ( int j = j1; j <= j2; j++ ) lvl[j] = 0;
                for ( int i2 = i1; i2 <= n; i2++ )
                {
                    f[i1][j1][i2][j2] = f[i1][j1][i2 - 1][j2];
                    vector< pair< int, int > > st; int sum = 0;
                    for ( int j = j1; j <= j2; j++ ) 
                    {
                        if ( a[i2][j] == 1 ) lvl[j]++; else lvl[j] = 0;
                        int killed = 1;
                        while ( true )
                        {
                            if ( st.size() == 0 ) break;
                            if ( st.back().first <= lvl[j] ) break;
                            killed += st.back().second;
                            sum -= st.back().first * st.back().second;
                            st.pop_back();
                        }
                        st.push_back( make_pair( lvl[j], killed ) );
                        sum += st.back().first * st.back().second;
                        f[i1][j1][i2][j2] += sum;
                    }
                } 
            }
    for ( int i = 0; i < q; i++ )
    {
        int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
        printf("%d\n", f[a][b][c][d]);
    }
    return 0;
}
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

int n, p[ 3333 ], inv = 0;
double f[ 4499500 ];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for ( int i = 1; i <= n; i++ ) cin >> p[i];
    for ( int i = 1; i <= n; i++ )
        for ( int j = i + 1; j <= n; j++ )
            if ( p[i] > p[j] )
                inv++;
    int ii = 50;
    double pp = 0, p1 = 0.5, p2 = 0.25;
    while ( ii > 0 )
    {
        pp += p1;
        p1 *= p2;
        p2 *= 0.5;
        ii--;
    }
    f[0] = 0.0;
    f[1] = 1.0;
    for ( int i = 2; i <= inv; i++ )
    {
        f[i] = f[i - 2] + 4;
    }  
    //for ( int i = 0; i <= inv; i++ ) cout << fixed << setprecision( 8 ) << f[i] << endl;
    //cout << "--------------" << endl;
    cout << fixed << setprecision( 8 ) << f[inv] << endl;
    return 0;
}
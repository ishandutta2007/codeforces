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

int k, n = 2;
bool graf[ 1010 ][ 1010 ];

void add( int a, int b )
{
    graf[ a ][ b ] = graf[ b ][ a ] = true;
}

void build()
{
    int start = 1;
    for ( int pt = 29; pt > 0; pt-- )
    {
        add( start, n + 1 );
        add( start, n + 2 );
        start = n + 1;
        n += 2;
        for ( int i = 1; i < pt; i++ )
        {
            add( n - 1, n + 1 );
            add( n - 1, n + 2 );
            add( n, n + 1 );
            add( n, n + 2 );  
            n += 2;
        }  
        if ( k & ( 1 << pt ) )
        {
            add( n - 1, 2 );
            add( n, 2 );
        }
    }
    if ( k & 1 ) 
    {
        start = 1;
        for ( int i = 1; i <= 29; i++ )
        {
            add( start, n + 1 );
            start = n + 1;
            n++;
        }
        add( start, 2 );
    }
}

int main (int argc, const char * argv[])
{
    scanf("%d", &k);
    build();
    printf("%d\n", n);
    for ( int i = 1; i <= n; i++ )
    {
        for ( int j = 1; j <= n; j++ ) if ( graf[i][j] ) putchar('Y'); else putchar('N');
        putchar('\n');
    }
    return 0;
}
#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
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

const int maxn = 100500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

vector < int > ans;

void gen( int n, int sum ) {
    while ( n ) {
        int x = sum / n;
        ans.pb( x );
        --n;
        sum -= x; 
    }
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, k, l, r, all, part;
    scanf ( "%d%d%d%d%d%d", &n, &k, &l, &r, &all, &part );
    gen( k, part );
    gen( n - k, all - part );
    for ( int j = 0; j < n; j++ )
        printf( "%d ", ans[j] );
    return 0;
}
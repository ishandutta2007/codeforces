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

const int maxn = 1050;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn][maxn];
int sumR[maxn][maxn];
int sumD[maxn][maxn];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, m;
    scanf ( "%d%d", &n, &m );
    for ( int j = 1; j <= n; j++ )
    	for ( int i = 1; i <= m; i++ )
    		scanf ( "%d", &a[j][i] );
   	for ( int j = 1; j <= n; j++ ) 
   		for ( int i = 1; i <= m; i++ ) {
   			sumR[j][i] = sumR[j][i - 1] + a[j][i];
   			sumD[j][i] = sumD[j - 1][i] + a[j][i];
   		}
   	int ans = 0;
   	for ( int j = 1; j <= n; j++ )
   		for ( int i = 1; i <= m; i++ ) {
   			if ( a[j][i] )
   				continue;
   			if ( sumR[j][i - 1] )
   				++ans;
   			if ( sumD[j - 1][i] )
   				++ans;
   			if ( sumR[j][m] - sumR[j][i] )
   				++ans;
   			if ( sumD[n][i] - sumD[j][i] )
   				++ans;
   		}
   	printf ( "%d\n", ans );
    return 0;
}
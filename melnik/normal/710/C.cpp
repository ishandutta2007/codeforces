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

list < int > odd;
int a[maxn][maxn];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    for ( int j = 1; j <= n * n; j += 2 )
    	odd.pb( j );
    int cur = 0;
    int add = 1;
    for ( int j = 0; j < n; j++ ) {
    	for ( int i = n / 2 - cur; i <= n / 2 + cur; i++ ) {
    		a[j][i] = odd.front();
    		odd.pop_front();
    	}
    	if ( n / 2 - cur == 0 )
    		add = -1;
    	cur += add;
    }
   	for ( int j = 2; j <= n * n; j += 2 )
   		odd.pb( j );
   	for ( int j = 0; j < n; j++ ) {
   		for ( int i = 0; i < n; i++ )
   			if ( !a[j][i] ) {
   				printf ( "%d ", odd.front() );
   				odd.pop_front();
   			}
   			else
   				printf ( "%d ", a[j][i] );
   		printf ( "\n" );
   	}
    return 0;
}
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

const int maxn = 200500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];
int b[maxn];
int sufSum[maxn];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, pos;
    scanf ( "%d%d", &n, &pos );
    for ( int j = 1; j <= n; j++ )
    	scanf ( "%d", &a[j] );
    int ansToAdd = 0;
    if ( a[pos] )
    	++ansToAdd;
   	if ( n == 1 ) {
   		printf ( "%d\n", ansToAdd );
   		return 0;
   	}
   	a[pos] = 0;
   	for ( int j = 1; j <= n; j++ )
   		++b[a[j]];
   	for ( int j = maxn - 2; j >= 0; j-- )
   		sufSum[j] = sufSum[j + 1] + b[j];
   	int curOdd = b[0] - 1;
   	int haveNulls = 0;
   	int canBeReplaced = 0;
   	int ans = inf;
   	for ( int j = 1; j < maxn; j++ ) {
   		if ( !b[j] )
   			++haveNulls;
   		if ( b[j] )
   			canBeReplaced += b[j] - 1;
   		int newOdd = curOdd + sufSum[j + 1];
   		int newAns = newOdd;
   		if ( haveNulls <= newOdd ) {
   			ans = min( ans, newAns );
   			continue;
   		}
   		if ( haveNulls <= newOdd + canBeReplaced )
   			ans = min( ans, haveNulls );
   	}
   	printf ( "%d\n", ans + ansToAdd );
    return 0;
}
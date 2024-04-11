#include <iostream>
#include <fstream>
#include <stdio.h>
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
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <time.h>
#include <ctime>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 1e5+5;


ll i[maxn], dp[maxn];

#define f first
#define s second
#define pb push_back
#define mp make_pair

int main()
{
    ll ma = -2e9;
    int n, k, x;
    scanf ( "%lld", &n );
    for ( k = 0; k < maxn; k++ )
        i[k] = 0;
    for ( k = 0; k < n; k++ ){
        scanf ( "%lld", &x );
        i[x]++;
        ma = max ( ma, (ll) x );
    }
    dp[0] = 0;
    dp[1] = i[1];
    for ( k = 2; k < maxn; k++ )
        dp[k] = max ( k * i[k] + dp[k - 2], dp[k - 1] );
    printf ( "%lld", max ( dp[ma], dp[ma - 1] ) ) ;
    return 0;
}
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
#include <iterator>
#include <cstdio>


using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 1e5;
const int inf = 2e9;
const double eps = 1e-8;

int main()
{
    srand( time( 0 ) );
    ll a, b, k, ans = 0LL;
//    scanf ( "%I64d%I64dI64d", &k, &a, &b );
    cin >> k >> a >> b;
    if ( a <= 0 && b >= 0 ) {
        ans = abs( a ) / k + b / k + 1LL;
        printf ( "%I64d", ans );
        return 0;
    }
//    printf ( "--%I64d %I64d %I64d", k, a, b );
    a = abs( a );
    b = abs( b );
    if ( b < a ) swap ( a, b );
    if ( a == 0 ) ans += 1LL;
    ans += 1LL * ( b / k ) - (  ( a - 1 ) / k );
    printf ( "%I64d", ans );
    return 0;
}
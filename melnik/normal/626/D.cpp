#include <iostream>
#include <fstream>
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

const int maxn = 10050;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];

ull bal1[maxn] = { 0ULL };
ull bal2[maxn] = { 0ULL };

ull sufSum[maxn] = { 0ULL };

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, j;
    scanf ( "%d", &n );
    for ( j = 0; j < n; j++ )
        scanf ( "%d", &a[j] );
    sort( a, a + n );
    int i;
    for ( j = 1; j < n; j++ )
        for ( i = 0; i < j; i++ )
            bal1[a[j] - a[i]]++;
    for ( j = maxn - 1; j >= 0; j-- )
        sufSum[j] = bal1[j] + sufSum[j + 1];
    for ( j = 0; j <= 5000; j++ )
        for ( i = 0; i <= 5000; i++ )
            bal2[j + i] += bal1[j] * bal1[i];
    ull cnt = 0ULL;
    for ( j = 0; j <= 5000; j++ )
        cnt += bal2[j] * sufSum[j + 1];
//    cout << cnt << endl;
    ull all = sufSum[0] * sufSum[0] * sufSum[0];
//    cout << all;
    cout << fixed << setprecision( 20 ) << (ld)cnt / all;
    return 0;
}
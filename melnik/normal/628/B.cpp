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

const int maxn = 300500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

char t[maxn];
int a[maxn];

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    gets( t );
    int n = strlen( t ), j;
    for ( j = 0; j < n; j++ )
        a[j] = t[j] - '0';
    ll ans = 0LL;
    for ( j = 0; j < n; j++ )
        if ( a[j] % 4 == 0 )
            ans += 1LL;
//    cout << ans;
    for ( j = 1; j < n; j++ )
        if ( ( a[j - 1] * 10 + a[j] ) % 4 == 0 )
            ans += 1LL * j;
    cout << ans;
    return 0;
}
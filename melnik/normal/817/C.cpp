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

bool correct( ll c, ll x ) {
	int sum = 0;
	ll old = c;
	while ( c ) {
		sum += c % 10LL;
		c /= 10LL;
	}
	return old - sum >= x;
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    ll n, x;
    cin >> n >> x;
    ll ans = 0;
    for ( ll j = x; j <= n && j <= x + 200; j += 1LL )
    	ans += correct( j, x );
    ans += max( 0LL, n - x - 200LL );
    cout << ans << endl;
    return 0;
}
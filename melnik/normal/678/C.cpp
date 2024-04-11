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

ll nok( int a, int b ) {
	return 1LL * a * b / __gcd( a, b );
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, a, b, p, q;
    scanf ( "%d%d%d%d%d", &n, &a, &b, &p, &q );
    ll ans = 1LL * ( n / a ) * p + 1LL * ( n / b ) * q;
    ans -= 1LL * ( 1LL * n / nok( a, b ) ) * ( p + q );
    ans += 1LL * ( 1LL * n / nok( a, b ) ) * max( p, q );
    cout << ans;
    return 0;
}
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

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int a, b;
    scanf ( "%d%d", &a, &b );
    ll ans = 0LL;
    for ( int y = 0; y <= b; y++ ) {
    	int x = ( b - y ) * a;
    	ll newAns = 1LL * ( y + 1 ) * x * ( x + 1 ) / 2LL;
    	newAns += 1LL * ( x + 1 ) * y * ( y + 1 ) / 2LL;
    	ans = max( ans, newAns ); 
    }
    cout << ans << endl;
    return 0;
}
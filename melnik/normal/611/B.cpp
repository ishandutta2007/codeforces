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

const int maxn = 1e5;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

ll next_( ll z ) {
    int t[100];
    int num = 0;
    int pos;
    while ( z != 0 ) {
        t[num] = z % 2;
        z /= 2;
        if ( t[num] == 0 ) pos = num;
        num++;
    }
    if ( pos ) {
        t[pos] = 1;
        t[pos - 1] = 0;
        ll st = 1;
        ll pr = 0;
        for ( int j = 0; j < num; j++ ) {
            pr += 1LL * st * t[j];
            st *= 2LL;
        }
        return pr;
    }
    for ( int j = 0; j <= num; j++ )
        t[j] = 1;
    t[num - 1] = 0;
    ll st = 1;
    ll pr = 0;
    for ( int j = 0; j <= num; j++ ) {
            pr += 1LL * st * t[j];
            st *= 2LL;
        }
    return pr;
}


int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
    ll a, b;
    cin >> a >> b;
    ll z = 2;
    int ans = 0;
    while ( z < a ) {
        z = next_( z );
    }
    while ( z <= b ) {
        ans++;
        z = next_( z );
    }
    cout << ans;
    return 0;
}
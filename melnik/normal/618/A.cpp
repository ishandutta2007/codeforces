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

bool u[maxn] = {0};
vector < int > ans;

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, st = 2, j = 0;
    scanf ( "%d", &n );
    while ( n > 0 ) {
        u[j] = n % 2;
        j++;
        n /= 2;
    }
    st = 1;
    for ( j = 0; j < 50; j++ ) {
        if ( u[j] ) ans.pb( st );
        st++;
    }
    reverse( ans.begin(), ans.end() );
    for ( j = 0; j < ans.size(); j++ )
        cout << ans[j] << ' ';
    return 0;
}
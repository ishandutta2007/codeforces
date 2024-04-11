#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <iomanip>

#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <tuple>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <unordered_map>
#include <array>

#include <complex>
#include <time.h>
#include <math.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

bool solve() {

    int n;

    cin >> n;

    vec< int > a(n + 1);

    for(int i = 1;i <= n;i++) cin >> a[i];

    vec< vec< int > > dp(n + 1, vec< int >(3, inf));

    dp[1][0] = 1;
    if(1 & a[1]) dp[1][1] = 0;
    if(2 & a[1]) dp[1][2] = 0;

    for(int i = 2;i <= n;i++) {
        dp[i][0] = 1 + min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
        if(1 & a[i]) dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        if(2 & a[i]) dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
    }

    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]) << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}
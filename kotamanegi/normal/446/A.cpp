#pragma comment (linker, "/STACK:256000000")
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 1e-5
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144*2
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long a = 0;a < b;++a)
#define ALL(x) (x).begin(),(x).end()
void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(20);
}
unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
#define int ll
long long dp[2][200000];
void solve() {
    int n;
    cin >> n;
    vector<int> inputs;
    REP(i, n) {
        int a;
        cin >> a;
        inputs.push_back(a);
    }
    dp[0][0] = 1;
    for (int i = 1; i < n; ++i) {
        if (inputs[i] > inputs[i - 1]) {
            dp[0][i] = max(dp[0][i], dp[0][i - 1] + 1);
            dp[1][i] = max(dp[1][i], dp[1][i - 1] + 1);
        }
        if (i == 1) {
            dp[1][i] = 2;
        }
        else if (inputs[i - 2]+2 <= inputs[i]) {
            dp[1][i] = max(dp[1][i], dp[0][i - 2] + 2);
        }
        dp[1][i] = max(dp[1][i], 2LL);
        dp[0][i] = max(dp[0][i], 1LL);
    }
    ll ans = 0;
    REP(i, 2) {
        REP(q, n + 1) {
            ans = max(ans, dp[i][q] + (1 - i));
        }
    }
    cout << min(n,ans) << endl;
}
#undef int
int main() {
    init();
    solve();
}
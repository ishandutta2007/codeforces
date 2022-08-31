#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <functional>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

#ifndef LOCAL
#define cerr _cer
struct _cert
{
    template <typename T> _cert& operator << (T) { return *this; }
};
_cert _cer;
#endif

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}
const int INF = 1e5;
vector<ll> vv;
ll dp[120000];

int solve(int a, int b, int h, int w) {
    a = (a + h - 1) / h;
    b = (b + w - 1) / w;
    fill(dp, dp + a + 1, 0);
    dp[1] = 1;
    if (a == 1 && b == 1)
        return 0;
    for (int i = 0; i < vv.size(); ++i) {
        for (int j = a; j >= 1; --j) {
            dp[min((ll)j * vv[i], (ll)a)] = min((ll)b, max(dp[min((ll)j * vv[i], (ll)a)], dp[j]));
            dp[j] = min((ll)b, dp[j] * vv[i]);
        }
        if (dp[a] >= b)
            return i + 1;
    }
    return INF;
}

int main() {
    ll a, b, w, h;
    int n;
    scanf("%lld%lld%lld%lld%d", &a, &b, &h, &w, &n);
    for (int i = 0; i < n; ++i) {
        ll x;
        scanf("%lld", &x);
        vv.push_back(x);
    }
    sort(vv.rbegin(), vv.rend());
    n = min(n, 40);
    vv.resize(n);
    int ans = min(solve(a, b, h, w), solve(a, b, w, h));
    if (ans == INF)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
    return 0;
}
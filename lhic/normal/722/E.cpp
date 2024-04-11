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
const ll MOD = 1e9 + 7;
const int LOG = 21;

ll pw(ll a, ll b) {
    ll ans = 1;
    while (b) {
        while (!(b & 1))
            b >>= 1, a = (a * a) % MOD;
        ans = (ans * a) % MOD;
        --b;
    }
    return ans;
}
const int MX = 210000;

ll fc[MX];
ll bfc[MX];

void init() {
    fc[0] = 1;
    for (int i = 1; i < MX; ++i)
        fc[i] = (fc[i - 1] * i) % MOD;
    for (int i = 0; i < MX; ++i)
        bfc[i] = pw(fc[i], MOD - 2);
}

ll get(int a, int b) {
    return fc[a + b] * bfc[a] % MOD * bfc[b] % MOD;
}

int n, m, k, s;
vector<pair<pair<int, int>, int> > vv;
ll dp[2100][LOG];

int main() {
    init();
    cin >> n >> m >> k >> s;
    if (n == 1 && m == 1) {
        if (k == 0) {
            cout << s << "\n";
        }
        else {
            cout << (s + 1) / 2 << "\n";
        }
        return 0;
    }
    vv.push_back(make_pair(make_pair(0, 0), 0));
    vv.push_back(make_pair(make_pair(n - 1, m - 1), 0));
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (a == 0 && b == 0)
            vv[0].second = 1;
        else if (a == n - 1 && b == m - 1)
            vv[1].second = 1;
        else
            vv.push_back(make_pair(make_pair(a, b), 1));
    }
    sort(vv.begin(), vv.end());
    dp[0][0] = 1;
    for (int i = 1; i < vv.size(); ++i) {
        int x = vv[i].first.first;
        int y = vv[i].first.second;
        for (int k = 0; k < LOG; ++k) {
            dp[i][k] = get(x, y);
            for (int j = 0; j < i; ++j)
                if (vv[j].first.second <= y && vv[j].second)
                    dp[i][k] = (dp[i][k] - get(x - vv[j].first.first, y - vv[j].first.second) * dp[j][k] + MOD * MOD) % MOD;
        }
        for (int k = LOG - 1; k > 0; --k)
            dp[i][k] = (dp[i][k] - dp[i][k - 1] + MOD) % MOD;
    }
    if (vv.back().second) {
        for (int i = LOG - 1; i > 0; --i)
            dp[vv.size() - 1][i] = dp[vv.size() - 1][i - 1];
        dp[vv.size() - 1][0] = 0;
    }
    ll all = get(n - 1, m - 1);
    ll ans = 0;
    for (int i = 0; i < LOG; ++i) {
        all = (all - dp[vv.size() - 1][i] + MOD) % MOD;
        ans = (ans + s * dp[vv.size() - 1][i]) % MOD;
        s = (s + 1) / 2;
    }
    ans = (ans + all * 1) % MOD;
    ll q = get(n - 1, m - 1);
    q = pw(q, MOD - 2);
    cout << (ans * q) % MOD << "\n";
    return 0;
}
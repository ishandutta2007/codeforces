#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MASK = (1 << 20);
vector<int> ones[MASK];

inline void init() {
    for (int mask = 1; mask < MASK; mask++) {
        int one = 31 - __builtin_clz(mask);
        ones[mask] = ones[mask ^ (1 << one)];
        ones[mask].push_back(one);
    }
}

vector<int> calcDp(const vector<int> &g) {
    int n = len(g);
    int MASK = (1 << n);
    vector<int> dp(MASK);

    for (int mask = 1; mask < MASK; mask++) {
        int submask = (mask ^ (1 << ones[mask][0]));
        if (dp[submask] == len(ones[mask]) - 1 && submask == (g[ones[mask][0]] & submask)) {
            dp[mask] = len(ones[mask]);
            continue;
        }

        for (int one : ones[mask]) {
            int submask = (mask ^ (1 << one));
            dp[mask] = max(dp[mask], dp[submask]);
        }
    }
    return dp;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int n, k;
    cin >> n >> k;
    vector<ll> g(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll x;
            cin >> x;
            if (j <= i) x = 0;
            g[i] |= (x << j);
        }
    }

    int half = n / 2;
    vector<int> leftG(half);
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            int bit = (g[i] >> j) % 2;
            leftG[i] |= (bit << j);
        }
    }

    vector<int> rightG(n - half);
    for (int i = half; i < n; i++) {
        for (int j = half; j < n; j++) {
            int bit = (g[i] >> j) % 2;
            rightG[i - half] |= (bit << (j - half));
        }
    }

    vector<int> dp1 = calcDp(leftG);
    vector<int> dp2 = calcDp(rightG);

    int ans = 0;
    for (int mask = 0; mask < (1 << half); mask++) {
        int valid = len(dp2) - 1;
        for (auto i : ones[mask]) {
            assert(i < half);
            valid &= (g[i] >> half);
        }
        ans = max(ans, dp1[mask] + dp2[valid]);
    }
    assert(ans);

    using ld = long double;
    ld one = ld(k) / ans;
    cout << fixed << setprecision(10);
    cout << ans * (ans - 1) / 2 * one * one << '\n';
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x, x--;

    const int K = *max_element(all(a)) + 1;
    vector<vector<ll>> cnt(K, vector<ll>(K));

    vector<int> pref(K);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < K; j++)
            cnt[a[i]][j] += pref[j];

        pref[a[i]]++;
    }

    const int MASK = 1 << K;
    vector<vector<ll>> sum(K, vector<ll>(MASK));
    for (int i = 0; i < K; i++)
        for (int mask = 1; mask < MASK; mask++) {
            int b = __lg(mask);
            sum[i][mask] = sum[i][mask ^ (1 << b)] + cnt[i][b];
        }

    vector<ll> dp(MASK, LLONG_MAX);
    dp[0] = 0;

    for (int mask = 0; mask < MASK - 1; mask++)
        for (int b = 0; b < K; b++)
            if (!(mask >> b & 1))
                dp[mask ^ (1 << b)] = min(dp[mask ^ (1 << b)], dp[mask] + sum[b][mask]);

    cout << dp.back() << '\n';
}
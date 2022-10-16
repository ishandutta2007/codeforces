#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
const ll INF = 1e15 + 21;
const ll MAXN = 1e5 + 5;
typedef pair<ll, ll> pii;

const double PI = atan(1) * 4;
using ll = long long;
struct chash {
    const uint64_t C = ll(2e18 * PI) | 71; // large odd number
    ll operator()(ll x) const { return __builtin_bswap64(x * C); }
};
using ht = cc_hash_table<ll, ll>;


ll N, Q;
ll V[MAXN];
ll C[MAXN];
ll dp[MAXN];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;
    for (ll i = 0; i < N; i++) {
        cin >> V[i];
    }
    for (ll i = 0; i < N; i++) {
        cin >> C[i];
    }
    ht curMax;
    for (int i = 0; i < N; i++) {
        curMax[C[i]] = -INF;
    }
    for (ll i = 0; i < Q; i++) {
        for (auto j : curMax) {
            curMax[j.first] = -INF;
        }
        ll a, b;
        cin >> a >> b;
        fill(dp, dp + N, -1);
        pii mx1 = {0, 1e5 + 5};
        pii mx2 = {0, 1e5 + 4};
        for (ll j = 0; j < N; j++) {
            if (mx1.second == C[j]) {
                dp[j] = mx2.first + b * V[j];
            } else {
                dp[j] = mx1.first + b * V[j];
            }
            dp[j] = max(dp[j], curMax[C[j]] + a * V[j]);
            if (dp[j] > mx1.first) {
                if (C[j] == mx1.second) {
                    mx1 = {dp[j], C[j]};
                } else {
                    mx2 = {mx1.first, mx1.second};
                    mx1 = {dp[j], C[j]};
                }
            } else if (dp[j] > mx2.first) {
                if (C[j] == mx1.second) {
                    continue;
                } else {
                    mx2 = {dp[j], C[j]};
                }
            }
            curMax[C[j]] = max(curMax[C[j]], dp[j]);
        }
        cout << mx1.first << endl;
    }
}
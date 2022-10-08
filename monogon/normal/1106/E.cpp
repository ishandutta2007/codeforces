
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// dp[n][m]
// for each time, we should know which envelope is preferred.
// It will not depend on previously collected envelopes because t[i] <= d[i]
// scan the intervals, using priority queue.

const int N = 1e5 + 5, K = 1e5 + 5, M = 205;
int n, m, k, s[K], t[K], d[K];
vi ins[N], del[N];
ll w[K], dp[N][M];
pair<ll, int> pa[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    rep(i, 1, k + 1) {
        cin >> s[i] >> t[i] >> d[i] >> w[i];
        ins[s[i]].push_back(i);
        del[t[i]].push_back(i);
    }
    multiset<pair<ll, int>> Q;
    rep(t, 1, n + 1) {
        for(int i : ins[t]) {
            Q.emplace(w[i], d[i]);
        }
        if(Q.empty()) {
            pa[t] = {0, t};
        }else {
            pa[t] = *prev(Q.end());
        }
        for(int i : del[t]) {
            Q.erase(Q.find({w[i], d[i]}));
        }
    }
    for(int t = n; t >= 1; t--) {
        rep(j, 0, m + 1) {
            dp[t][j] = pa[t].fi + dp[pa[t].se + 1][j];
            if(j > 0) {
                dp[t][j] = min(dp[t][j], dp[t + 1][j - 1]);
            }
        }
    }
    cout << dp[1][m] << '\n';
}
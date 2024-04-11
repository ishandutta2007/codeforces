#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, bool>> events;
    rep(_, m) {
        int i, l, r;
        cin >> i >> l >> r;
        i--, l--;
        events.emplace_back(l, i, true);
        events.emplace_back(r, i, false);
    }
    sort(all(events));
    constexpr int INF = 1001001001;
    multiset<int> s{-INF, INF};
    VVI to(n);
    for(auto [x, i, t]: events) {
        if (t) {
            int j = *prev(s.lower_bound(i));
            int k = *s.upper_bound(i);
            if (j >= 0) {
                to[j].push_back(i);
            }
            if (k < n) to[i].push_back(k);
            s.insert(i);
        } else {
            s.erase(s.find(i));
        }
    }
    VI dp(n, 1);
    VI pre(n, -1);
    rep(i, n) {
        int nd = dp[i] + 1;
        for(int j: to[i]) {
            if (nd > dp[j]) dp[j] = nd, pre[j] = i;
        }
    }
    vector<char> visited(n);
    int v = max_element(all(dp)) - dp.begin();
    visited[v] = true;
    while(pre[v] != -1) {
        v = pre[v];
        visited[v] = true;
    }
    VI ans;
    rep(i, n) if (!visited[i]) ans.push_back(i);
    int sz = ans.size();
    cout << sz << '\n';
    rep(i, sz) cout << ans[i] + 1 << " \n"[i + 1 == sz];
}
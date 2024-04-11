#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
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
    int n;
    cin >> n;
    VVI idxs(5001);
    rep(i, n) {
      int x;
      cin >> x;
      idxs[x].push_back(i);
    }
    constexpr int INF = 1001001001;
    VI dp(1 << 13, INF), ndp;
    dp[0] = -1;
    rep(a, 5001) {
      auto& is = idxs[a];
      ndp = dp;
      rep(x, 1 << 13) {
        auto it = lower_bound(all(is), dp[x]);
        if(it == is.end()) continue;
        int i = *it;
        chmin(ndp[x ^ a], i + 1);
      }
      dp = move(ndp);
    }
    VI ans;
    rep(i, 1 << 13) if (dp[i] != INF) ans.push_back(i);
    int sz = ans.size();
    cout << sz << '\n';
    rep(i, sz) cout << ans[i] << " \n"[i + 1 == sz];
}
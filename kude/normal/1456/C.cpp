#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    VL c(n);
    rep(i, n) cin >> c[i];
    sort(rall(c));
    ++k;
    priority_queue<pair<ll,int>> q;
    rep(i, k) q.emplace(0, i);
    ll ans = 0;
    rep(i, n) {
        auto [cost, idx] = q.top(); q.pop();
        ans += cost;
        q.emplace(cost + c[i], idx);
    }
    cout << ans << endl;
}
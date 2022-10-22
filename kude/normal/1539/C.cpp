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
    int n;
    ll k, x;
    cin >> n >> k >> x;
    VL a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    priority_queue<ll, VL, greater<ll>> q;
    rep(i, n - 1) {
        ll d = a[i + 1] - a[i];
        if (d > x) q.push(d);
    }
    int ans = 1;
    while(!q.empty()) {
        ll d = q.top(); q.pop();
        ll needed = (d - 1) / x;
        if (needed <= k) k -= needed;
        else {
            ans += 1 + q.size();
            break;
        }
    }
    cout << ans << '\n';
}
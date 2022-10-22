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
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<P> p(n + 1);
        rep(i, n) cin >> p[i].first;
        rep(i, n) cin >> p[i].second;
        p[n] = {1, 1};
        sort(all(p));
        ll ans = 0;
        rep(i, n) {
            auto [rj, cj] = p[i+1];
            auto [ri, ci] = p[i];
            int tot = rj - ri, right = cj - ci, left = tot - right;
            if (!(rj + cj & 1)) {
                if (left == 0) {
                    ans += tot;
                    continue;
                }
                tot--, left--;
                ans++;
            }
            ans += left / 2;
        }
        cout << ans << '\n';
    }
}
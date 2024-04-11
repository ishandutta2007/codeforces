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
        int n, m, k;
        cin >> n >> m >> k;
        map<int, map<int, int>> xs, ys;
        xs[0], xs[1000000];
        ys[0], ys[1000000];
        rep(_, n) {
            int x;
            cin >> x;
            xs[x];
        }
        rep(_, m) {
            int y;
            cin >> y;
            ys[y];
        }
        rep(_, k) {
            int x, y;
            cin >> x >> y;
            if (x != xs.lower_bound(x)->first) {
                auto& d = xs.lower_bound(x)->second;
                d[y]++;
            } else if (y != ys.lower_bound(y)->first) {
                auto& d = ys.lower_bound(y)->second;
                d[x]++;
            }
        }
        ll ans = 0;
        for(auto& mp: {xs, ys}) {
            for(auto& [x, d]: mp) {
                ll acc = 0;
                for(auto [y, cnt]: d) {
                    ans += acc * cnt;
                    acc += cnt;
                }
            }
        }
        cout << ans << '\n';
    }
}
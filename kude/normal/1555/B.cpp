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
        ll W, H;
        cin >> W >> H;
        ll x1, y1, x2, y2, w, h;
        cin >> x1 >> y1 >> x2 >> y2 >> w >> h;
        constexpr ll INF = 1002003004005006007;
        ll ans = INF;
        rep(_, 2) {
            rep(_, 2) {
                ll dx = W - x2;
                if (dx >= w) {
                    ans = 0;
                    break;
                }
                ll d = w - dx;
                if (x1 >= d) chmin(ans, d);

                swap(x1, x2);
                x1 = W - x1;
                x2 = W - x2;
            }

            swap(x1, y1);
            swap(x2, y2);
            swap(w, h);
            swap(W, H);
        }
        if (ans == INF) ans = -1;
        cout << ans << '\n';
    }
}
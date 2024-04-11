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
        constexpr int INF = 1001001001;
        int lmin = INF, lmin_c = -1, rmax = -INF, rmax_c = -1;
        int l_maximal = INF, r_maximal = -INF, c_maximal = -1;
        rep(i, n) {
            int l, r, c;
            cin >> l >> r >> c;
            if (l < lmin) {
                lmin = l;
                lmin_c = c;
            } else if (l == lmin) {
                chmin(lmin_c, c);
            }
            if (r > rmax) {
                rmax = r;
                rmax_c = c;
            } else if (r == rmax) {
                chmin(rmax_c, c);
            }
            if (l < l_maximal || (l == l_maximal && r > r_maximal)) {
                l_maximal = l;
                r_maximal = r;
                c_maximal = c;
            } else if (l == l_maximal && r == r_maximal) {
                chmin(c_maximal, c);
            }
            int ans = lmin_c + rmax_c;
            if (lmin == l_maximal && rmax == r_maximal) chmin(ans, c_maximal);
            cout << ans << '\n';
        }
    }
}
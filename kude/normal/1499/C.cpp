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
        VI c(n);
        rep(i, n) cin >> c[i];
        ll mn_e = c[0], mn_o = c[1];
        ll ans = mn_e * n + mn_o * n;
        ll tot_e = c[0], tot_o = c[1];
        for(int i = 2; i < n; i++) {
            if (i & 1) {
                chmin<ll>(mn_o, c[i]);
                tot_e += c[i];
            } else {
                chmin<ll>(mn_e, c[i]);
                tot_o += c[i];
            }
            int seg_cnt_e = i / 2 + 1, seg_cnt_o = (i + 1) / 2;
            chmin(ans, tot_e + tot_o + (n - seg_cnt_e) * mn_e + (n - seg_cnt_o) * mn_o);
            //cout << i << ' ' << seg_cnt_e << ' ' << seg_cnt_o << ' ' << tot_e << ' ' << tot_o << ' ' << endl;
        }
        cout << ans << '\n';
    }
}
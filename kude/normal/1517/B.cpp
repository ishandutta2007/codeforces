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
        int n, m;
        cin >> n >> m;
        VVI b(n, VI(m));
        rep(i, n) rep(j, m) cin >> b[i][j];
        VVI ans(n, VI(m, -1));
        auto mycmp = [&](P x, P y) {
            auto [i, j] = x;
            auto [c, d] = y;
            return b[i][j] < b[c][d];
        };
        vector<P> ord;
        rep(i, n) rep(j, m) ord.emplace_back(i, j);
        sort(all(ord), mycmp);
        rep(z, m) {
            auto [i, j] = ord[z];
            ans[i][z] = b[i][j];
            b[i][j] = -1;
        }
        rep(i, n) {
            int z = 0;
            rep(j, m) if (b[i][j] >= 0) {
                while(ans[i][z] != -1) z++;
                ans[i][z] = b[i][j];
                b[i][j] = -1;
            }
        }
        rep(i, n) rep(j, m) cout << ans[i][j] << " \n"[j + 1 == m];
    }
}
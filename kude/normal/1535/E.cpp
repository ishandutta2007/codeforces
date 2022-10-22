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
    int q;
    cin >> q;
    VI a(q + 1), c(q + 1), depth(q + 1);
    VVI par(q + 1);
    cin >> a[0] >> c[0];
    depth[0] = 0;
    auto v_up = [&] (int v, int d) {
        int k = 0;
        while(d) {
            if (d & 1) v = par[v][k];
            d >>= 1;
            k++;
        }
        return v;
    };
    for(int i = 1; i <= q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            par[i].resize(1);
            cin >> par[i][0] >> a[i] >> c[i];
            depth[i] = depth[par[i][0]] + 1;
            for(int k = 0;; k++) {
                int pik = par[i][k];
                if (k < (int)par[pik].size()) {
                    par[i].push_back(par[pik][k]);
                } else break;
            }
        } else {
            int v, w;
            cin >> v >> w;
            int l = -1, r = depth[v] + 1;
            while(r - l > 1) {
                int mid = (r + l) >> 1;
                int u = v_up(v, mid);
                if (a[u] > 0) l = mid;
                else r = mid;
            }
            ll ans_a = 0, ans_c = 0;
            for(int d = l; d >= 0 && w > 0; d--) {
                int u = v_up(v, d);
                int amount = min(w, a[u]);
                ans_a += amount, w -= amount, a[u] -= amount;
                ans_c += (ll)amount * c[u];
            }
            cout << ans_a << ' ' << ans_c << endl;
        }
    }
}
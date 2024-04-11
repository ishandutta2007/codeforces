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

int a[110][110];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        rep(i, n) rep(j, m) {
            char t;
            cin >> t;
            a[i][j] = t - '0';
        }
        vector<vector<P>> ans;
        auto op = [&](int x, int y, int i, int j) {
            vector<P> res;
            for(int s: {x, x + 1}) for(int t: {y, y + 1}) if (s != i || t != j) {
                res.emplace_back(s+1, t+1);
                a[s][t] ^= 1;
            }
            assert(res.size() == 3);
            ans.push_back(res);
        };
        for(int i = n - 1; i >= 2; --i) {
            for(int j = m - 1; j >= 2; --j) {
                if (a[i][j] == 1) {
                    op(i-1, j-1, i, j-1);
                }
            }
            if (a[i][1] == 1) {
                if (a[i][0] == 1) op(i-1, 0, i-1, 0);
                else op(i-1, 0, i, 0);
            } else {
                if (a[i][0] == 1) op(i-1, 0, i, 1);
            }
        }
        for(int j = m - 1; j >= 2; --j) {
            if (a[0][j] == 1) {
                if (a[1][j] == 1) op(0, j-1, 0, j-1);
                else op(0, j-1, 1, j);
            } else {
                if (a[1][j] == 1) op(0, j-1, 0, j);
            }
        }
        int cnt = 0;
        rep(i, 2) rep(j, 2) cnt += a[i][j];
        if (cnt % 2 == 0) {
            vector<P> tmp;
            rep(i, 2) rep(j, 2) if (a[i][j] == 1) tmp.emplace_back(i, j);
            for(auto [i,j]: tmp) op(0, 0, i, j);
        } else {
            vector<P> tmp;
            rep(i, 2) rep(j, 2) if (a[i][j] == 0) tmp.emplace_back(i, j);
            for(auto [i,j]: tmp) op(0, 0, i, j);
        }
        cout << ans.size() << '\n';
        for(auto& v: ans) {
            rep(i, 3) cout << v[i].first << ' ' << v[i].second << " \n"[i == 2];
        }

        //rep(i, n) rep(j, m) assert(a[i][j] == 0);
    }
}
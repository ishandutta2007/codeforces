#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        VVI a(n, VI(m));
        rep(i, n) rep(j, m) cin >> a[i][j];
        ll ans = 0;
        rep(i, n) rep(j, m) {
            set<P> p{{i, j}, {n - 1 - i, j}, {i, m - 1 - j}, {n - 1 - i, m - 1 - j}};
            int mx = -999;
            vector<int> t;
            for(P ij: p) {
                t.push_back(a[ij.first][ij.second]);
            }
            sort(all(t));
            int tg = t[t.size() / 2];
            for(P ij: p) {
                ans += abs(a[ij.first][ij.second] - tg);
                //cout << a[ij.first][ij.second] << ' ' << ans << endl;
                a[ij.first][ij.second] = tg;
            }
            //cout << ans << endl;
        }
        cout << ans << endl;
        //cout << endl;
    }
}

#include <bits/stdc++.h>

#define ll long long
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()

using namespace std;

const int N = 1e5 + 5;
int n, w, h;
int g[N], p[N], t[N];
pii ans[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> w >> h;
    map<int, vi> ma;
    rep(i, 0, n) {
        cin >> g[i] >> p[i] >> t[i];
        ma[p[i] - t[i]].push_back(i);
    }
    for(auto &pa : ma) {
        vi ve = pa.second;
        sort(all(ve), [&](int i, int j) {
            if(g[i] != g[j]) return g[i] == 1;
            if(g[i] == 1) return p[i] > p[j];
            return p[i] < p[j];
        });
        vector<pii> ve2;
        for(int i : ve) {
            if(g[i] == 1) ve2.emplace_back(p[i], h);
            else ve2.emplace_back(w, p[i]);
        }
        sort(all(ve2), [&](pii &a, pii &b) {
            return make_pair(a.first, -a.second) < make_pair(b.first, -b.second);
        });
        int k = sz(ve);
        rep(i, 0, k) {
            ans[ve[i]] = ve2[k - i - 1];
        }
    }
    rep(i, 0, n) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}
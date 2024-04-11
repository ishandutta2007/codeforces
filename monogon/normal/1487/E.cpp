
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vi n(4);
    rep(i, 0, 4) cin >> n[i];
    vector<vi> a(4);
    rep(i, 0, 4) {
        a[i].resize(n[i]);
        rep(j, 0, n[i]) cin >> a[i][j];
    }
    rep(i, 1, 4) {
        vector<pii> kms;
        rep(j, 0, n[i - 1]) kms.push_back({a[i - 1][j], j});
        sort(all(kms));
        vector<bool> dirty(n[i - 1], false);
        vi p(n[i - 1]);
        rep(j, 0, n[i - 1]) p[kms[j].second] = j;
        int m;
        cin >> m;
        vector<vi> g(n[i]);
        rep(i, 0, m) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            g[y].push_back(p[x]);
        }
        rep(j, 0, n[i]) {
            for(int x : g[j]) dirty[x] = true;
            int k = min(sz(g[j]) + 1, n[i - 1]);
            int l = 0;
            while(l < k && dirty[l]) l++;
            if(l == n[i - 1] || kms[l].first == INT_MAX) a[i][j] = INT_MAX;
            else a[i][j] += kms[l].first;
            for(int x : g[j]) dirty[x] = false;
        }
    }
    int val = *min_element(all(a[3]));
    cout << (val == INT_MAX ? -1 : val) << '\n';
}
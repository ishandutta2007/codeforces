#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define vi vector<int>
using namespace std;
const int N = 1e3 + 10;
int n, d[N], fa[N], vis[N];
int gf(int x) {return fa[x] == x ? x : fa[x] = gf(fa[x]); }
int Q(int u) {
    cout << "? " << u << endl;
    int v;
    cin >> v;
    return v;
}
void solve() {
    cin >> n;
    vector<int> ord(n);
    FOR(i, 1, n) cin >> d[i], ord[i - 1] = i, fa[i] = i, vis[i] = 0;
    sort(ord.begin(), ord.end(), [&](int x, int y) {
        return d[x] > d[y];
    });
    for(auto u : ord) {
        if(vis[u]) continue;
        vis[u] = 1;
        FOR(i, 1, d[u]) {
            int v = Q(u);
            if(vis[v]) {
                fa[gf(u)] = gf(v);
                break;
            } else {
                fa[gf(v)] = gf(u), vis[v] = 1;
            }
        }
    }
    cout << "! ";
    FOR(i, 1, n) cout << gf(i) << " ";
    cout << endl;
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; ) solve();
    return 0;
}
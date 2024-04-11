#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define db double
#define ull unsigned long long
using namespace std;
const int N = 1e5 + 10, M = N * 32;
int n, a[N], rt[N];
int ch[M][2], siz[M], tot = 0;
int newd(int v) {
    int u = ++tot;
    ch[u][0] = ch[v][0], ch[u][1] = ch[v][1], siz[u] = siz[v];
    return u;
}
void ins(int &p, int q, int x, int dep = 29) {
    p = newd(q);
    siz[p]++;
    if(dep < 0) return;
    int c = x >> dep & 1;
    ins(ch[p][c], ch[q][c], x, dep - 1);
}
int gv(int p, int q, int dep) {
    if(dep < 0) return 0;
    if(siz[ch[p][0]] - siz[ch[q][0]]) return gv(ch[p][0], ch[q][0], dep - 1);
    return gv(ch[p][1], ch[q][1], dep - 1) | (1 << dep);
}
int qry(int p, int q, vector<int> v, int dep = 29) {
    if(dep < 0) return 0;
    int rsz = siz[ch[p][0]] - siz[ch[q][0]], vsz = 0;
    vector<int> nx;
    for(auto x : v) if(~x >> dep & 1) vsz++, nx.emplace_back(x);
    if(rsz + vsz >= 2) {
        return qry(ch[p][0], ch[q][0], nx, dep - 1);
    }
    if(rsz > 0) {
        v.emplace_back(gv(ch[p][0], ch[q][0], dep - 1));
    }
    return qry(ch[p][1], ch[q][1], v, dep - 1) | (1 << dep);
}
void solve() {
    tot = 0;
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i];
        ins(rt[i], rt[i - 1], a[i]);
    }
    int q;
    cin >> q;
    FOR(i, 1, q) {
        int l, r;
        cin >> l >> r;
        cout << qry(rt[r], rt[l - 1], {}) << "\n";
    }
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; solve());
    return 0;
}
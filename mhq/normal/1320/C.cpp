#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m, p;
const int maxN = (int)1e6 + 22;
int a[maxN], b[maxN];
int ca[maxN], cb[maxN];
const ll INF = 1e18;
ll valX[maxN];
vector < pair < int, int > > all[maxN];
ll lazy[4 * maxN];
ll t[4 * maxN];
ll valY[4 * maxN];
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = valY[tl + 1];
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = max(t[2 * v], t[2 * v + 1]);
}
void upd(int v, ll by) {
    lazy[v] += by;
    t[v] += by;
}
void merge(int v) {
    t[v] = max(t[2 * v], t[2 * v + 1]);
}
void push(int v, int tl, int tr) {
    if (tl != tr && lazy[v] != 0) {
        upd(2 * v, lazy[v]);
        upd(2 * v + 1, lazy[v]);
    }
    lazy[v] = 0;
}
void upd(int v, int tl, int tr, int l, int r, ll by) {
    if (l > tr || r < tl) return;
    if (l <= tl && tr <= r) {
        upd(v, by);
        push(v, tl, tr);
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) /  2;
    upd(2 * v, tl, tm, l, r, by);
    upd(2 * v + 1, tm + 1, tr, l, r, by);
    merge(v);
}
int x[maxN], y[maxN], z[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> p;
    for (int i = 0; i < maxN; i++) {
        valX[i] = -INF;
        valY[i] = -INF;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> ca[i];
        valX[a[i]] = max(valX[a[i]], -(ll)ca[i]);
    }
    for (int i = maxN - 2; i >= 0; i--) {
        valX[i] = max(valX[i], valX[i + 1]);
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i] >> cb[i];
        valY[b[i]] = max(valY[b[i]], -(ll)cb[i]);
    }
    for (int i = maxN - 2; i >= 0; i--) {
        valY[i] = max(valY[i], valY[i + 1]);
    }
    ll best = valX[0] + valY[0];
    for (int i = 1; i <= p; i++) {
        cin >> x[p] >> y[p] >> z[p];
        all[x[p]].emplace_back(y[p], z[p]);
    }
    const int INF = (int)1e6 + 4;
    build(1, 1, INF);
    for (int i = 1; i <= INF; i++) {
        for (auto it : all[i]) {
            upd(1, 1, INF, it.first, INF, it.second);
        }
        best = max(best, valX[i + 1] + t[1]);
    }
    cout << best;
    return 0;
}
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = (int)1e6 + 100;
int x[maxN], y[maxN], c[maxN];
int bestX = 1.5e9;
int bestY = bestX;
ll cost = 0;
int idX[maxN], idY[maxN];
int id[maxN];
vector < int > events[maxN];
pair < ll, int > t[4 * maxN];
ll upd[4 * maxN];
void build(int v, int tl, int tr) {
    t[v] = make_pair(0, tl);
    if (tl == tr) return;
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
}
void push(int v, int tl, int tr) {
    if (upd[v] == 0) return;
    t[v].first += upd[v];
    if (tl != tr) {
        upd[2 * v] += upd[v];
        upd[2 * v + 1] += upd[v];
    }
    upd[v] = 0;
}
void add(int v, int tl, int tr, int l, int r, ll val) {
    if (l <= tl && tr <= r) {
        upd[v] += val;
        push(v, tl, tr);
        return;
    }
    push(v, tl, tr);
    if (r < tl || l > tr) return;
    int tm = (tl + tr) / 2;
    add(2 * v, tl, tm, l, r, val);
    add(2 * v + 1, tm + 1, tr, l, r, val);
    t[v] = max(t[2 * v], t[2 * v + 1]);
}
const ll INF = 2e18;
pair < ll, int > get_mx(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if (l <= tl && tr <= r) return t[v];
    if (l > r) return make_pair(-INF, -1);
    int tm = (tl + tr) / 2;
    return max(get_mx(2 * v, tl, tm, l, min(r, tm)), get_mx(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    vector < int > cords;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> c[i];
        if (x[i] < y[i]) swap(x[i], y[i]);
        cords.push_back(x[i]);
        cords.push_back(y[i]);
    }
    sort(cords.begin(), cords.end());
    cords.erase(unique(cords.begin(), cords.end()), cords.end());
    for (int i = 0; i < cords.size(); i++) {
        id[i + 1] = cords[i];
    }
    for (int i = 1; i <= n; i++) {
        idX[i] = lower_bound(cords.begin(), cords.end(), x[i]) - cords.begin() + 1;
        idY[i] = lower_bound(cords.begin(), cords.end(), y[i]) - cords.begin() + 1;
        events[idX[i]].push_back(i);
    }
    int m = cords.size();
    build(1, 1, m);
    for (int i = 1; i <= cords.size(); i++) {
        add(1, 1, m, i, i, id[i]);
        for (int v : events[i]) {
            add(1, 1, m, 1, idY[v], c[v]);
        }
        auto it = get_mx(1, 1, m, 1, i);
        ll val = it.first - id[i];
        if (val > cost) {
            bestX = id[i];
            bestY = id[it.second];
            cost = val;
        }
    }
    cout << cost << '\n';
    cout << bestY << " " << bestY << " " << bestX << " " << bestX;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 6e5 + 10;
pair<int,int> mx[4 * maxN];
pair<int,int> lazy[4 * maxN];
void apply(int v, pair<int,int>& c) {
    lazy[v] = max(lazy[v], c);
    mx[v] = max(mx[v], c);
}
void push(int v, int tl, int tr) {
    if (tl != tr && lazy[v].first != 0) {
        apply(2 * v, lazy[v]);
        apply(2 * v + 1, lazy[v]);
        lazy[v] = make_pair(0, 0);
    }
}
void upd(int v, int tl, int tr, int l, int r, pair<int,int>& c) {
    if (tr < l || tl > r) return;
    if (l <= tl && tr <= r) {
        apply(v, c);
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    upd(2 * v, tl, tm, l, r, c);
    upd(2 * v + 1, tm + 1, tr, l, r, c);
    mx[v] = max(mx[2 * v], mx[2 * v + 1]);
}

pair<int,int> get(int v, int tl, int tr, int l, int r) {
    if (tr < l || tl > r) return make_pair(0, 0);
    if (l <= tl && tr <= r) {
        return mx[v];
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}
int n, m;
vector<pair<int,int>> segs[maxN];
pair<int,int> val[maxN];
int main() {
  //  freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<int> cords;
    for (int i = 1; i <= m; i++) {
        int id, l, r;
        cin >> id >> l >> r;
        segs[id].emplace_back(l, r);
        cords.emplace_back(l);
        cords.emplace_back(r);
    }
    sort(cords.begin(), cords.end());
    cords.erase(unique(cords.begin(), cords.end()), cords.end());
    int N = cords.size();
    assert(N < maxN);
    pair<int,int> opt = make_pair(0, 0);
    for (int i = 1; i <= n; i++) {
        pair<int,int> best = make_pair(0, 0);
        for (auto& it : segs[i]) {
            int l = lower_bound(cords.begin(), cords.end(), it.first) - cords.begin();
            it.first = l;
            int r = lower_bound(cords.begin(), cords.end(), it.second) - cords.begin();
            it.second = r;
            best = max(best, get(1, 0, N - 1, l, r));
        }
        best.first++;
        opt = max(opt, make_pair(best.first, i));
        val[i] = best;
        pair<int,int> to_upd = make_pair(best.first, i);
        for (auto& it : segs[i]) {
            upd(1, 0, N - 1, it.first, it.second, to_upd);
        }
    }
    assert(opt.second != 0);
    int st = opt.second;
    vector<bool> good(n + 1);
    while (st != 0)  {
        good[st] = true;
        st = val[st].second;
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (!good[i]) ans.emplace_back(i);
    }
    cout << ans.size() << '\n';
    for (int v : ans) cout << v << " ";
}
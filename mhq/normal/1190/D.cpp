#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2 * (int)1e5 + 100;
vector < int > compress(vector < pair < int, int > >& a) {
    sort(a.begin(), a.end());
    int cur = 1;
    vector < int > ans(a.size());
    int i = 0;
    while (i < a.size()) {
        int j = i;
        while (j < a.size() && a[j].first == a[i].first) j++; j--;
        for (int k = i; k <= j; k++) {
            ans[a[k].second] = cur;
        }
        cur++;
        i = j + 1;
    }
    return ans;
}


ll t[4 * maxN];
ll lazy[4 * maxN];

void add(int v, ll x, int tl, int tr) {
    t[v] += (tr - tl + 1) * x;
    lazy[v] += x;
}

void push(int v, int tl, int tr) {
    if (tl != tr) {
        int tm = (tl + tr) / 2;
        add(2 * v, lazy[v], tl, tm);
        add(2 * v + 1, lazy[v], tm + 1, tr);
    }
    lazy[v] = 0;
}

void update(int v) {
    t[v] = t[v + v] + t[v + v + 1];
}

void upd(int v, int tl, int tr, int l, int r, int val) {
    if (l <= tl && tr <= r) {
        add(v, val, tl, tr);
        return;
    }
    if (l > tr || tl > r) {
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    upd(v + v, tl, tm, l, r, val);
    upd(v + v + 1, tm + 1, tr, l, r, val);
    update(v);
}

ll get(int v, int tl, int tr, int l, int r) {
    if (l <= tl && tr <= r) {
        return t[v];
    }
    if (l > tr || tl > r) {
        return 0;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return get(v + v, tl, tm, l, r) + get(v + v + 1, tm + 1, tr, l, r);
}

const int INF = 200 * 1000 + 2;

bool was[maxN];
bool already[maxN];
vector < int > byY[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    vector < pair < int, int > > xx, yy;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        xx.emplace_back(x, i);
        yy.emplace_back(y, i);
    }
    auto vx = compress(xx);
    auto vy = compress(yy);
    vector < pair < int, int > > all;
    for (int i = 0; i < n; i++) {
        all.emplace_back(vx[i], vy[i]);
        byY[vy[i]].push_back(vx[i]);
    }
    ll total = 0;
    int sz = 0;
    for (int i = maxN - 1; i >= 0; i--) {
        vector < int > ones;
        ones.push_back(0);
        ones.push_back(INF + 1);
        for (int v : byY[i]) {
            if (!was[v]) {
                sz++;
                was[v] = true;
            }
            ones.push_back(v);
        }
        sort(ones.begin(), ones.end());
        ones.erase(unique(ones.begin(), ones.end()), ones.end());
        total += (1LL * sz * (sz + 1)) / 2;
        for (int j = 0; j + 1 < ones.size(); j++) {
            if (ones[j] + 1 > ones[j + 1] - 1) continue;
            int cnt = get(1, 1, INF, ones[j] + 1, ones[j + 1] - 1);
            total -= (1LL * cnt * (cnt + 1)) / 2;
        }
        for (int j = 1; j + 1 < ones.size(); j++) {
            if (already[ones[j]]) continue;
            upd(1, 1, INF, ones[j], ones[j], 1);
            already[ones[j]] = true;
        }
    }
    cout << total;
    return 0;
}
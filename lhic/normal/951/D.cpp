#ifndef BZ
#pragma GCC optimize -O3
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

const int MAXN = 510000;

int n, k, m;
int p[MAXN], sz[MAXN];

int get(int x) {
    if (p[x] == x)
        return x;
    return p[x] = get(p[x]);
}

void un(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b)
        return;
    if (sz[a] > sz[b])
        swap(a, b);
    p[a] = b;
    sz[b] += sz[a];
}

int pp[MAXN];
int used[MAXN];
ll ww[MAXN];

vector<tuple<int, int, ll> > vv;

vector<pair<int, int> > ed;


vector<pair<int, int> > eds[MAXN];

int tin[MAXN];
int tout[MAXN];
int tm1;

bool is_p(int a, int b) {
    return (tin[a] <= tin[b]) && (tin[b] < tout[a]);
}

void dfs1(int v, int p) {
    tin[v] = tm1++;
    for (auto e: eds[v]) {
        int u = e.first;
        if (u == p)
            continue;
        pp[u] = v;
        if (e.second) {
            used[u] = 1;
        }
        else {
            used[u] = 0;
        }
        dfs1(u, v);
    }
    tout[v] = tm1;
}

int get2(int a) {
    if (!used[a])
        return a;
    return pp[a] = get2(pp[a]);
}

void go(int a, int b, ll w) {
    while (!is_p(a, b)) {
        if (!used[a]) {
            used[a] = 1;
            ww[a] = w;
        }
        a = get2(a);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);
#ifdef BZ
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> k >> m;
    for (int i = 0; i < n; ++i)
        p[i] = i, sz[i] = 1;
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        un(a, b);
        ed.emplace_back(a, b);
    }
    int cnt = n;
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        --a, --b;
        if (get(a) == get(b)) {
            vv.emplace_back(a, b, w);
        }
        else {
            un(a, b);
            ed.emplace_back(a, b);
        }
    }
    for (int i = 0; i < k; ++i) {
        int a, b;
        tie(a, b) = ed[i];
        eds[a].emplace_back(b, 0);
        eds[b].emplace_back(a, 0);
    }
    for (int i = k; i < ed.size(); ++i) {
        int a, b;
        tie(a, b) = ed[i];
        eds[a].emplace_back(b, 1);
        eds[b].emplace_back(a, 1);
    }
    pp[0] = 0;
    used[0] = 0;
    ww[0] = 0;
    dfs1(0, -1);
    for (auto e: vv) {
        int a, b;
        ll w;
        tie(a, b, w) = e;
        go(a, b, w);
        go(b, a, w);
    }
    for (int i = 1; i < n; ++i)
        if (!used[i]) {
            cout << -1 << "\n";
            return 0;
        }
    ll ans = 0;
        for (int i = 1; i < n; ++i)
            ans += ww[i];
        cout << ans << "\n";
    return 0;
}
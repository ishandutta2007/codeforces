#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

struct st {
    int p, c, l;
};

bool cmp(st a, st b) {
    return a.l < b.l;
}

struct edge {
    int a, b, c, f;
};

vector<edge> ed;
vector<int> eds[300];
ll dd[300];
int pp[300];
const int INF = 1e6;
queue<int> qu;
int s, t;

void add_edge(int a, int b, int c) {
    edge x;
    x.a = a;
    x.b = b;
    x.c = c;
    x.f = 0;
    eds[a].push_back(ed.size());
    ed.push_back(x);
    swap(x.a, x.b);
    x.c = 0;
    eds[b].push_back(ed.size());
    ed.push_back(x);
}

ll dfs1(int v, ll fl) {
    if (v == t)
        return fl;
    if (dd[v] >= dd[t])
        return 0;
    ll now = 0;
    for (; pp[v] < eds[v].size(); ++pp[v]) {
        int e = eds[v][pp[v]];
        int u = ed[e].b;
        ll go = ed[e].c - ed[e].f;
        if (go == 0 || dd[u] != dd[v] + 1)
            continue;
        go = dfs1(u, min(fl, go));
        fl -= go;
        now += go;
        ed[e].f += go;
        ed[e ^ 1].f -= go;
        if (fl == 0)
            break;
    }
    return now;
}

ll dinic() {
    fill(dd, dd + t + 1, INF);
    dd[s] = 0;
    qu.push(s);
    while (!qu.empty()) {
        int x = qu.front();
        qu.pop();
        for (int e: eds[x]) {
            int u = ed[e].b;
            if (ed[e].c == ed[e].f || dd[u] < dd[x] + 1)
                continue;
            dd[u] = dd[x] + 1;
            qu.push(u);
        }
    }
    if (dd[t] == INF)
        return 0;
    fill(pp, pp + t + 1, 0);
    return dfs1(s, INF);
}

ll flow() {
    ll ans = 0;
    while (true) {
        ll x = dinic();
        ans += x;
        if (x == 0)
            break;
    }
    return ans;
}

st a[1200];
const int MX = 220000;
int pr[MX];

int solve(int n) {
    int fl1 = 0;
    vector<pair<int, int> > v1;
    vector<pair<int, int> > v0;
    for (int i = 0; i < n; ++i) {
        if (a[i].c == 1) {
            fl1 = max(fl1, a[i].p);
        }
        else if (a[i].c % 2 == 0) {
            v0.push_back(make_pair(a[i].p, a[i].c));
        }
        else {
            v1.push_back(make_pair(a[i].p, a[i].c));
        }
    }
    if (fl1 != 0)
        v1.push_back(make_pair(fl1, 1));
    n = v0.size();
    int m = v1.size();
    s = n + m;
    t = n + m + 1;
    for (int i = 0; i < t + 1; ++i)
        eds[i].clear();
    ed.clear();
    ll ans = 0;
    for (int i = 0; i < n; ++i)
        add_edge(s, i, v0[i].first), ans += v0[i].first;
    for (int i = 0; i < m; ++i)
        add_edge(i + n, t, v1[i].first), ans += v1[i].first;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (pr[v0[i].second + v1[j].second])
                add_edge(i, j + n, INF);
        }
    ans -= flow();
    return ans;
}

int main() {
    for (int i = 2; i < MX; ++i)
        pr[i] = 1;
    for (int i = 2; i < MX; ++i) {
        if (!pr[i])
            continue;
        for (ll j = (ll)i * i; j < MX; j += i)
            pr[j] = 0;
    }
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &a[i].p, &a[i].c, &a[i].l);
    }
    sort(a, a + n, cmp);
    int l = 0;
    int r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        if (solve(mid) >= k)
            r = mid;
        else
            l = mid;
    }
    if (r == n + 1) {
        cout << -1 << "\n";
    }
    else {
        cout << a[l].l << "\n";
    }
    return 0;
}
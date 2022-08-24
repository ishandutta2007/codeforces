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

int n, m;


struct edge {
    int a, b, l, r;
    edge(int A = 0, int B = 0, int L = 0, int R = 0) {
        a = A, b = B, l = L, r = R;
    }
};
const int MAXN = 2100000;
const int INF = 1e9 + 1000;
int cc;

edge ed[MAXN];
vector<int> ee[MAXN][2];
int tp[MAXN];
int dd[MAXN];
set<pair<int, int> > ss;

void add(int a, int b, int l, int r) {
    if (l % 2 == 0 || r - l >= 2) {
        ee[a][0].push_back(cc);
        ed[cc] = edge(a, b, l, r);
        tp[cc] = 0;
        ++cc;
    }
    if (l % 2 == 1 || r - l >= 2) {
        ee[a][1].push_back(cc);
        ed[cc] = edge(a, b, l, r);
        tp[cc] = 1;
        ++cc;
    }
}

bool cmp(int a, int b) {
    return ed[a].l > ed[b].l;
}

int main() {
    scanf("%d%d", &n, &m);
    if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }
    for (int i = 0; i < m; ++i) {
        int a, b, l, r;
        scanf("%d%d%d%d", &a, &b, &l, &r);
        --a, --b;
        add(a, b, l, r);
        add(b, a, l, r);
    }
    for (int i = 0; i < cc; ++i)
        dd[i] = INF;
    for (int i = 0; i < cc; ++i) {
        if (tp[i] == 0 && ed[i].a == 0 && ed[i].l == 0) {
            dd[i] = 0;
            ss.insert(make_pair(dd[i], i));
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j)
            sort(ee[i][j].begin(), ee[i][j].end(), cmp);
    }
    while (!ss.empty()) {
        int x = ss.begin()->second;
        ss.erase(ss.begin());
        int g = dd[x] + 1;
        int u = ed[x].b;
        int t = tp[x] ^ 1;
        int r = ed[x].r;
        if (r % 2 != g % 2)
            --r;
        while (!ee[u][t].empty()) {
            int y = ee[u][t].back();
            if (dd[y] < INF) {
                ee[u][t].pop_back();
                continue;
            }
            if (g + 1 > ed[y].r) {
                ee[u][t].pop_back();
                continue;
            }
            if (r < ed[y].l)
                break;
            int go = max(g, ed[y].l);
            if (go % 2 != tp[y])
                ++go;
            dd[y] = go;
            ss.insert(make_pair(dd[y], y));
        }
    }
    int ans = INF;
    for (int i = 0; i < cc; ++i) {
        if (ed[i].b == n - 1) {
            ans = min(ans, dd[i] + 1);
        }
    }
    if (ans == INF)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
    return 0;
}
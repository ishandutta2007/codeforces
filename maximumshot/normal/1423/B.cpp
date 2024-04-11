#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e4 + 5;

int n, m;
vector<pii> g[N];
int mt[N], pr[N];
int used[N];

bool dfs(int v, int maxd) {
    if (used[v])
        return false;
    used[v] = 1;
    for (auto [to, w] : g[v]) {
        if (w > maxd)
            continue;
        if (mt[to] == -1 || dfs(mt[to], maxd)) {
            mt[to] = v;
            pr[v] = to;
            return true;
        }
    }
    return false;
}

bool check(int maxd) {
    fill(mt, mt + n, -1);
    fill(pr, pr + n, -1);
    for (int run = 1; run;) {
        run = 0;
        fill(used, used + n, 0);
        for (int v = 0; v < n; v++)
            if (pr[v] == -1 && dfs(v, maxd))
                run = 1;
    }
    int res = 0;
    for (int v = 0; v < n; v++)
        res += mt[v] != -1;
    return res == n;
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    vector<int> ws;
    ws.push_back(0);
    ws.push_back(inf + 5);
    for (int u, v, w, i = 0; i < m; i++) {
        cin >> u >> v >> w;
        ws.push_back(w);
        u--, v--;
        g[u].emplace_back(v, w);
    }
    sort(ws.begin(), ws.end());
    ws.erase(unique(ws.begin(), ws.end()), ws.end());

    int bl = -1;
    int br = (int) ws.size() - 1;
    int bm;

    while (br - bl > 1) {
        bm = (bl + br) / 2;
        if (check(ws[bm]))
            br = bm;
        else
            bl = bm;
    }

    cout << (check(ws[br]) ? ws[br] : -1) << "\n";

    return 0;
}
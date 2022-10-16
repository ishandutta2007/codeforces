#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define pb push_back
#define dbg(x) cerr << #x << " " << x << "\n"
const int INF = 2e9;
struct Edge {
    int x;
    int y;
    int s;
    bool operator < (const Edge &other) const {
        return s < other.s;
    }
};

struct DSU {
    int n;
    vector <int> f;
    DSU (int n) {
        this->n = n;
        f.resize (n + 1);
        for (int i = 1; i <= n; i++)
            f[i] = i;
    }
    int ft (int x) {
        if (f[x] == x) return x;
        return (f[x] = ft (f[x]));
    }
    bool unite (int x, int y) {
        int tx = ft (x);
        int ty = ft (y);
        if (tx == ty)
            return false;
        f[tx] = ty;
        return true;
    }
};

void solveTest () {
    int n, m, k;
    cin >> n >> m >> k;
    vector <Edge> smalledges, bigedges;
    int best = INF;
    for (int i = 0; i < m; i++) {
        int x, y, s;
        cin >> x >> y >> s;
        best = min (best, abs (s - k));
        if (s <= k)
            smalledges.pb ({x, y, s});
        else
            bigedges.pb ({x, y, s - k});
    }
    int lft = n - 1;
    DSU apm (n);
    for (Edge e : smalledges)
        if (apm.unite (e.x, e.y))
            lft--;
    if (lft == 0) {
        cout << best << "\n";
        return;
    }
    sort (bigedges.begin (), bigedges.end ());
    ll ans = 0;
    for (Edge e : bigedges)
        if (apm.unite (e.x, e.y))
            lft--, ans += e.s;
    assert (lft == 0);
    cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--)
        solveTest ();
    return 0;
}
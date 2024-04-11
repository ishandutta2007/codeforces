#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 100 * 1000 + 10;
const int V = (int)4e6;

vector<int> g[V];
vector<int> w[V];
int n;
int last; 

const ll INF = (ll)1e18;

int from[V];
int to[V];

void build(int i, int l, int r) {
    if (l == r) {
        to[i] = from[i] = l;
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    to[i] = last++;
    from[i] = last++;
    for (int d = 1; d <= 2; d++) {
        g[to[i]].push_back(to[2 * i + d]);
        w[to[i]].push_back(0);
        g[from[2 * i + d]].push_back(from[i]);
        w[from[2 * i + d]].push_back(0);
    }
}

void add(int i, int tl, int tr, int l, int r, int v, int len, bool out) {
    if (l == tl && r == tr) {
        if (out) {
            g[from[i]].push_back(v);
            w[from[i]].push_back(len);
        } else {
            g[v].push_back(to[i]);
            w[v].push_back(len);
        }
        return;
    }
    int m = (tl + tr) / 2;
    if (l <= m)
        add(2 * i + 1, tl, m, l, min(r, m), v, len, out);
    if (r > m)
        add(2 * i + 2, m + 1, tr, max(m + 1, l), r, v, len, out);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int m, s;
    cin >> n >> m >> s;
    s--;
    last = n;
    build(0, 0, n - 1);
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b, l;
            cin >> a >> b >> l;
            a--;
            b--;
            g[a].push_back(b);
            w[a].push_back(l);
        } else if (t == 2) {
            int v, l, r, len;
            cin >> v >> l >> r >> len;
            v--;
            l--;
            r--;
            add(0, 0, n - 1, l, r, v, len, false);
        } else {
            int v, l, r, len;
            cin >> v >> l >> r >> len;
            v--;
            l--;
            r--;
            add(0, 0, n - 1, l, r, v, len, true);
        }
    }
    priority_queue<pair<long long, int>> q;
    vector<ll> d(V, INF);
    vector<bool> was(V, false);
    d[s] = 0;
    q.push(mp(0, s));
    while (q.size()) {
        int v = q.top().second;
        q.pop();
        if (was[v])
            continue;
        was[v] = true;
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            if (d[to] > d[v] + w[v][i]) {
                d[to] = d[v] + w[v][i];
                q.push(mp(-d[to], to));
            }
        }
    }
    for (ll i = 0; i < n; i++)
        cout << (d[i] == INF ? -1 : d[i]) << " ";
    cout << "\n";
}
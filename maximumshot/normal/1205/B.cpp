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

const int N = 2e5 + 5;
const int LOG = 60;

int n;
ll a[N];
vector<int> g[N], h[N];
int dist[N];

void read() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

int solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < LOG; j++) {
            if ((1ll << j) & a[i]) {
                g[i].push_back(n + j);
                g[n + j].push_back(i);
            }
        }
    }
    for (int t = n; t < n + LOG; t++) {
        if ((int) g[t].size() > 2) {
            return 3;
        }
        if ((int) g[t].size() == 2) {
            int u = g[t][0];
            int v = g[t][1];
            h[u].push_back(v);
            h[v].push_back(u);
        }
    }
    int res = inf;
    for (int s = 0; s < n; s++) {
        for (int t : h[s]) {
            fill(dist, dist + n, inf);
            dist[s] = 0;
            queue<int> q;
            q.push(s);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int to : h[v]) {
                    if (v == s && to == t) continue;
                    if (v == t && to == s) continue;
                    if (dist[to] > dist[v] + 1) {
                        dist[to] = dist[v] + 1;
                        q.push(to);
                    }
                }
            }
            res = min(res, dist[t] + 1);
        }
    }
    return res == inf ? -1 : res;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    cout << solve() << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
//    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> dist(n + 1, inf), from(n + 1, -1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int y = 0; y <= v && y <= k; y++) {
            int to = v - y + k - y;
            if (v + k - y <= n && dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                from[to] = v;
                q.push(to);
            }
        }
    }

    if (dist[n] == inf) {
        cout << -1 << endl;
        return 0;
    }

    vector<vector<int>> path;

    vector<int> cur(n, 1);
    for (int to = n; to > 0; to = from[to]) {
        int v = from[to];
        int y = (v + k - to) / 2;
        int z = k - y;
        vector<int> nxt = cur, edge(n);
        for (int i = 0; i < n && y > 0; i++) {
            if (!cur[i]) {
                y--;
                nxt[i] = 1;
                edge[i] = 1;
            }
        }
        for (int i = 0; i < n && z > 0; i++) {
            if (cur[i]) {
                z--;
                nxt[i] = 0;
                edge[i] = 1;
            }
        }
        path.push_back(edge);
        cur = nxt;
    }

    reverse(path.begin(), path.end());

    int res = 0;
    for (auto e : path) {
        cout << "? ";
        for (int i = 0; i < n; i++) {
            if (e[i])
                cout << i + 1 << " ";
        }
        cout << endl;
        int tmp;
        cin >> tmp;
        res ^= tmp;
    }

    cout << "! " << res << endl;

    return 0;
}
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

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> ds(m);
    for (int i = 0; i < m; i++)
        cin >> ds[i];
    sort(ds.begin(), ds.end());
    ds.erase(unique(ds.begin(), ds.end()), ds.end());
    m = (int) ds.size();

    int g, r;
    cin >> g >> r;

    vector<vector<int>> dist(m, vector<int>(g, inf));
    deque<pii> dq;

    dist[0][0] = 0;
    dq.push_back({0, 0});

    while (!dq.empty()) {
        int v, x;
        tie(v, x) = dq.front();
        dq.pop_front();

        if (v > 0) {
            int w = ds[v] - ds[v - 1];
            if (x + w <= g) {
                int y = x + w < g ? x + w : 0;
                int cost = y == 0;
                if (dist[v - 1][y] > dist[v][x] + cost) {
                    dist[v - 1][y] = dist[v][x] + cost;
                    if (cost)
                        dq.push_back({v - 1, y});
                    else
                        dq.push_front({v - 1, y});
                }
            }
        }

        if (v + 1 < m) {
            int w = ds[v + 1] - ds[v];
            if (x + w <= g) {
                int y = x + w < g ? x + w : 0;
                int cost = y == 0;
                if (dist[v + 1][y] > dist[v][x] + cost) {
                    dist[v + 1][y] = dist[v][x] + cost;
                    if (cost)
                        dq.push_back({v + 1, y});
                    else
                        dq.push_front({v + 1, y});
                }
            }
        }
    }

    int res = inf;

    for (int i = 0; i < m; i++) {
        if (dist[i][0] == inf || ds[i] + g < n)
            continue;
        res = min(res, dist[i][0] * (g + r) + n - ds[i]);
    }

    if (res == inf)
        res = -1;

    cout << res << "\n";

    return 0;
}
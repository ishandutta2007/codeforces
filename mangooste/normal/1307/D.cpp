#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using ll = long long;
using namespace std;

const int INF = 1e8;
const int N = 2e5 + 2;

int n, m, k;
vector<int> G[N];
int a[N];
bool sp[N];
int distN[N], dist1[N];
int suf[N];

bool cmp(int& v, int& u) {
    return dist1[v] < dist1[u];
}

void bfsN() {
    for (int i = 0; i < n; i++)
        distN[i] = INF;
    distN[n - 1] = 0;
    queue<pair<int, int>> q;
    q.push({ 0, n - 1 });
    while (!q.empty()) {
        int v = q.front().second;
        int d = q.front().first;
        q.pop();
        for (auto u : G[v]) {
            if (distN[u] > d + 1) {
                distN[u] = d + 1;
                q.push({ distN[u], u });
            }
        }
    }
}

void bfs1() {
    for (int i = 0; i < n; i++)
        dist1[i] = INF;
    dist1[0] = 0;
    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    while (!q.empty()) {
        int v = q.front().second;;
        int d = q.front().first;
        q.pop();
        for (auto u : G[v]) {
            if (dist1[u] > d + 1) {
                dist1[u] = d + 1;
                q.push({ dist1[u], u });
            }
        }
    }
}

int getAns() {
    int ans = 0;
    for (int i = k - 2; i >= 0; i--)
        ans = max(ans, dist1[a[i]] + 1 + suf[i + 1]);
    return min(ans, distN[0]);
}

signed main() {
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> a[i], a[i]--;
        sp[a[i]] = true;
    }
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u, v--, u--;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    bfsN();
    bfs1();
    sort(a, a + k, cmp);
    suf[k - 1] = distN[a[k - 1]];
    for (int i = k - 2; i >= 0; i--)
        suf[i] = max(suf[i + 1], distN[a[i]]);
    cout << getAns() << '\n';
}
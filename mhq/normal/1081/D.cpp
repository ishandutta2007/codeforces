#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = (int)1e5 + 10;
int p[maxN];
int sz[maxN];
int get(int a) {
    if (a == p[a]) return a;
    p[a] = get(p[a]);
    return p[a];
}
bool unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return false;
    if (rand() % 2) swap(a, b);
    sz[a] += sz[b];
    p[b] = a;
    return true;
}
int n, m, k;
bool need[maxN];
vector < pair < int, int > > g[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(239);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= k; i++) {
        int a;
        cin >> a;
        need[a] = true;
        sz[a] = 1;
    }
    vector < pair < int, pair < int, int > > > edges;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(make_pair(w, make_pair(u, v)));
    }
    sort(edges.begin(), edges.end());
    for (auto t : edges) {
        int u = t.second.first;
        int v = t.second.second;
        int we = t.first;
        if (unite(u, v)) {
            if (sz[get(u)] == k) {
                for (int i = 1; i <= k; i++) cout << we << " ";
                return 0;
            }
        }
    }
    return 0;
}
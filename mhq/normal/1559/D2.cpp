#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
int n, m1, m2;
vector<int> g[2][maxN];
int m[2];
int p[2][maxN];
int sz[2][maxN];
set<pair<int,int>> small[2];
int get(int x, int a) {
    if (p[x][a] == a) return p[x][a];
    return p[x][a] = get(x, p[x][a]);
}
bool unite(int a, int b, int z) {
    a = get(z, a);
    b = get(z, b);
    if (a == b) return false;
    if (sz[z][a] < sz[z][b]) {
        swap(a, b);
    }
    p[z][b] = a;

    small[z].erase(make_pair(sz[z][a], a));
    small[z].erase(make_pair(sz[z][b], b));
    sz[z][a] += sz[z][b];
    small[z].insert(make_pair(sz[z][a], a));
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m[0] >> m[1];
    for (int i = 0; i < 2; i++) {
        for (int x = 1; x <= n; x++) {
            p[i][x] = x;
            sz[i][x] = 1;
            small[i].insert(make_pair(sz[i][x], x));
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int x = 0; x < m[i]; x++) {
            int a, b;
            cin >> a >> b;
            unite(a, b, i);
        }
    }
    mt19937 rnd((int)(chrono::steady_clock::now().time_since_epoch().count()));
    vector<pair<int,int>> edges;
    for (int i = 1; i <= n; i++) {
        if (get(0, i) != get(0, 1) && get(1, i) != get(1, 1)) {
            edges.emplace_back(1, i);
            unite(1, i, 0);
            unite(1, i, 1);
            m[0]++;
            m[1]++;
        }
    }
    int x = -1;
    for (int i = 2; i <= n; i++) {
        if (get(0, i) != get(0, 1)) {
            x = i;
            break;
        }
    }
    if (x != -1) {
        for (int i = 1; i <= n; i++) {
            if (get(0, i) != get(0, x) && get(1, i) != get(1, x)) {
                edges.emplace_back(x, i);
                unite(x, i, 0);
                unite(x, i, 1);
                m[0]++;
                m[1]++;
            }
        }
    }
    int y = -1;
    for (int i = 1; i <= n; i++) {
        if (get(1, 1) != get(1, i)) {
            y = i;
            break;
        }
    }
    if (y != -1) {
        for (int i = 1; i <= n; i++) {
            if (get(0, i) != get(0, y) && get(1, i) != get(1, y)) {
                edges.emplace_back(y, i);
                unite(y, i, 0);
                unite(y, i, 1);
                m[0]++;
                m[1]++;
            }
        }
    }
    while (m[0] < n - 1 && m[1] < n - 1) {
        int a = rnd() % n + 1;
        int b = rnd() % n + 1;
        if (get(0, a) != get(0, b) && get(1, a) != get(1, b)) {
            edges.emplace_back(a, b);
            unite(a, b, 0);
            unite(a, b, 1);
            m[0]++;
            m[1]++;
        }
        a = small[0].begin()->second;
        b = rnd() % n + 1;
        if (get(0, a) != get(0, b) && get(1, a) != get(1, b)) {
            edges.emplace_back(a, b);
            unite(a, b, 0);
            unite(a, b, 1);
            m[0]++;
            m[1]++;
        }
        a = small[1].begin()->second;
        b = rnd() %  n + 1;
        if (get(0, a) != get(0, b) && get(1, a) != get(1, b)) {
            edges.emplace_back(a, b);
            unite(a, b, 0);
            unite(a, b, 1);
            m[0]++;
            m[1]++;
        }
    }
    cout << edges.size() << '\n';
    for (auto& it : edges) {
        cout << it.first << " " << it.second << '\n';
    }
    return 0;
}
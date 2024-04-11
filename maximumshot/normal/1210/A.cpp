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

const int N = 10;

int n, m;
int g[N][N];
int val[N];
int res = 0;
vector<pii> edges;
int used[N][N];
int cnt = 0;

void rec(int i) {
    if (i == n + 1) {
        cnt++;
        fill((int*) used, (int*) used + N * N, 0);
        for (pii e : edges) {
            int u, v;
            tie(u, v) = e;
            if (val[u] > val[v]) swap(u, v);
            used[val[u]][val[v]] = 1;
        }
        int tmp = 0;
        for (int x = 1; x <= 6; x++) {
            for (int y = x; y <= 6; y++) {
                tmp += used[x][y];
            }
        }
        res = max(res, tmp);
//        if (tmp == res) {
//            cout << tmp << " " << res << "\n";
//        }
        return;
    }
    for (int x = 1; x <= 6; x++) {
        val[i] = x;
        rec(i + 1);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
        edges.emplace_back(u, v);
    }

    rec(1);
    cout << res << "\n";

    return 0;
}
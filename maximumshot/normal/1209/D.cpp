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

const int N = 1e5 + 5;

int n, k;
vector<int> g[N];
int color[N];

void dfs(int v, int cl) {
    color[v] = cl;
    for (int to : g[v]) {
        if (!color[to]) {
            dfs(to, cl);
        }
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int u, v, i = 0; i < k; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int cl = 0;

    for (int v = 1; v <= n; v++) {
        if (color[v]) continue;
        cl++;
        dfs(v, cl);
    }

    int res = n - cl;
    res = k - res;

    cout << res << "\n";

    return 0;
}
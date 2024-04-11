#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 3e5 + 5;

int n, m;
vector<int> g[N];
int color[N];

bool check() {
    int cnt[4] {0, 0, 0, 0};
    for (int v = 1; v <= n; v++) {
        cnt[color[v]]++;
    }
    if (1ll * cnt[1] * cnt[2] + 1ll * cnt[1] * cnt[3] + 1ll * cnt[2] * cnt[3] != m) {
        return false;
    }
    for (int v = 1; v <= n; v++) {
        for (int to : g[v]) {
            if (color[v] == color[to]) {
                return false;
            }
        }
    }
    return true;
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
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
        g[i].push_back(n + 1);
    }

    for (int iter = 1; iter <= 3; iter++) {
        int s = -1;
        for (int i = 1; i <= n; i++) {
            if (color[i]) continue;
            s = i;
            break;
        }
        if (s == -1) {
            cout << "-1\n";
            return 0;
        }
        color[s] = iter;
        for (int i = 0; i < (int) g[s].size(); i++) {
            int l = i ? g[s][i - 1] + 1 : 1;
            int r = g[s][i] - 1;
            for (int u = l; u <= r; u++) {
                if (color[u]) continue;
                color[u] = iter;
            }
        }
    }

    if (check()) {
        for (int i = 1; i <= n; i++) {
            cout << color[i] << " ";
        }
        cout << "\n";
    } else {
        cout << "-1\n";
        return 0;
    }

    return 0;
}
#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using ull = uint64_t;

using namespace std;

const int MAXN = 628;

vector<int> e[MAXN];
int p[MAXN];
int ls[MAXN];
bool w[MAXN];

bool dfs(int v) {
    if (v == 0) {
        return true;
    }

    if (w[v]) {
        return false;
    }

    w[v] = true;

    for (int u: e[v]) {
        if (dfs(p[u])) {
            p[u] = v;
            return true;
        }
    }

    return false;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        ls[i] = 0;
        e[i].clear();
    }

    
    for (int i = 0; i < m; ++i) {
        p[i] = 0;
        int a, b;
        cin >> a >> b;
        e[a].push_back(i);
        e[b].push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        int cn = max(0, int(e[i].size()) - k);
        for (int j = 0; j < 2 * cn; ++j) {
            fill(w, w + n + 1, false);
            if (!dfs(i)) {
                for (int l = 0; l < m; ++l) {
                    cout << 0 << " ";
                }

                cout << "\n";
                return;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        int x = p[i];
        if (ls[x]) {
            cout << ls[x] << " ";
            ls[x] = 0;
        } else {
            cout << i + 1 << " ";
            if (x) {
                ls[x] = i + 1;
            }
        }
    }

    cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
	return 0;
}
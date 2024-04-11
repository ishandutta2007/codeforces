#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> g(n);
        vector<int> deg(n);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            --a; --b;
            g[a].emplace_back(b);
            g[b].emplace_back(a);
            deg[a]++; deg[b]++;
        }
        for (int i = 0; i < n; i++) {
            sort(g[i].begin(), g[i].end());
        }
        vector<bool> used(n), inQ(n);
        vector<int> Q(n);
        int topQ = 0;
        vector<int> vert(k);
        bool fnd = false;
        for (int i = 0; i < n; i++) {
            used[i] = inQ[i] = false;
            if (deg[i] < k) {
                inQ[i] = true;
                Q[topQ++] = i;
            }
        }
        for (int i = 0; i < topQ; i++) {
            int u = Q[i];
            used[u] = true;
            inQ[u] = false;
            if (deg[u] < (k - 1)) {
                for (int j : g[u]) {
                    if (!used[j]) --m;
                    deg[j]--;
                    if (!inQ[j] && !used[j] && deg[j] < k) {
                        inQ[j] = true;
                        Q[topQ++] = j;
                    }
                }
                continue;
            }
            else if (deg[u] == k - 1) {
                if ((long long)k * (k - 1)  <= 2 * (long long)m) {
                    int r = 0;
                    for (int p : g[u]) {
                        if (!used[p]) {
                            vert[r++] = p;
                        }
                    }
                    assert (r == (k - 1));
                    bool good = true;
                    for (int x = 0; x < r; x++) {
                        if (!good) break;
                        for (int y = x + 1; y < r; y++) {
                            int pp = lower_bound(g[vert[x]].begin(), g[vert[x]].end(), vert[y]) - g[vert[x]].begin();
                            if (pp == g[vert[x]].size() || g[vert[x]][pp] != vert[y]) {
                                good = false;
                                break;
                            }
                        }
                    }
                    if (good) {
                        fnd = true;
                        cout << 2 << '\n';
                        cout << u + 1 << " ";
                        for (int c = 0; c < r; c++) {
                            cout << vert[c] + 1 << " ";
                        }
                        cout << '\n';
                        break;
                    }
                }
            }
            for (int j : g[u]) {
                deg[j]--;
                if (!used[j]) --m;
                if (!inQ[j] && !used[j] && deg[j] < k) {
                    inQ[j] = true;
                    Q[topQ++] = j;
                }
            }
        }
        if (fnd) continue;
        vector<int> f;
        for (int i = 0; i < n; i++) {
            if (!used[i]) f.emplace_back(i);
        }
        if (!f.empty()) {
            cout << 1 << " " << f.size() << '\n';
            for (int c : f) {
                c++;
                cout << c << " ";
            }
            cout << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 1005, K = 100005;

int n, m, k, u, v, col[K], val[K];
vector<int> cx[N], cy[N], adj[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cx[i] = vector<int>(N, 0);
    }
    for (int i = 1; i <= m; i++) {
        cy[i] = vector<int>(N, 0);
    }
    for (int i = 1; i <= k; i++) {
        cin >> u >> v;
        val[i] = u ^ v;
        adj[u].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end(), [&](const int &u, const int &v) {
            return (val[u] ^ i) < (val[v] ^ i);
        });
        for (int &u : adj[i]) {
            int x = i, y = val[u] ^ i, ind = u, ox = 0, oy = 0;
            for (int i = 0; i < (int)cx[x].size(); i++) {
                if (cx[x][i] == 0) {
                    ox = i;
                    break;
                }
            }
            for (int i = 0; i < (int)cy[y].size(); i++) {
                if (cy[y][i] == 0) {
                    oy = i;
                    break;
                }
            }
            for (bool hor = true; ; hor = !hor) {
                if (hor) {
                    col[ind] = ox + 1; cx[x][ox] = ind;
                    if (cy[y][ox] == 0) {
                        cy[y][ox] = ind;
                        break;
                    } else {
                        cx[val[cy[y][ox]] ^ y][ox] = 0;
                        swap(ind, cy[y][ox]);
                        x = val[ind] ^ y;
                    }
                } else {
                    col[ind] = oy + 1; cy[y][oy] = ind;
                    if (cx[x][oy] == 0) {
                        cx[x][oy] = ind;
                        break;
                    } else {
                        cy[val[cx[x][oy]] ^ x][oy] = 0;
                        swap(ind, cx[x][oy]);
                        y = val[ind] ^ x;
                    }
                }
            }
        }
    }
    cout << *max_element(col + 1, col + k + 1) << '\n';
    for (int i = 1; i <= k; i++) {
        cout << col[i] << ' ';
    }
}
#include<bits/stdc++.h>
using namespace std;
const int N = 512;
char s[N][N];
int n, m;
int val[N][N];
const pair <int, int> d[] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void solve() {
    cin >> n >> m;
    for (int i = 0 ; i < n ; ++ i) {
        cin >> s[i];
    }
    vector <int> g[N * N];
    vector <int> bar;
    for (int i = 0 ; i < n ; ++ i) {
        for (int j = 0 ; j < m ; ++ j) {
            if (s[i][j] == 'X') {
                for (int k = 0 ; k < 4 ; ++ k) {
                    int dx = i + d[k].first, dy = j + d[k].second;
                    if (s[dx][dy] == '.') {
                        bar.emplace_back(dx * m + dy);
                    }
                }
            }
            if (int(bar.size()) % 2) {
                cout << "NO\n";
                return;
            }
            for (int k = 0 ; k < int(bar.size()) ; k += 2) {
                g[bar[k]].push_back(bar[k + 1]);
                g[bar[k + 1]].push_back(bar[k]);
            }
            bar.clear();
        }
    }
    /// we can prove that the graph made by this method is bipartite

    for (int i = 0 ; i < n ; ++ i)
    for (int j = 0 ; j < m ; ++ j) {
        queue <int> q;
        if (val[i][j]) continue;
        val[i][j] = 1;
        q.push(i * m + j);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int to : g[x]) {
                if (!val[to / m][to % m]) {
                    val[to / m][to % m] = val[x / m][x % m] ^ 5;
                    q.push(to);
                }
            }
        }
    }
    cout << "YES\n";

    for (int i = 0 ; i < n ; ++ i, cout << '\n')
    for (int j = 0 ; j < m ; ++ j) {
        if (s[i][j] == 'X') {
            val[i][j] = 0;
            for (int k = 0 ; k < 4 ; ++ k) {
                int u = i + d[k].first, v = j + d[k].second;
                if (s[u][v] == '.')
                    val[i][j] += val[u][v];
            }
        }
        cout << val[i][j] << ' ';
    }
}

int main() {
    solve();

}
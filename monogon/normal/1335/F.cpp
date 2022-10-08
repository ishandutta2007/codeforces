
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// label a robot by the cycle it enters and its position in the cycle
// label cell by (iteration, depth)
// backtrack if it finds a previous cycle

const int N = 1e6 + 5;
int t, n, m;
string s[N], c[N];
vector<vector<pair<int, int>>> vis;
int len[N];

map<char, int> drow = {{'U', -1}, {'D', 1}, {'L', 0}, {'R', 0}};
map<char, int> dcol = {{'U', 0}, {'D', 0}, {'L', -1}, {'R', 1}};

void dfs(int i, int j, int it, int d) {
    if(vis[i][j].first != -1) {
        if(vis[i][j].first == it) {
            len[it] = abs(d - vis[i][j].second);
            vis[i][j] = {it, 0};
        }
        return;
    }
    vis[i][j] = {it, d};
    int i2 = i + drow[s[i][j]], j2 = j + dcol[s[i][j]];
    dfs(i2, j2, it, d + 1);
    vis[i][j] = {vis[i2][j2].first, (vis[i2][j2].second + 1) % len[vis[i2][j2].first]};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        vis = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(m, {-1, -1}));
        for(int i = 0; i < n; i++) {
            cin >> c[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> s[i];
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dfs(i, j, i * m + j, 0);
            }
        }
        set<pair<int, int>> se, se2;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                se.insert(vis[i][j]);
                if(c[i][j] == '0') {
                    se2.insert(vis[i][j]);
                }
            }
        }
        cout << se.size() << ' ' << se2.size() << '\n';
    }
}
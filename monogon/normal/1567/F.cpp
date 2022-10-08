
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, 0, n) {
        cin >> s[i];
    }
    vector<vi> g(n * m);
    rep(i, 0, n) rep(j, 0, m) {
        vi ve;
        if(s[i][j] == 'X') {
            rep(d, 0, 4) {
                int x = i + dx[d];
                int y = j + dy[d];
                if(s[x][y] != 'X') {
                    ve.push_back(x * m + y);
                }
            }
            if(sz(ve) % 2 != 0) {
                cout << "NO\n";
                return 0;
            }
            if(sz(ve) == 2) {
                g[ve[0]].push_back(ve[1]);
                g[ve[1]].push_back(ve[0]);
            }else if(sz(ve) == 4) {
                g[ve[0]].push_back(ve[2]);
                g[ve[2]].push_back(ve[0]);
                g[ve[1]].push_back(ve[3]);
                g[ve[3]].push_back(ve[1]);
            }
        }
    }
    vi col(n * m);
    auto dfs = [&](auto dfs, int x, int c) -> void {
        col[x] = c;
        for(int y : g[x]) {
            if(col[y] == 0) {
                dfs(dfs, y, 5 - c);
            }
        }
    };
    rep(i, 0, n) rep(j, 0, m) {
        if(s[i][j] != 'X' && col[i * m + j] == 0) dfs(dfs, i * m + j, 1);
    }
    cout << "YES\n";
    rep(i, 0, n) rep(j, 0, m) {
        if(s[i][j] == 'X') {
            rep(d, 0, 4) {
                int x = i + dx[d];
                int y = j + dy[d];
                if(s[x][y] != 'X') {
                    col[i * m + j] += col[x * m + y];
                }
            }
        }
        cout << col[i * m + j] << ' ';
        if(j == m - 1) cout << '\n';
    }
}
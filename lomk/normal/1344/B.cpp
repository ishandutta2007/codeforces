/*input
3 3
###
...
...

4 5
....#
####.
.###.
.#...

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
void debug() {cerr << endl;} template<typename T, typename... Ts> void debug(const T& value, const Ts&... values) {cerr << value << ' ', debug(values...);}
#endif
const int N = 1005;

int n, m;
char a[N][N];
bool vis[N][N];
int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(pair<int, int> root) {
    queue<pair<int, int> > q;
    q.push(root); vis[root.fi][root.se] = true;
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        loop(i, 0, 3) {
            int ax = u.fi + dx[i];
            int ay = u.se + dy[i];
            if (1 <= ax && ax <= n && 1 <= ay && ay <= m && !vis[ax][ay] && a[ax][ay] == '#') {
                vis[ax][ay] = true;
                q.push({ax, ay});
            }
        }
    }
}

void quit() {
    cout << -1 << endl;
    exit(0);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    loop(i, 1, n) {
        loop(j, 1, m) {
            cin >> a[i][j];
        }
    }
    loop(i, 1, n) {
        vector<char> tmp(a[i] + 1, a[i] + m + 1);
        tmp.resize(distance(tmp.begin(), unique(tmp.begin(), tmp.end())));
        if (count(tmp.begin(), tmp.end(), '#') >= 2) quit();
    }
    loop(j, 1, m) {
        vector<char> tmp;
        loop(i, 1, n) tmp.push_back(a[i][j]);
        tmp.resize(distance(tmp.begin(), unique(tmp.begin(), tmp.end())));
        if (count(tmp.begin(), tmp.end(), '#') >= 2) quit();
    }
    int ans = 0;
    loop(i, 1, n) {
        loop(j, 1, m) {
            if (a[i][j] == '.') continue;
            if (!vis[i][j]) {
                ans++;
                bfs({i, j});
            }
        }
    }
    int empty_col = [&] {
        int ret = 0;
        loop(i, 1, n) {
            int cnt = 0;
            loop(j, 1, m) cnt += (a[i][j] == '#');
            ret += (cnt == 0);
        }
        return ret;
    }();
    int empty_row = [&] {
        int ret = 0;
        loop(j, 1, m) {
            int cnt = 0;
            loop(i, 1, n) cnt += (a[i][j] == '#');
            ret += (cnt == 0);
        }
        return ret;
    }();
    if ((empty_col == 0 && empty_row != 0) || (empty_col != 0 && empty_row == 0)) quit();
    cout << ans << endl;
}

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<bool>> a(500, vector<bool>(500, false));
    auto ins = [&](int x, int y) {
        return 0 <= x && x < 500 && 0 <= y && y < 500;
    };

    rep(i, 0, n) {
        int x, y;
        cin >> x >> y;
        a[x][y] = true;
    }
    vector<vector<bool>> a2(all(a));

    auto get = [&](int x, int y) -> bool {
        if(!ins(x, y)) return false;
        return a[x][y];
    };
    auto get2 = [&](int x, int y) -> bool {
        if(!ins(x, y)) return false;
        return a2[x][y];
    };
    auto adj = [&](int x, int y) -> vector<pii> {
        vector<pii> ve;
        ve.push_back({x - 1, y});
        ve.push_back({x + 1, y});
        if(x % 2 == 0) ve.push_back({x + 1, y - 1});
        else ve.push_back({x - 1, y + 1});
        return ve;
    };
    queue<pii> Q;
    rep(i, 0, 500) rep(j, 0, 500) {
        int cnt = 0;
        cnt += get(i - 1, j) + get(i + 1, j);
        if(i % 2 == 0) cnt += get(i + 1, j - 1);
        else cnt += get(i - 1, j + 1);
        if(!a[i][j] && cnt >= 2) {
            a[i][j] = true;
            Q.push({i, j});
        }
    }

    int moves = 0;
    while(!Q.empty()) {
        int i, j;
        tie(i, j) = Q.front(); Q.pop();
        vector<pii> ve;
        ve.push_back({i - 1, j});
        ve.push_back({i + 1, j});
        if(i % 2 == 0) ve.push_back({i + 1, j - 1});
        else ve.push_back({i - 1, j + 1});
        for(auto &pa : ve) {
            int x, y; tie(x, y) = pa;
            if(ins(x, y)) {
                int cnt = 0;
                cnt += get(x - 1, y) + get(x + 1, y);
                if(x % 2 == 0) cnt += get(x + 1, y - 1);
                else cnt += get(x - 1, y + 1);
                if(cnt >= 2 && !a[x][y]) {
                    a[x][y] = true;
                    Q.push({x, y});
                }
            }
        }
    }
    // a -> all filled, a2 -> original infected
    // cycle in a -> no solution
    vector<vector<bool>> vis(500, vector<bool>(500, false));
    bool cyc = false;
    bool checker = false;
    int perim = 0;
    auto dfs = [&](auto dfs, int x, int y, int px, int py) -> void {
        auto ve = adj(x, y);
        vis[x][y] = true;
        int c = 0;
        for(auto &pa : ve) {
            int xx, yy; tie(xx, yy) = pa;
            if(ins(xx, yy) && (xx != px || yy != py)) {
                if(vis[xx][yy]) {
                    cyc = true;
                }else if(a[xx][yy]) {
                    dfs(dfs, xx, yy, x, y);
                }
            }
            if(a2[x][y] != get2(xx, yy)) {
                c++;
            }
            if(a2[x][y] == 1 && get2(xx, yy) == 0) {
                perim++;
            }
        }
        if(c == 2) checker = false;
    };
    rep(i, 0, 500) rep(j, 0, 500) {
        if(a[i][j] && !vis[i][j]) {
            checker = true;
            perim = 0;
            dfs(dfs, i, j, i, j);
            moves += perim - 2;
            if(perim > 3)
                moves -= checker * 2;
        }
    }
    if(cyc) {
        cout << "SICK\n";
        return 0;
    }
    cout << "RECOVERED\n" << moves << '\n';
}
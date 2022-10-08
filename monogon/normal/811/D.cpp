
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// first horizontal move should only be done if safe in both directions
// same for vertical
// first horizontal move must be right, when we are in column 1
// first vertical move must be left, when we are in row 1

const int N = 105;
int n, m;
string s[N];
bool vis[N][N];
int dir[N][N];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
map<int, char> ma = {{0, 'L'}, {1, 'R'}, {2, 'U'}, {3, 'D'}};
map<int, int> oth = {{0, 1}, {1, 0}, {2, 3}, {3, 2}};
int x = 0, y = 0;

pii query(int d) {
    cout << ma[d] << endl;
    int x, y;
    cin >> x >> y;
    if(x == -1 && y == -1) exit(0);
    return {x - 1, y - 1};
}
void moveplayer(int d) {
    auto [x2, y2] = query(d);
    if(x2 != x + dx[d] || y2 != y + dy[d]) {
        swap(ma[d], ma[oth[d]]);
        tie(x2, y2) = query(d);
        assert(x2 == x + dx[d] && y2 == y + dy[d]);
    }
    x = x2;
    y = y2;
}

bool inbounds(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}
void dfs(int x, int y) {
    vis[x][y] = true;
    for(int d = 0; d < 4; d++) {
        if(inbounds(x + dx[d], y + dy[d]) && !vis[x + dx[d]][y + dy[d]] && s[x + dx[d]][y + dy[d]] != '*') {
            dir[x + dx[d]][y + dy[d]] = d;
            dfs(x + dx[d], y + dy[d]);
        }
    }
}

void solve(int x, int y) {
    if(x == 0 && y == 0) return;
    solve(x - dx[dir[x][y]], y - dy[dir[x][y]]);
    moveplayer(dir[x][y]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int fx = 0, fy = 0;
    rep(i, 0, n) {
        cin >> s[i];
        rep(j, 0, m) {
            if(s[i][j] == 'F') {
                fx = i;
                fy = j;
            }
        }
    }
    dfs(0, 0);
    solve(fx, fy);
}
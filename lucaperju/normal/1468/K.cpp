#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define pb push_back
#define dbg(x) cerr << #x << " " << x << "\n"

set <pair <int, int>> possible;
map <char, int> mp;
/// L R D U
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
void go (int x, int y, int step, string &op) {
    if (x || y)
        possible.insert ({x, y});
    if (step == op.size ())
        return;
    int dir = mp[op[step]];
    x += dx[dir];
    y += dy[dir];
    go (x, y, step + 1, op);
}

bool trythis (int x, int y, int step, pair <int, int> &obstacle, string &op) {
    if (step == op.size ())
        return (x == 0 && y == 0);
    int dir = mp[op[step]];
    x += dx[dir];
    y += dy[dir];
    if (x == obstacle.first && y == obstacle.second) {
        x -= dx[dir];
        y -= dy[dir];
    }
    return trythis (x, y, step + 1, obstacle, op);
}

int main () {
    ios::sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    mp['L'] = 0;
    mp['R'] = 1;
    mp['D'] = 2;
    mp['U'] = 3;
    int t;
    cin >> t;
    while (t--) {
        string op;
        cin >> op;
        go (0, 0, 0, op);
        pair <int, int> ans = {0, 0};
        for (pair <int, int> obstacle : possible) {
            if (trythis (0,  0, 0, obstacle, op))
                ans = obstacle;
        }
        cout << ans.second << " " << ans.first << "\n";
    }
    return 0;
}
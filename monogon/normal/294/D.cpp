
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
    int n, m, x, y;
    string dir;
    cin >> n >> m >> x >> y >> dir;
    int dx = 0, dy = 0;
    dx = (dir[0] == 'D') - (dir[0] == 'U');
    dy = (dir[1] == 'R') - (dir[1] == 'L');
    int cnt = 2 * n + 2 * m - 4;
    ll ans = 1, step = 0;
    set<pii> se;
    if(x == 1 || y == 1 || x == n || y == m) se.insert({x, y});
    rep(i, 0, 2 * cnt) {
        int t = INT_MAX;
        if(x == 1) dx = 1;
        if(x == n) dx = -1;
        if(y == 1) dy = 1;
        if(y == m) dy = -1;
        if(dx == -1) t = min(t, x - 1);
        else t = min(t, n - x);
        if(dy == -1) t = min(t, y - 1);
        else t = min(t, m - y);
        x += dx * t;
        y += dy * t;
        step += t;
        if(!se.count({x, y})) {
            ans += step;
            step = 0;
            se.insert({x, y});
        }
    }
    // cout << ans << '\n';
    if(sz(se) == cnt / 2 || sz(se) == (cnt + 1) / 2) {
        cout << ans << '\n';
    }else {
        cout << -1 << '\n';
    }
}
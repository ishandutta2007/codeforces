
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

const int N = 2005;
int n, m;
string s[N];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int dist[N][N];
bool vis[N][N];

bool ins(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> s[i];
    }
    queue<pii> Q;
    rep(i, 0, n) {
        rep(j, 0, m) {
            bool flag = true;
            rep(d, 0, 4) {
                int x = i + dx[d];
                int y = j + dy[d];
                flag &= (ins(x, y) && s[i][j] == s[x][y]);
            }
            if(!flag) {
                vis[i][j] = true;
                Q.emplace(i, j);
            }
        }
    }
    while(!Q.empty()) {
        int x, y;
        tie(x, y) = Q.front(); Q.pop();
        rep(d, 0, 4) {
            int xx = x + dx[d];
            int yy = y + dy[d];
            if(ins(xx, yy) && !vis[xx][yy]) {
                dist[xx][yy] = dist[x][y] + 1;
                vis[xx][yy] = true;
                Q.emplace(xx, yy);
            }
        }
    }
    ll ans = 0;
    rep(i, 0, n) rep(j, 0, m) ans += dist[i][j] + 1;
    cout << ans << '\n';
}
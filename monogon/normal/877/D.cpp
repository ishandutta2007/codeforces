
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

// check if in same component, else -1
// do BFS from a node, run in all 4 directions at most k steps, until you reach visited node
// complexity is still O(nm) even though it might not seem like it

const int N = 1005;
int n, m, k, r1, c1, r2, c2;
string s[N];
int dist[N][N];
bool vis[N][N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

bool inbounds(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    rep(i, 0, n) {
        cin >> s[i];
    }
    cin >> r1 >> c1 >> r2 >> c2;
    r1--; c1--; r2--; c2--;
    queue<pii> Q;
    vis[r1][c1] = true;
    Q.emplace(r1, c1);
    while(!Q.empty()) {
        auto [r, c] = Q.front(); Q.pop();
        if(r == r2 && c == c2) {
            cout << dist[r][c] << '\n';
            return 0;
        }
        rep(d, 0, 4) {
            rep(i, 1, k + 1) {
                int R = r + i * dx[d];
                int C = c + i * dy[d];
                if(!inbounds(R, C)) break;
                else if(s[R][C] == '#' || (vis[R][C] && dist[R][C] <= dist[r][c])) break;
                else if(vis[R][C]) continue;
                vis[R][C] = true;
                dist[R][C] = dist[r][c] + 1;
                Q.emplace(R, C);
            }
        }
    }
    cout << "-1\n";
}
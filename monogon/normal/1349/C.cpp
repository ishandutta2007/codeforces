
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

// for a cell, what time does it first change color? INT_MAX if never
// then it changes color every iteration from that point on

const int N = 1005;
int n, m, t, i, j;
ll p;
string s[N];
ll ti[N][N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool inbounds(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> t;
    rep(i, 0, n) {
        cin >> s[i];
    }
    deque<pii> Q;
    rep(i, 0, n) rep(j, 0, m) {
        ti[i][j] = LLONG_MAX;
        rep(d, 0, 4) {
            if(inbounds(i + dx[d], j + dy[d]) && s[i + dx[d]][j + dy[d]] == s[i][j]) {
                Q.emplace_back(i, j);
                ti[i][j] = 0;
                break;
            }
        }
    }
    while(!Q.empty()) {
        auto [x, y] = Q.front(); Q.pop_front();
        rep(d, 0, 4) {
            if(inbounds(x + dx[d], y + dy[d]) && ti[x + dx[d]][y + dy[d]] == LLONG_MAX) {
                if(s[x][y] == s[x + dx[d]][y + dy[d]]) {
                    ti[x + dx[d]][y + dy[d]] = ti[x][y];
                    Q.emplace_front(x + dx[d], y + dy[d]);
                }else {
                    ti[x + dx[d]][y + dy[d]] = ti[x][y] + 1;
                    Q.emplace_back(x + dx[d], y + dy[d]);
                }
            }
        }
    }

    while(t--) {
        cin >> i >> j >> p;
        i--; j--;
        if(p <= ti[i][j]) {
            cout << s[i][j] << '\n';
        }else {
            cout << (char) ('0' + ((s[i][j] - '0' + p - ti[i][j]) % 2)) << '\n';
        }
    }
}
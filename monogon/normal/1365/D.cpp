
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
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 55;
int t, n, m;
string s[N];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool inbounds(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int dfs(int x, int y) {
    int ans = (s[x][y] == 'G');
    s[x][y] = '#';
    rep(d, 0, 4) {
        int xx = x + dx[d];
        int yy = y + dy[d];
        if(inbounds(xx, yy) && s[xx][yy] != '#') {
            ans += dfs(xx, yy);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        int good = 0;
        rep(i, 0, n) {
            cin >> s[i];
            rep(j, 0, m) good += (s[i][j] == 'G');
        }
        rep(x, 0, n) rep(y, 0, m) {
            if(s[x][y] == 'B') {
                if(x == n - 1 && y == m - 1) {
                    cout << "No\n";
                    goto lab;
                }
                rep(d, 0, 4) {
                    int xx = x + dx[d];
                    int yy = y + dy[d];
                    if(inbounds(xx, yy)) {
                        if(s[xx][yy] == '.') s[xx][yy] = '#';
                        else if(s[xx][yy] == 'G') {
                            cout << "No\n";
                            goto lab;
                        }
                    }
                }
            }
        }
        if(s[n - 1][m - 1] != '#') good -= dfs(n - 1, m - 1);
        cout << (good == 0 ? "Yes" : "No") << '\n';
        lab:;
    }
}
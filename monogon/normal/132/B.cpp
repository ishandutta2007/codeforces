
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

// for all (i, j) store the index of the rectangle.
// state = (rectangle id, dir (0-4), block chooser (L/R))

const int N = 55, K = 5e7 + 5;
int n, m, k;
string s[N];
bool vis[N][N];

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int minr[N * N], maxr[N * N], minc[N * N], maxc[N * N], block[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    rep(i, 0, n) cin >> s[i];
    m = s[0].length();
    int cnt = 0;
    rep(i, 0, n) rep(j, 0, m) {
        if(!vis[i][j]) {
            int i2 = i, j2 = j;
            while(i2 < n && s[i2][j] == s[i][j]) i2++;
            while(j2 < m && s[i][j2] == s[i][j]) j2++;
            rep(ii, i, i2) rep(jj, j, j2) {
                vis[ii][jj] = true;
                block[ii][jj] = cnt;
            }
            minr[cnt] = i;
            minc[cnt] = j;
            maxr[cnt] = i2 - 1;
            maxc[cnt] = j2 - 1;
            cnt++;
        }
    }
    int b = 0, dp = 0, cp = 0;
    while(k--) {
        int i2 = 0, j2 = 0;
        switch(dp) {
        case RIGHT:
            j2 = maxc[b] + 1;
            i2 = (cp ? maxr[b] : minr[b]);
            break;
        case LEFT:
            j2 = minc[b] - 1;
            i2 = (cp ? minr[b] : maxr[b]);
            break;
        case UP:
            i2 = minr[b] - 1;
            j2 = (cp ? maxc[b] : minc[b]);
            break;
        case DOWN:
            i2 = maxr[b] + 1;
            j2 = (cp ? minc[b] : maxc[b]);
            break;
        }
        if(i2 < 0 || i2 >= n || j2 < 0 || j2 >= m || s[i2][j2] == '0') {
            if(cp) {
                dp = (dp + 1) % 4;
            }
            cp = !cp;
        }else {
            b = block[i2][j2];
        }
    }
    cout << s[minr[b]][minc[b]] << '\n';
}
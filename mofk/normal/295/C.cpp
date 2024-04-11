#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back
#define fi first
#define se second

typedef long long ll;
using namespace std;
typedef vector <int> vi;
typedef pair <ll, ll> ii;
typedef pair <ii, bool> iii;

const int mod = 1000000007;
int N, K, X, Y;
ll d[55][55][2], f[55][55][2];
bool g[55][55][2];
ll c[55][55];

#define that x][y][t

int main(void) {
    cin >> N >> K; K /= 50;
    ff(i, 0, N) c[i][0] = c[i][i] = 1;
    ff(i, 1, N) ff(j, 1, i - 1) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
    int w;
    ff(i, 1, N) { cin >> w; if (w == 50) ++X; else ++Y; }
    d[X][Y][0] = 0, f[X][Y][0] = 1; g[X][Y][0] = 1;
    queue <iii> q; q.push(iii(ii(X, Y), 0));
    while (!q.empty()) {
        int x = q.front().fi.fi, y = q.front().fi.se, t = q.front().se;
        q.pop();
        ff(i, 0, x) ff(j, 0, y) if (i + j && i + 2 * j <= K) {
            int nx = X - x + i, ny = Y - y + j;
            if (g[nx][ny][!t]) {
                if (d[nx][ny][!t] == d[that] + 1) f[nx][ny][!t] = (f[nx][ny][!t] + f[that] * c[x][i] % mod * c[y][j] % mod) % mod;
            }
            else {
                g[nx][ny][!t] = 1;
                d[nx][ny][!t] = d[that] + 1;
                f[nx][ny][!t] = f[that] * c[x][i] % mod * c[y][j] % mod;
                q.push(iii(ii(nx, ny), !t));
            }
        }
    }
    if (!g[X][Y][1]) return cout << -1 << endl << 0 << endl, 0;
    cout << d[X][Y][1] << endl << f[X][Y][1] << endl;
    return 0;
}
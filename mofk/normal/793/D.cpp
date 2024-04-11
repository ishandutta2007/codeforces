#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

const int oo = 1000000000;
int N, K, M;
int dist[85][85];
int f[85][85][85][2];
int best1[85][85][85];
int best2[85][85][85];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K >> M;
    int u, v, w;
    ff(i, 1, N) ff(j, 1, N) dist[i][j] = oo;
    ff(i, 1, M) cin >> u >> v >> w, dist[u][v] = min(dist[u][v], w);
    if (K == 1) return cout << 0 << endl, 0;
    ff(i, 1, N) ff(l, 0, i - 1) ff(r, i + 1, N + 1) f[l][r][i][1] = oo;
    ff(l, 0, N + 1) ff(r, 0, N + 1) best1[l][r][1] = best2[l][r][1] = oo;
    ff(i, 1, N) f[0][N+1][i][1] = 0, best1[N+1][i][1] = 0, best2[0][i][1] = 0;
    int ans = oo;
    ff(k, 2, K) {
        ff(l, 0, N + 1) ff(r, 0, N + 1) best1[l][r][k] = best2[l][r][k] = oo;
        ff(i, 1, N) ff(l, 0, i - 1) ff(r, i + 1, N + 1) {
            f[l][r][i][k&1] = oo;
            if (dist[l][i] < oo) f[l][r][i][k&1] = min(f[l][r][i][k&1], best1[r][l][k-1] + dist[l][i]);
            if (dist[r][i] < oo) f[l][r][i][k&1] = min(f[l][r][i][k&1], best2[l][r][k-1] + dist[r][i]);
            best1[r][i][k] = min(best1[r][i][k], f[l][r][i][k&1]);
            best2[l][i][k] = min(best2[l][i][k], f[l][r][i][k&1]);
            if (k == K) ans = min(ans, f[l][r][i][k&1]);
        }
    }
    if (ans == oo) ans = -1;
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

struct data {
    int R, C, D, V;
    data() {}
    data(int r, int c, int d, int v) { R = r, C = c, D = d, V = v; }
};
const int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int N, M;
char s[1005][1005];
bool can[1005][1005][5][5];
queue <data> q;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    ff(i, 0, N - 1) cin >> s[i];
    ff(i, 0, N - 1) ff(j, 0, M - 1) if (s[i][j] == 'S') q.push(data(i, j, 4, 0)), can[i][j][4][0] = 1;
    data u, nu;
    int r, c, d, v;
    while (!q.empty()) {
        u = q.front(); q.pop();
        r = u.R, c = u.C, d = u.D, v = u.V;
        if (s[r][c] == 'T') return cout << "YES" << endl, 0;
        ff(i, 0, 3) {
            int nr = r + dx[i], nc = c + dy[i];
            if (nr < 0 || nr >= N || nc < 0 || nc >= M || s[nr][nc] == '*') continue;
            nu = data(nr, nc, i, v + (i != d));
            if (nu.V > 3) continue;
            if (!can[nu.R][nu.C][nu.D][nu.V]) {
                can[nu.R][nu.C][nu.D][nu.V] = 1;
                q.push(nu);
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int mod = 1000000007;
const int dy[2] = {-1, 1};
const int dx[2] = {-1, 1};

int T;
int n, m, rb, cb, rd, cd, p;
int notp;
vector <vector <vector <ii> > > V[2][2];

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int a) { return toPower(a, mod - 2); }

int Get(const vector <ii> &V)
{
    int a = V[0].first, b = V[0].second;
    int c = (V[1].first - a), d = (V[1].second - b);
    int B = toPower(notp, b);
    int D = toPower(notp, d);
    int notD = (1 - D + mod) % mod;
    int inotD = Inv(notD);
    return (ll(B) * p % mod * a % mod * inotD % mod + ll(B) * D % mod * p % mod * c % mod * inotD % mod * inotD) % mod;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d %d %d %d", &n, &m, &rb, &cb, &rd, &cd, &p);
        p = ll(p) * Inv(100) % mod;
        notp = (1 - p + mod) % mod;
        rb--; cb--; rd--; cd--;
        for (int x = 0; x < 2; x++)
            for (int y = 0; y < 2; y++) {
                V[x][y].resize(n);
                for (int i = 0; i < n; i++) {
                    V[x][y][i].resize(m);
                    for (int j = 0; j < m; j++)
                        V[x][y][i][j].clear();
                }
            }
        int res = 0;
        int x = 1, y = 1;
        int r = rb, c = cb;
        int t = 0, f = 0;
        while (true) {
            if (r + dx[x] < 0 || r + dx[x] >= n) x = 1 - x;
            if (c + dy[y] < 0 || c + dy[y] >= m) y = 1 - y;
            if (V[x][y][r][c].size() >= 2) break;
            V[x][y][r][c].push_back(ii(t, f));
            if (V[x][y][r][c].size() == 2 && (r == rd || c == cd))
                res = (res + Get(V[x][y][r][c])) % mod;
            t++;
            if (r == rd || c == cd) f++;
            r += dx[x];
            c += dy[y];
        }
        printf("%d\n", res);
    }
    return 0;
}
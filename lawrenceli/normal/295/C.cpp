#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <queue>
#include <cstring>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 55;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int n, k, num[2], comb[MAXN][MAXN];
pii dp[MAXN][MAXN][2]; //num 50, num 100, side of boat
int ord[MAXN][MAXN][2];

struct data {
    int a, b, c;
    data() {}
    data(int a, int b, int c) : a(a), b(b), c(c) {}
};
queue<data> que;

pii calc(int a, int b, int c) {
    if (dp[a][b][c].fi != -1) return dp[a][b][c];
    if (a == num[0] && b == num[1] && c == 1) return dp[a][b][c] = pii(0, 1);

    dp[a][b][c] = pii(INF, 0);
    for (int i=0; i<=a; i++)
        for (int j=0; j<=b; j++) {
            if (!(i + j)) continue;
            if (i*50 + j*100 > k) continue;
            if (ord[num[0] - a + i][num[1] - b + j][c^1] <= ord[a][b][c]) continue;
            ll mult = ll(comb[a][i]) * comb[b][j] % MOD;
            pii p = calc(num[0] - a + i, num[1] - b + j, c^1);
            if (p.fi + 1 < dp[a][b][c].fi)
                dp[a][b][c] = pii(p.fi + 1, mult * p.se % MOD);
            else if (p.fi + 1 == dp[a][b][c].fi)
                dp[a][b][c].se = (dp[a][b][c].se + mult * p.se % MOD) % MOD;
        }

    return dp[a][b][c];
}

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    cin >> n >> k;
    for (int i=0; i<n; i++) {
        int w; cin >> w;
        if (w == 50) num[0] ++;
        else num[1] ++;
    }

    comb[0][0] = 1;
    for (int i=1; i<MAXN; i++)
        for (int j=0; j<MAXN; j++) {
            if (j == 0) comb[i][j] = 1;
            else comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
        }

    memset(ord, -1, sizeof(ord));
    que.push(data(num[0], num[1], 0));

    for (int t=0; !que.empty(); t++) {
        int sze = que.size();
        for (int ii=0; ii<sze; ii++) {
            data d = que.front(); que.pop();
            if (ord[d.a][d.b][d.c] != -1) continue;
            ord[d.a][d.b][d.c] = t;
            for (int i=0; i<=d.a; i++)
                for (int j=0; j<=d.b; j++) {
                    if (!(i+j)) continue;
                    if (i*50 + j*100 > k) continue;
                    que.push(data(num[0]-d.a+i, num[1]-d.b+j, d.c^1));
                }
        }
    }

    for (int i=0; i<MAXN; i++)
        for (int j=0; j<MAXN; j++)
            for (int k=0; k<2; k++)
                dp[i][j][k].fi = -1;

    pii p = calc(num[0], num[1], 0);
    if (p.fi == INF) cout << "-1\n0\n";
    else cout << p.fi << endl << p.se << endl;

    return 0;
}
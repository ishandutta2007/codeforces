#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxd = 64;
const int mod = 998244353;
const int Maxn = 1005;
const int Maxb = 31;
const int Maxc = 3;

struct matrix {
    int m[Maxd][Maxd];
    matrix(int diag = 0) {
        for (int i = 0; i < Maxd; i++)
            for (int j = 0; j < Maxd; j++)
                m[i][j] = (i == j) * diag;
    }
    matrix operator *(const matrix &b) const {
        matrix c;
        for (int i = 0; i < Maxd; i++)
            for (int j = 0; j < Maxd; j++)
                for (int k = 0; k < Maxd; k++)
                    c.m[i][j] = (c.m[i][j] + ll(m[i][k]) * b.m[k][j]) % mod;
        return c;
    }
};

int n;
int a[Maxn];
int m;
vector <ii> seq[Maxn];
int al[Maxc][Maxc];
int my[Maxd][Maxc];
matrix M[Maxb];
vector <int> mystates[4];
int cur;
int col[2][Maxd];
int ways[Maxn][4];
int dp[Maxn][1 << 4];

int getId(const vector <int> &V)
{
    int res = 0;
    for (int i = 0; i < V.size(); i++)
        res = res * 4 + V[i];
    return res;
}

int getNew(const vector <int> &V, int col)
{
    int mask = 0;
    for (int i = 0; i < Maxc; i++) if (al[col][i])
        mask |= 1 << V[i];
    int res = 0;
    while (mask & 1 << res) res++;
    return getId({res, V[0], V[1]});
}

void Clear()
{
    for (int i = 0; i < Maxd; i++)
        col[cur][i] = 0;
    col[cur][getId({3, 3, 3})] = 1;
}

void moveOne(int c)
{
    for (int i = 0; i < Maxd; i++) {
        col[!cur][my[i][c]] = (col[!cur][my[i][c]] + col[cur][i]) % mod;
        col[cur][i] = 0;
    }
    cur = !cur;
}

void moveBy(const matrix &M)
{
    for (int j = 0; j < Maxd; j++) {
        for (int i = 0; i < Maxd; i++)
            col[!cur][i] = (col[!cur][i] + ll(col[cur][j]) * M.m[i][j]) % mod;
        col[cur][j] = 0;
    }
    cur = !cur;
}

void Move(int len)
{
    for (int i = Maxb - 1; i >= 0; i--) if (1 << i <= len) {
        moveBy(M[i]);
        len -= 1 << i;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int x, y, c; scanf("%d %d %d", &x, &y, &c);
        seq[x].push_back(ii(y, c - 1));
    }
    for (int i = 0; i < Maxc; i++)
        for (int j = 0; j < Maxc; j++)
            scanf("%d", &al[i][j]);
    for (int a = 0; a < 4; a++)
        for (int b = 0; b < 4; b++)
            for (int c = 0; c < 4; c++) {
                mystates[a].push_back(getId({a, b, c}));
                for (int d = 0; d < Maxc; d++)
                    my[getId({a, b, c})][d] = getNew({a, b, c}, d);
            }
    for (int i = 0; i < Maxd; i++)
        for (int j = 0; j < Maxc; j++)
            M[0].m[my[i][j]][i]++;
    for (int i = 1; i < Maxb; i++)
        M[i] = M[i - 1] * M[i - 1];
    for (int i = 1; i <= n; i++) {
        sort(seq[i].begin(), seq[i].end());
        Clear();
        int nxt = 1;
        for (int j = 0; j < seq[i].size(); j++) {
            if (nxt < seq[i][j].first) Move(seq[i][j].first - nxt);
            moveOne(seq[i][j].second);
            nxt = seq[i][j].first + 1;
        }
        if (nxt <= a[i]) Move(a[i] - nxt + 1);
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < mystates[j].size(); k++)
                ways[i][j] = (ways[i][j] + col[cur][mystates[j][k]]) % mod;
    }
    dp[1][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 1 << 4; j++) if (dp[i][j])
            for (int k = 0; k < 4; k++) {
                int nj = (j ^ k);
                dp[i + 1][nj] = (dp[i + 1][nj] + ll(dp[i][j]) * ways[i][k]) % mod;
            }
    printf("%d\n", dp[n + 1][0]);
    return 0;
}
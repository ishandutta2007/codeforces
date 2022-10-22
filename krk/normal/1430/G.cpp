#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000007;
const int Maxm = 19;
const int Maxn = 18;

int n, m;
int neigh[Maxm];
bool tk[Maxm];
int val[Maxm];
vector <int> seq;
int dp[Maxm][Maxm][1 << Maxn];
bool par[Maxm][Maxm][1 << Maxn];
int res[Maxm];

void topSort(int v)
{
    if (tk[v]) return;
    tk[v] = true;
    for (int i = 0; i < n; i++)
        if (neigh[v] & 1 << i) {
            topSort(i);
            neigh[v] |= neigh[i];
        }
    seq.push_back(v);
}

void getAns()
{
    int i = n, j = 0, k = (1 << n) - 1;
    while (k) {
        bool tk = par[i][j][k];
        j--;
        if (j < 0) { i--; j = n - 1; }
        if (tk) {
            res[seq[j]] = i;
            k ^= 1 << seq[j];
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y, w; scanf("%d %d %d", &x, &y, &w);
        x--; y--;
        val[x] += w;
        val[y] -= w;
        neigh[x] |= 1 << y;
    }
    for (int i = 0; i < n; i++)
        topSort(i);
    reverse(seq.begin(), seq.end());
    fill((int*)dp, (int*)dp + Maxm * Maxm * (1 << Maxn), Inf);
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < 1 << n; k++) if (dp[i][j][k] < Inf) {
                int v = seq[j];
                int ni = i, nj = j + 1;
                if (nj >= n) { ni++; nj = 0; }
                if (dp[i][j][k] < dp[ni][nj][k]) {
                    dp[ni][nj][k] = dp[i][j][k];
                    par[ni][nj][k] = false;
                }
                if (!(k & 1 << v) && (k & neigh[v]) == neigh[v]) {
                    int nk = (k | 1 << v);
                    int cand = dp[i][j][k] + val[v] * i;
                    if (cand < dp[ni][nj][nk]) {
                        dp[ni][nj][nk] = cand;
                        par[ni][nj][nk] = true;
                    }
                }
            }
    getAns();
    for (int i = 0; i < n; i++)
        printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    return 0;
}
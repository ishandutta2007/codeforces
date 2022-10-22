#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxd = 4005;

int G[Maxd][Maxd];
int W, H;
int pos[2][2];
int un[2][2];
int all[2][2];
int res;

int Md(int x) { return x % 2? 1: 0; }

int Get(int A[][2], int a, int b)
{
    int res = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if ((b * i - a * j) % 2 == 0)
                res = (res + A[i][j]) % mod;
    return res;
}

int main()
{
    for (int i = 0; i < Maxd; i++)
        G[i][0] = G[0][i] = i;
    for (int i = 1; i < Maxd; i++)
        for (int j = 1; j < Maxd; j++)
            if (i >= j) G[i][j] = G[i - j][j];
            else G[i][j] = G[i][j - i];
    cin >> W >> H;
    for (int i = -H; i <= H; i++)
        for (int j = i; j - i <= H; j++) if (max(j, 0) - min(i, 0) <= H && (i != 0 || j != 0)) {
            int tims = H + 1 - (max(j, 0) - min(i, 0));
            if (i > 0) pos[Md(i)][Md(j)] = (pos[Md(i)][Md(j)] + tims) % mod;
            if (j > 0 && i != j) pos[Md(j)][Md(i)] = (pos[Md(j)][Md(i)] + tims) % mod;
            if (i != j) un[Md(i)][Md(j)] = (un[Md(i)][Md(j)] + tims) % mod;
            all[Md(i)][Md(j)] = (all[Md(i)][Md(j)] + tims) % mod;
        }
    for (int i = 1; i <= W; i++) {
        int tims = W + 1 - i;
        res = (res + ll(tims) * Get(pos, 0, i)) % mod;
    }
    for (int i = 1; i <= W; i++) {
        int tims = W + 1 - i;
        res = (res + ll(tims) * Get(un, i, i)) % mod;
        for (int j = i + 1; j <= W; j++) {
            tims = W + 1 - j;
            res = (res + ll(Get(all, i, j) + Get(un, j, i)) * tims) % mod;
        }
    }
    for (int i = 1; i <= W; i++)
        for (int j = 1; j <= H; j++) {
            int tims = 2ll * (W + 1 - i) % mod * (H + 1 - j) % mod * (G[i][j] - 1) % mod;
            res = (res - tims + mod) % mod;
        }
    res = ll(res) * 6ll % mod;
    printf("%d\n", res);
    return 0;
}
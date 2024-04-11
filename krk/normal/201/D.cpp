#include <bits/stdc++.h>
using namespace std;

const int Maxn = 15;
const int Maxm = 106;
const int Maxk = 500025;
const int Inf = 1000000000;

char tmp[Maxk];
int bits[1 << Maxn];
int n;
map <string, int> M;
int m;
string my[Maxk];
int nxt[Maxk][Maxn];
int dp[1 << Maxn][Maxm];
int best, wth = -1;

string Read()
{
    scanf("%s", tmp);
    return tmp;
}

int Get(const string &s)
{
    auto it = M.find(s);
    return it == M.end()? -1: it->second;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 1 << n; i++)
        bits[i] = __builtin_popcount(i);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        M[Read()] = i;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int sz; scanf("%d", &sz);
        for (int j = 0; j < sz; j++)
            my[j] = Read();
        fill(nxt[sz], nxt[sz] + n, Inf);
        for (int j = sz - 1; j >= 0; j--) {
            int val = Get(my[j]);
            for (int k = 0; k < n; k++)
                nxt[j][k] = val == k? j: nxt[j + 1][k];
        }
        fill((int*)dp, (int*)dp + (1 << Maxn) * Maxm, Inf);
        dp[0][0] = 0;
        for (int mask = 0; mask < 1 << n; mask++)
            for (int j = 0; j < Maxm; j++) if (dp[mask][j] < Inf)
                for (int k = 0; k < n; k++) if (!(mask & 1 << k) && nxt[dp[mask][j]][k] < sz) {
                    int nmask = mask | 1 << k;
                    int nj = j + bits[(~mask & ((1 << k) - 1))];
                    int val = nxt[dp[mask][j]][k] + 1;
                    dp[nmask][nj] = min(dp[nmask][nj], val);
                }
        int ans = 0;
        while (ans < Maxm && dp[(1 << n) - 1][ans] >= Inf) ans++;
        if (ans >= Maxm) continue;
        ans = n * (n - 1) / 2 - ans + 1;
        if (ans > wth) {
            wth = ans;
            best = i;
        }
    }
    if (wth == -1) printf("Brand new problem!\n");
    else {
        printf("%d\n", best + 1);
        printf("[:");
        while (wth--) printf("|");
        printf(":]\n");
    }
    return 0;
}
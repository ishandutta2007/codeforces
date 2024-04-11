#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10005;
const int Inf = 1000000000;

char S[Maxn];
int slen;
int pnt;
char T[Maxn];
int tlen;
int glob[Maxn];
int dp[Maxn][Maxn];

void processBad(int dp[])
{
    for (int i = 0; i <= tlen; i++)
        dp[i]++;
}

void processGood(int ind, int par[], int cur[])
{
    for (int i = tlen; i >= 0; i--) {
        cur[i] = par[i] + 1;
        if (i > 0 && S[ind] == T[i - 1])
            cur[i] = min(cur[i], par[i - 1]);
    }
    bool mn = false;
    while (pnt < slen)
        if (S[pnt++] == '.') {
            processBad(cur);
            mn = true;
            break;
        } else processGood(pnt - 1, cur, dp[pnt]);
    for (int i = 0; i <= tlen; i++)
        par[i] = mn? min(par[i], cur[i]): cur[i];
}

void Solve()
{
    while (pnt < slen)
        if (S[pnt++] == '.') processBad(glob);
        else processGood(pnt - 1, glob, dp[pnt]);
}

int main()
{
    scanf("%s", S); slen = strlen(S);
    scanf("%s", T); tlen = strlen(T);
    fill(glob, glob + Maxn, Inf);
    glob[0] = 0;
    Solve();
    printf("%d\n", glob[tlen]);
    return 0;
}
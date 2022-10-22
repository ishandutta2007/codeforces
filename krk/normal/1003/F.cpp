#include <bits/stdc++.h>
using namespace std;

const int Maxn = 305;
const int Maxl = 1000005;

char tmp[Maxl];
int n;
string w[Maxn];
int S[Maxn];
int dp[Maxn][Maxn];
int res;

void Read(string &s)
{
    scanf("%s", tmp); s = tmp;
}

void Solve(int ind, int hm)
{
    int cnt = 1;
    for (int i = ind + hm; i + hm <= n + 1; )
        if (dp[ind][i] >= hm) { cnt++; i += hm; }
        else i++;
    if (cnt >= 2) {
        int cand = S[n] + n - 1 - cnt * (S[ind + hm - 1] - S[ind - 1] + hm - 1) + cnt * hm;
        res = min(res, cand);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        Read(w[i]);
        S[i] = S[i - 1] + int(w[i].length());
    }
    res = S[n] + n - 1;
    for (int i = n; i > 0; i--)
        for (int j = i + 1; j <= n; j++) if (w[i] == w[j])
            if (j + 1 <= n) dp[i][j] = 1 + dp[i + 1][j + 1];
            else dp[i][j] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; i + j <= n + 1; j++)
            Solve(i, j);
    printf("%d\n", res);
    return 0;
}
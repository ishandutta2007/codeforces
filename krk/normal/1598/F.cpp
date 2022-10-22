#include <bits/stdc++.h>
using namespace std;

const int Maxn = 20;
const int Maxm = 400005;
const int Inf = 1000000000;

char tmp[Maxm];
int n;
string S[Maxn];
int adds[Maxn][Maxm];
bool en[Maxn][Maxm];
int dif[Maxn];
int dp[1 << Maxn];
int res;

void Read(string &s)
{
    scanf("%s", tmp);
    s = tmp;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        Read(S[i]);
        int st = 0;
        int mn = 0;
        for (int z = 0; z < S[i].length(); z++) {
            if (S[i][z] == '(') st++;
            else st--;
            if (st <= 0 && st <= mn) {
                adds[i][-st]++;
                mn = min(mn, st);
            }
        }
        for (int j = 0; j < -mn; j++)
            en[i][j] = true;
        dif[i] = st;
    }
    fill(dp, dp + (1 << n), -Inf);
    dp[0] = 0;
    for (int i = 0; i < 1 << n; i++) if (dp[i] >= 0) {
        int st = 0;
        for (int j = 0; j < n; j++) if (i & 1 << j)
            st += dif[j];
        for (int j = 0; j < n; j++) if (!(i & 1 << j)) {
            int cand = dp[i] + adds[j][st];
            res = max(res, cand);
            if (!en[j][st])
                dp[i | 1 << j] = max(dp[i | 1 << j], cand);
        }
    }
    printf("%d\n", res);
    return 0;
}
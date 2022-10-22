#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2000005;
const double eps = 1e-10;
const double empt = -1e30;

char tmp[Maxn];
int tlen;
char str[Maxn];
int slen;
double res;
double dp[Maxn][2];

void Print(double res)
{
    printf("%.6f\n", max(0.0, res * 100 + eps - 0.0000005));
}

int main()
{
    scanf("%s", tmp);
    tlen = strlen(tmp);
    int lets = 0;
    for (int i = 0; i < tlen; i++) {
        str[slen++] = tmp[i];
        if (tmp[i] == 'L' || tmp[i] == 'R') {
            lets++;
            if (i + 1 < tlen && tmp[i] == tmp[i + 1])
                str[slen++] = 'X';
        }
    }
    if ((str[0] == 'L' || str[0] == 'R') && str[0] == str[slen - 1])
        if (str[0] == 'L') str[slen++] = 'X';
        else {
            for (int i = slen; i > 0; i--)
                str[i] = str[i - 1];
            str[0] = 'X';
            slen++;
        } 
    res = double(lets) / 2.0 / (slen + 1 - slen % 2);
    double lef = 0, rig = 1;
    fill((double*)dp, (double*)dp + Maxn * 2, empt);
    for (int i = 0; i < 40; i++) {
        double mid = (lef + rig) / 2.0;
        dp[0][0] = 0;
        for (int i = 0; i < slen; i++)
            for (int j = 0; j < 2; j++) {
                if (str[i] == 'X') { dp[i + 1][1 - j] = max(dp[i + 1][1 - j], dp[i][j] - mid); }
                else {
                    bool good = (j % 2) == (str[i] == 'R');
                    if (good) dp[i + 1][1 - j] = max(dp[i + 1][1 - j], dp[i][j] + 1 - mid);
                    else {
                        dp[i + 1][1 - j] = max(dp[i + 1][1 - j], dp[i][j] - mid);
                        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1 - 2 * mid);
                    }
                }
                dp[i][j] = empt;
            }
        if (max(dp[slen][0], dp[slen][1] - mid) >= 0) lef = mid;
        else rig = mid;
        dp[slen][0] = dp[slen][1] = empt;
    }
    Print(max(res, lef));
    return 0;
}
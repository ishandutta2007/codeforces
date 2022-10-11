#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int d[3] = {-1, 0, 1};
const string c = "LDW";
int ans[1005][2005], i, n, k, j, t;
string s, res = "";

int main()
{
    memset(ans, -1, sizeof(ans));
    cin >> n >> k >> s;
    ans[0][k] = 1;
    for (i = 1; i <= n; i++)
    {
        if (s[i - 1] != '?')
        {
            if (s[i - 1] == 'W') t = 2;
            else if (s[i - 1] == 'D') t = 1;
            else t = 0;
            if (i == n)
            {
                for (j = max(0, -d[t]); j <= min(2 * k, 2 * k - d[t]); j++)
                    if (ans[i - 1][j] != -1)
                        ans[i][j + d[t]] = t;
            }
            else
            {
                for (j = max(1, 1 - d[t]); j <= min(2 * k - 1, 2 * k - d[t] - 1); j++)
                    if (ans[i - 1][j] != -1)
                        ans[i][j + d[t]] = t;
            }
        }
        else for (t = 0; t < 3; t++)
        {
            if (i == n)
            {
                for (j = max(0, -d[t]); j <= min(2 * k, 2 * k - d[t]); j++)
                    if (ans[i - 1][j] != -1)
                        ans[i][j + d[t]] = t;
            }
            else
            {
                for (j = max(1, 1 - d[t]); j <= min(2 * k - 1, 2 * k - d[t] - 1); j++)
                    if (ans[i - 1][j] != -1)
                        ans[i][j + d[t]] = t;
            }
        }
    }
    if (ans[n][2 * k] == -1 && ans[n][0] == -1)
    {
        printf("NO");
        return 0;
    }
    if (ans[n][2 * k] != -1)
        t = 2 * k;
    else t = 0;
    for (i = n; i > 0; i--)
    {
        res = c[ans[i][t]] + res;
        t -= d[ans[i][t]];
    }
    printf("%s", res.c_str());
    return 0;
}
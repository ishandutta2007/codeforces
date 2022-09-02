#include <bits/stdc++.h>
using namespace std;
int n, s[105] = {0}, m, f[25][1050000] = {{0}}, MAXI, x[25] = {0};
bool flag[25][1050000] = {{false}};
char s1[25][10] = {'\0'};
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
    sort(s + 1, s + n + 1, greater<int>());
    scanf("%d", &m);
    MAXI = 1 << m;
    flag[m][0] = true;
    for (int i = 1; i <= m; i++) scanf("%s", s1[i]), scanf("%d", &x[i]);
    for (int i = m; i >= 1; i--)
    {
        if (x[i] == 1)
        {
            for (int j = 0; j < MAXI; j++)
                if (flag[i][j])
                {
                    for (int k = 0, k0 = 1; k < m; k++, k0 <<= 1)
                        if (!(j & k0))
                            if (!flag[i - 1][j ^ k0] || f[i - 1][j ^ k0] < f[i][j] + ((s1[i][0] == 'p')? s[k + 1] : 0))
                            {
                                f[i - 1][j ^ k0] = f[i][j] + ((s1[i][0] == 'p')? s[k + 1] : 0);
                                flag[i - 1][j ^ k0] = true;
                            }
                }
        }
        else
        {
            for (int j = 0; j < MAXI; j++)
                if (flag[i][j])
                {
                    for (int k = 0, k0 = 1; k < m; k++, k0 <<= 1)
                        if (!(j & k0))
                            if (!flag[i - 1][j ^ k0] || f[i - 1][j ^ k0] > f[i][j] - ((s1[i][0] == 'p')? s[k + 1] : 0))
                            {
                                f[i - 1][j ^ k0] = f[i][j] - ((s1[i][0] == 'p')? s[k + 1] : 0);
                                flag[i - 1][j ^ k0] = true;
                            }
                }
        }
    }
    printf("%d\n", f[0][MAXI - 1]);
    return 0;
}
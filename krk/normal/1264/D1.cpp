#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 2005;
const int mod = 998244353;

char str[Maxn];
int n;
int L[Maxn][Maxn], R[Maxn][Maxn];
int res;

int main()
{
    scanf("%s", str + 1);
    n = strlen(str + 1);
    L[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++) if (L[i][j]) {
            if (str[i + 1] == ')' || str[i + 1] == '?')
                L[i + 1][j] = (L[i + 1][j] + L[i][j]) % mod;
            if (str[i + 1] == '(' || str[i + 1] == '?')
                L[i + 1][j + 1] = (L[i + 1][j + 1] + L[i][j]) % mod;
        }
    R[n + 1][0] = 1;
    for (int i = n + 1; i > 1; i--)
        for (int j = 0; j <= n; j++) if (R[i][j]) {
            if (str[i - 1] == ')' || str[i - 1] == '?')
                R[i - 1][j + 1] = (R[i - 1][j + 1] + R[i][j]) % mod;
            if (str[i - 1] == '(' || str[i - 1] == '?')
                R[i - 1][j] = (R[i - 1][j] + R[i][j]) % mod;
        }
    for (int i = 1; i <= n; i++)
        for (int j = n; j >= 0; j--)
            R[i][j] = (R[i][j] + R[i][j + 1]) % mod;
    for (int i = 1; i <= n; i++)
        if (str[i] == '(' || str[i] == '?')
            for (int j = 0; j <= n; j++)
                res = (res + ll(L[i - 1][j]) * R[i + 1][j + 1]) % mod;
    printf("%d\n", res);
    return 0;
}
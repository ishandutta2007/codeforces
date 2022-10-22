#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int Maxn = 5005;

int C[Maxn][Maxn];
int n, k;
char str[Maxn];
int ones[Maxn];
int res = 1;

int main()
{
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    scanf("%d %d", &n, &k);
    scanf("%s", str);
    for (int i = 0; i < n; i++) {
        ones[i] = str[i] - '0';
        if (i) ones[i] += ones[i - 1];
    }
    if (ones[n - 1] < k || k == 0) { printf("1\n"); return 0; }
    int r = 0;
    for (int i = 0; i < n; i++) {
        int sub = i > 0? ones[i - 1]: 0;
        r = max(r, i);
        while (r + 1 < n && ones[r + 1] - sub <= k) r++;
        if (str[i] == '1')
            res = (res + C[r - i][ones[r] - sub]) % mod;
        else if (ones[r] - sub > 0)
            res = (res + C[r - i][ones[r] - sub - 1]) % mod;
    }
    printf("%d\n", res);
    return 0;
}
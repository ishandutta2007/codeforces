#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, k;
char str[Maxn];
int sum[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        scanf("%s", str + 1);
        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + (str[i] == 'W');
        int mn = n;
        for (int i = k; i <= n; i++)
            mn = min(mn, sum[i] - sum[i - k]);
        printf("%d\n", mn);
    }
    return 0;
}
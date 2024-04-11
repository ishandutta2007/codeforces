#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n, q;
char str[Maxn];
int sum[Maxn];

int main()
{
    scanf("%d %d", &n, &q);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = int(str[i] - 'a' + 1) + sum[i - 1];
    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        printf("%d\n", sum[r] - sum[l - 1]);
    }
    return 0;
}
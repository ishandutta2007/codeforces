#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int Maxn = 1005;

int n;
ll B[Maxn][Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%I64d", &B[i][j]);
    ll rt = B[1][2] * B[1][3] / B[2][3];
    ll g = sqrt(ld(rt));
    while (g * g < rt) g++;
    while (g * g > rt) g--;
    printf("%I64d", g);
    for (int i = 2; i <= n; i++)
        printf(" %I64d", B[1][i] / g);
    printf("\n");
    return 0;
}
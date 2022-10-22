#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
const int Maxm = Maxn * Maxn;

int n, sum;
int a[Maxn];
int freq[Maxn];
int mn[Maxn][Maxm], mx[Maxn][Maxm];
int res;

int Union(int a, int b)
{
    return min(a + b, 2);
}

int main()
{
    scanf("%d", &n);
    fill((int*)mn, (int*)mn + Maxn * Maxm, Maxn);
    fill((int*)mx, (int*)mx + Maxn * Maxm, -Maxn);
    mn[0][0] = Maxn - 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        for (int j = i; j >= 0; j--)
            for (int l = 0; l <= sum; l++) if (mn[j][l] < Maxn) {
                mn[j + 1][l + a[i]] = min(mn[j + 1][l + a[i]], min(a[i], mn[j][l]));
                mx[j + 1][l + a[i]] = max(mx[j + 1][l + a[i]], max(a[i], mx[j][l]));
            }
        sum += a[i];
        freq[a[i]]++;
    }
    for (int i = 0; i < Maxn; i++)
        for (int j = 1; j <= freq[i]; j++) if (mn[j][i * j] == mx[j][i * j]) {
            res = max(res, j);
            for (int l = i + 1; l < Maxn; l++) if ((sum - i * j) % l == 0) {
                int tk = (sum - i * j) / l;
                if (j + tk == n && tk <= freq[l] && mn[tk][tk * l] == mx[tk][tk * l])
                    res = max(res, n);
            }
        }
    printf("%d\n", res);
    return 0;
}
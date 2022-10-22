#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, k;
int a[Maxn];

int main()
{
    scanf("%d %d", &n, &k);
    ll sum = ll(k + 1) * k / 2;
    if (sum > n) { printf("NO\n"); return 0; }
    ll lft = n - sum;
    int give = lft / k;
    for (int i = 0; i < k; i++)
        a[i] = i + 1 + give;
    lft %= k;
    for (int i = k - 1; i >= 0 && lft > 0; i--)
        while (lft > 0 && (i == 0 || a[i] < a[i - 1] * 2)) {
            for (int j = i; j < k && lft > 0; j++)
                while (lft > 0 && (j == 0 || a[j] < a[j - 1] * 2)) {
                    a[j]++; lft--;
                }
        }
    for (int i = 0; i + 1 < k; i++)
        if (a[i] < a[i + 1] && a[i + 1] <= 2 * a[i]) ;
        else { printf("NO\n"); return 0; }
    printf("YES\n");
    for (int i = 0; i < k; i++)
        printf("%d%c", a[i], i + 1 < k? ' ': '\n');
    return 0;
}
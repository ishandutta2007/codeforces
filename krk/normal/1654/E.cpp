#include <bits/stdc++.h>
using namespace std;

const int Maxp = 320;
const int Maxn = 100005;
const int Maxm = 50000000;

int n;
int a[Maxn];
int cnt[Maxm];
int res;

void Solve()
{
    for (int p = 0; p < Maxp; p++) {
        for (int i = 0; i < n; i++)
            res = max(res, ++cnt[a[i] + i * p]);
        for (int i = 0; i < n; i++)
            cnt[a[i] + i * p] = 0;
    }
    for (int i = 0; i < n; i++) {
        int to = min(n, i + Maxp);
        for (int j = i + 1; j < to; j++) if (a[j] > a[i] && (a[j] - a[i]) % (j - i) == 0)
            res = max(res, 1 + (++cnt[(a[j] - a[i]) / (j - i)]));
        for (int j = i + 1; j < to; j++) if (a[j] > a[i] && (a[j] - a[i]) % (j - i) == 0)
            cnt[(a[j] - a[i]) / (j - i)] = 0;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    Solve();
    reverse(a, a + n);
    Solve();
    printf("%d\n", n - res);
    return 0;
}
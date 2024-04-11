#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, p, k;
int a[Maxn];
int sum[Maxn];
int my[Maxn];

bool Solve(int x)
{
    int res = 0;
    while (x > 0) {
        res += a[x - 1];
        x -= k;
    }
    return res <= p;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &p, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        sum[0] = a[0];
        for (int i = 1; i < n; i++)
            sum[i] = sum[i - 1] + a[i];
        int res = 0;
        fill(my, my + k, 0);
        for (int i = 1; i <= n; i++)
            if (i < k) {
                int cand = sum[i - 1];
                if (cand <= p) res = i;
            } else {
                my[i % k] += a[i - 1];
                int cand = my[i % k] + (i % k > 0? sum[i % k - 1]: 0);
                if (cand <= p) res = i;
            }
        printf("%d\n", res);
    }
    return 0;
}
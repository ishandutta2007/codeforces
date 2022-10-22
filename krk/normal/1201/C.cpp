#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, k;
int a[Maxn];

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int mid = n / 2;
    for (int i = mid; i + 1 < n; i++) {
        int tk = min(a[i + 1] - a[i], k / (i - mid + 1));
        k -= tk * (i - mid + 1);
        a[i] += tk;
        if (a[i] < a[i + 1]) {
            printf("%d\n", a[i]); return 0;
        }
    }
    int tk = k / (n - mid);
    a[n - 1] += tk;
    printf("%d\n", a[n - 1]);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn];
int L[Maxn], R[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        L[i] = 1;
        if (i && a[i - 1] < a[i]) L[i] += L[i - 1];
        res = max(res, L[i]);
    }
    for (int i = n; i > 0; i--) {
        R[i] = 1;
        if (i < n && a[i] < a[i + 1]) R[i] += R[i + 1];
    }
    for (int i = 1; i <= n; i++)
        if (i == 1) res = max(res, R[i + 1]);
        else if (i == n) res = max(res, L[i - 1]);
        else if (a[i - 1] < a[i + 1]) res = max(res, L[i - 1] + R[i + 1]);
    printf("%d\n", res);
    return 0;
}
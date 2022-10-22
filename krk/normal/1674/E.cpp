#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn];
int res = 1000000000;

int Solve(int a, int b)
{
    if (a > b) swap(a, b);
    if (2 * a <= b) return (b - 1) / 2 + 1;
    int res = b - a;
    a -= res;
    res += a / 3 * 2; a %= 3;
    res += a;
    return res;
}

int Spec(int a, int b)
{
    if (a > b) swap(a, b);
    int res = a;
    if (b > a) res += (b - a - 1) / 2 + 1;
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (i) res = min(res, Solve(a[i - 1], a[i]));
        if (i >= 2) res = min(res, Spec(a[i - 2], a[i]));
    }
    sort(a, a + n);
    res = min(res, (a[0] - 1) / 2 + 1 + (a[1] - 1) / 2 + 1);
    printf("%d\n", res);
    return 0;
}
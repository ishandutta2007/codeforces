#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    int l = 0;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        while (a[i] - a[l] > 5) l++;
        res = max(res, i - l + 1);
    }
    printf("%d\n", res);
    return 0;
}
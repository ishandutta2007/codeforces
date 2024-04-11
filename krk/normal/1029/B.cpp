#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0, j; i < n; i = j) {
        j = i + 1;
        while (j < n && a[j] <= 2 * a[j - 1])
            j++;
        res = max(res, j - i);
    }
    printf("%d\n", res);
    return 0;
}
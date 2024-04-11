#include <bits/stdc++.h>
using namespace std;

const int Maxn = 150;

int n;
int a[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int res1 = a[n - 1];
    if (a[n - 2] == res1) { printf("%d %d\n", res1, res1); return 0; }
    for (int i = n - 2; i >= 0; i--)
        if (res1 % a[i] != 0 || a[i] == a[i - 1]) {
            printf("%d %d\n", a[i], res1); return 0;
        }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n, x, y;
int a[Maxn];

int main()
{
    scanf("%d %d %d", &n, &x, &y);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    if (x > y) printf("%d\n", n);
    else {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (a[i] <= x) cnt++;
        printf("%d\n", (cnt + 1) / 2);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
int res[Maxn];
int b[Maxn];

bool Solve()
{
    res[n - 1] = b[n - 1];
    for (int i = n - 2; i >= 0; i--)
        res[i] = a[i] == b[i]? a[i]: min(b[i], res[i + 1] + 1);
    res[n - 1] = a[n - 1] == b[n - 1]? a[n - 1]: min(b[n - 1], res[0] + 1);
    for (int i = n - 2; i >= 0; i--)
        res[i] = a[i] == b[i]? a[i]: min(b[i], res[i + 1] + 1);
    for (int i = 0; i < n; i++)
        if (a[i] > b[i] || res[i] < b[i])
            return false;
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        printf("%s\n", Solve()? "YES": "NO");
    }
    return 0;
}
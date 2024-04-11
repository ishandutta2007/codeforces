#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        ll res = 0;
        for (int i = n - 1; i > 0; i--)
            if (a[i] < a[i - 1]) res += a[i - 1] - a[i];
        printf("%I64d\n", res);
    }
    return 0;
}
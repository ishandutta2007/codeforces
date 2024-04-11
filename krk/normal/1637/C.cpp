#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        if (n == 3 && a[2] % 2) printf("-1\n");
        else {
            bool canStart = false;
            for (int i = 2; i < n; i++)
                if (a[i] >= 2) canStart = true;
            if (!canStart) printf("-1\n");
            else {
                ll res = 0;
                for (int i = 2; i < n; i++)
                    res += (a[i] + 1) / 2;
                printf("%I64d\n", res);
            }
        }
    }
    return 0;
}
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
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        ll sum = 0;
        ll res = 0;
        for (int i = 1; i < n; i++)
            if (a[i] == 0)
                if (sum == 0) ;
                else res++;
            else sum += a[i];
        res += sum;
        printf("%I64d\n", res);
    }
    return 0;
}
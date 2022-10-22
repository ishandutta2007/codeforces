#include <bits/stdc++.h>
using namespace std;

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
        int mx = a[n - 1];
        int res = 0;
        for (int i = n - 2; i >= 0; i--)
            if (a[i] > mx) {
                res++;
                mx = a[i];
            }
        printf("%d\n", res);
    }
    return 0;
}
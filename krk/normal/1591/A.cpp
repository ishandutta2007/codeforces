#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

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
        int res = 1 + (a[0] == 1);
        for (int i = 1; i < n; i++)
            if (a[i] == 0)
                if (a[i - 1] == 0) { res = -1; break; }
                else ;
            else if (a[i - 1] == 1) res += 5;
            else res++;
        printf("%d\n", res);
    }
    return 0;
}
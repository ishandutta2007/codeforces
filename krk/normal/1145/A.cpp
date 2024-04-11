#include <bits/stdc++.h>
using namespace std;

const int Maxn = 16;

int n;
int a[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int l = 1; l <= Maxn; l *= 2)
        for (int i = 0; i < n; i += l) {
            bool ok = true;
            for (int j = 1; j < l && ok; j++)
                ok = a[i + j - 1] <= a[i + j];
            if (ok) res = l;
        }
    printf("%d\n", res);
    return 0;
}
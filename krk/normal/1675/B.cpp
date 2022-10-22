#include <bits/stdc++.h>
using namespace std;

const int Maxn = 32;

int T;
int n;
int a[Maxn];

int Solve()
{
    int res = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i + 1] == 0) return -1;
        while (a[i] >= a[i + 1]) {
            a[i] /= 2;
            res++;
        }
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        printf("%d\n", Solve());
    }
    return 0;
}
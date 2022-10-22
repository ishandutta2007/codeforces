#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int X[Maxn], Y[Maxn];
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &X[i]);
        for (int i = 0; i < n; i++) {
            scanf("%d", &Y[i]);
            a[i] = Y[i] - X[i];
        }
        sort(a, a + n);
        int res = 0;
        int l = 0, r = n - 1;
        while (l < r)
            if (a[l] + a[r] < 0) l++;
            else { res++; l++; r--; }
        printf("%d\n", res);
    }
    return 0;
}
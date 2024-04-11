#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int n, w;
int mn, mx, st;

int main()
{
    scanf("%d %d", &n, &w);
    for (int i = 1; i <= n; i++) {
        int a; scanf("%d", &a);
        st += a;
        mn = min(mn, st);
        mx = max(mx, st);
    }
    if (mx - mn > w) printf("0\n");
    else printf("%d\n", w - (mx - mn) + 1);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n, x;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &x);
        bool was = false;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (a[i] == x) was = true;
        }
        sort(a, a + n);
        if (was) printf("1\n");
        else {
            int res = max(2, (x - 1) / a[n - 1] + 1);
            printf("%d\n", res);
        }
    }
    return 0;
}
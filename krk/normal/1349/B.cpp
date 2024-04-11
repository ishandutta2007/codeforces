#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n, k;
int a[Maxn];
int cur[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        bool was = false;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] == k) was = true;
        }
        if (!was) { printf("no\n"); continue; }
        if (n == 1) { printf("yes\n"); continue; }
        int mn = 1000000000;
        was = false;
        for (int i = 1; i <= n && !was; i++) {
            if (a[i] >= k) cur[i] = cur[i - 1] + 1;
            else cur[i] = cur[i - 1] - 1;
            if (cur[i] - mn > 0) was = true;
            mn = min(mn, cur[i - 1]);
        }
        printf("%s\n", was? "yes": "no");
    }
    return 0;
}
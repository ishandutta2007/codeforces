#include <stdio.h>

int main(void) {
    int t;
    scanf("%d", &t);
    int a[1000];
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        int l = 0, r = n - 1;
        while (a[l] == 0) ++l;
        while (a[r] == 0) --r;
        int cnt = 0;
        for (int i = l; i <= r; ++i)
            cnt += (a[i] == 0);
        printf("%d\n", cnt);
    }
    return 0;
}
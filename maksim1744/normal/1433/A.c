#include <stdio.h>

int main(void) {
    int ar[100];
    int cnt[100];
    int ind = 0;
    for (int c = 1; c <= 9; ++c) {
        int x = 0;
        for (int i = 0; i < 4; ++i) {
            x = x * 10 + c;
            ar[ind] = x;
            cnt[ind] = i + 1;
            ++ind;
        }
    }
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int ans = 0;
        int i = 0;
        for (; ar[i] != n; ++i) {
            ans += cnt[i];
        }
        ans += cnt[i];
        printf("%d\n", ans);
    }
    return 0;
}
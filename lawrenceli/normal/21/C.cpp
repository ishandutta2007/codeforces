#include <cstdio>

const int MAXN = 100100;

int n, ar[MAXN], sum, num;
long long ans;

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &ar[i]);
        sum += ar[i];
    }
    if (sum%3) {
        printf("0\n");
        return 0;
    }
    int cur = 0;
    for (int i=0; i<n-1; i++) {
        cur += ar[i];
        if (cur == 2*sum/3) ans += num;
        if (cur == sum/3) num++;
    }
    printf("%I64d\n", ans);
    return 0;
}
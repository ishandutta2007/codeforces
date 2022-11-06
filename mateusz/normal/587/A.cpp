#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int cnt[2 * N];
int n, x;

int main() {

    scanf("%d", &n);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        cnt[x]++;
        mx = max(mx, x);
    }

    int ans = 0;
    for (int i = 0; i <= mx; i++) {
        if (cnt[i] % 2) {
            ans++;
        }
        cnt[i + 1] += cnt[i] / 2;
        if (cnt[i + 1] > 0) {
            mx = max(mx, i + 1);
        }
    }

    printf("%d\n", ans);

    return 0;
}
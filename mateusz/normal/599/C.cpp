#include <bits/stdc++.h>

using namespace std;

const int N = 100005, INF = 1e9 + 5;

int n;
int h[N], suf[N];

int main() {

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
    }

    suf[n + 1] = INF;
    for (int i = n; i >= 1; i--) {
        suf[i] = min(h[i], suf[i + 1]);
    }

    int mx = 0;
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        mx = max(mx, h[i]);
        if (mx <= suf[i + 1]) {
            ans++;
            mx = 0;
        }
    }

    printf("%d\n", ans);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int x, gdzie[N], n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        gdzie[x] = i;
    }
    int ans = 0;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        if (gdzie[i] > gdzie[i - 1]) {
            cur++;
            ans = max(ans, cur);
        } else {
            cur = 1;
        }
    }
    printf("%d\n", n - ans);
    return 0;
}
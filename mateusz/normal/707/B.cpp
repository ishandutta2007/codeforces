#include <bits/stdc++.h>

using namespace std;

const int N = 100005, INF = 1e9 + 5;

int n, m, k, x;
int a[N], b[N], c[N];
bool storage[N];

int main() {

    scanf("%d %d %d", &n, &m, &k);

    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
    }

    for (int i = 1; i <= k; i++) {
        scanf("%d", &x);
        storage[x] = true;
    }

    int ans = INF;
    for (int i = 1; i <= m; i++) {
        if (storage[a[i]] ^ storage[b[i]]) {
            ans = min(ans, c[i]);
        }
    }

    if (ans == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", ans);
    }

    return 0;
}
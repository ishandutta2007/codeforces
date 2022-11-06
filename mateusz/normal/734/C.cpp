#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, m, k, x, s;
int a[N], b[N], c[N], d[N], t[N];

bool cmp(int w, int u) {
    return b[w] < b[u];
}

int main() {

    scanf("%d %d %d", &n, &m, &k);
    scanf("%d %d", &x, &s);

    a[0] = x;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
    }

    for (int i = 1; i <= k; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 1; i <= k; i++) {
        scanf("%d", &d[i]);
    }

    for (int i = 1; i <= m; i++) {
        t[i] = i;
    }
    sort(t + 1, t + 1 + m, cmp);

    long long ans = (long long)n * x;

    int pos = k;
    for (int i = 0; i <= m; i++) {
        if (b[t[i]] > s) {
            break;
        }
        while (pos > 0 && (long long)b[t[i]] + d[pos] > s) {
            pos--;
        }
        ans = min(ans, (long long)(n - c[pos]) * a[t[i]]);
    }

    printf("%lld\n", ans);

    return 0;
}
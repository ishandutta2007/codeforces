#include <bits/stdc++.h>

using namespace std;

const int maxn = 2005;

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int n;
int a[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == 1) cnt++;

    if (cnt > 0) {
        printf("%d\n", n - cnt);
        return 0;
    }

    int mi = n + 1;
    for (int i = 0; i < n; i++) {
        int cur = a[i];
        for (int j = i; j < n; j++) {
            cur = gcd(cur, a[j]);
            if (cur == 1) {
                mi = min(mi, j - i);
                break;
            }
        }
    }

    if (mi == n + 1) printf("-1\n");
    else printf("%d\n", n - 1 + mi);
}
// Skyqwq
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 105;

int n, u, v, a[N];

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &u, &v);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        bool ok = false;
        for (int i = 1; i < n; i++) {
            if (abs(a[i + 1] - a[i]) > 1) {
                ok = true;
            }
        }
        if (ok) {
            puts("0");
            continue;
        }
        ok = false;
        for (int i = 1; i < n; i++) {
            if (abs(a[i + 1] - a[i]) == 1) {
                ok = true;
            }
        }
        if (ok) printf("%d\n", min(u, v));
        else printf("%d\n", min(2 * v, v + u));
    }
    return 0;
}
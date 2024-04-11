// Skyqwq
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 3e5 + 5, S = 1e6 + 5;

int n, a[N], q, cnt[S];

LL w;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int a1 = 0, a0 = 0;
        for (int i = 1; i <= n; i++) {
            int x; scanf("%d", &x);
            for (int j = 2; j * j <= x; j++) {
                while (x % (j * j) == 0) x /= j * j;
            }
            cnt[a[i] = x] ++;
            a0 = max(a0, cnt[a[i]]);
        }
        a1 = a0;
        int c = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt[a[i]] % 2 == 0 || a[i] == 1) {
                c += cnt[a[i]];
            }
            cnt[a[i]] = 0;
        }
        a1 = max(a1, c);
        int q; scanf("%d", &q);
        while (q--) {  
            LL w; scanf("%lld", &w);
            if (w > 0) printf("%d\n", a1);
            else printf("%d\n", a0);
        }
    }
    return 0;
}
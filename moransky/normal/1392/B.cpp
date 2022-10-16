// Skyqwq
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 2e5 + 5;

int n, a[N];

LL k;

void inline work() {
    int mx = -2e9;
    for (int i = 1; i <= n; i++) mx = max(mx, a[i]);
    for (int i = 1; i <= n; i++) a[i] = mx - a[i];
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%lld", &n, &k);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        work();
        if (k % 2 == 0) work();
        for (int i = 1; i <= n; i++) printf("%d ", a[i]);
        puts("");    
    }
    return 0;
}
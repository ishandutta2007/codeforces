#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

LL solve(LL a, LL b, LL x, LL y, LL n) {
    LL t = min(a - x, n);
    a -= t; n -= t;
    t = min(b - y, n);
    b -= t; n -= t;
    return a * b;
}

void loop() {
    int N, X, Y; scanf("%d%d%d", &N, &X, &Y);
    int ans[50]; int M = 1000000;
    for (int d = 1; d <= 50; d++) {
        if ((Y - X) % d != 0) continue;
        if (Y - X > d * (N - 1)) continue;
        for (int s = 1; s <= X; s++) {
            if (s % d != X % d) continue;
            if (Y - d * (N - 1) > s) continue;
            if (M <= s + d * (N - 1)) break;
            for (int i = 0; i < N; i++)
                ans[i] = s + d * i;
            M = ans[N - 1];
            break;
        }
    }
    rep(i, N) {
        if (i) printf(" ");
        printf("%d", ans[i]);
    } printf("\n");
}

int main() {
    int t; scanf("%d", &t);
    while (t--) loop();

    return 0;
}
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXM = 100100;

int n, m, w[MAXM], num;
ll ans, sum;

ll calc(int x) {
    if (x % 2 == 1) {
        return ll(x) * (x - 1) / 2 + 1;
    } else return ll(x) * (x - 1) / 2 + x / 2;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++) {
        int q; scanf("%d %d", &q, &w[i]);
    }
    sort(w, w + m); reverse(w, w + m);
    for (int i=0; i<m; i++) {
        sum += w[i];
        ll num = calc(i + 1);
        if (num <= n) ans = max(ans, sum);
    }
    printf("%I64d\n", ans);
    return 0;
}
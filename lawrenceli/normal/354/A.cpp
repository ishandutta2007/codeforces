#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100100;

int n, l, r, ql, qr, ans = 1e9;
int w[MAXN], pre[MAXN];

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    cin >> n >> l >> r >> ql >> qr;
    for (int i=0; i<n; i++) {
        cin >> w[i];
        pre[i+1] = pre[i] + w[i];
    }
    for (int i=0; i<=n; i++) {
        int j = n-i, x = 0;
        if (abs(i - j) > 1) x = abs(i - j) - 1;
        if (j > i) x *= qr;
        else x *= ql;
        ans = min(ans, x + (pre[i] - pre[0]) * l + (pre[n] - pre[i]) * r);
    }
    printf("%d\n", ans);
    return 0;
}
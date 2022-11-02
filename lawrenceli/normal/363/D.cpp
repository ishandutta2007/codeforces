#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 100100;

int n, m, a, b[MAXN], p[MAXN];

bool pos(int mid) {
    ll x = a;
    for (int i=0; i<mid; i++) {
        x += min(b[mid-i-1] - p[i], 0);
    }
    return x >= 0;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d %d", &n, &m, &a);
    for (int i=0; i<n; i++) scanf("%d", &b[i]);
    for (int i=0; i<m; i++) scanf("%d", &p[i]);
    sort(b, b + n); sort(p, p + m); reverse(b, b + n);
    int lo = 0, hi = min(n, m);
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (pos(mid)) lo = mid;
        else hi = mid - 1;
    }
    int ans = 0;
    for (int i=0; i<lo; i++) {
        ans += p[i];
    }
    printf("%d %d\n", lo, max(ans - a, 0));
    return 0;
}
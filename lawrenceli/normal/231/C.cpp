#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

typedef long long ll;

int n, k, a[MAXN], lo, hi, ans;

bool pos(int mid) {
    ll num = 0;
    for (int i=0; i<mid; i++) num -= a[i];
    for (int i=0; i + mid - 1 < n; i++) {
        if (ll(mid) * a[i+mid-1] + num <= k) {
            ans = a[i+mid-1];
            return 1;
        }
        num += a[i] - a[i+mid];
    }
    return 0;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    hi = MAXN;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (pos(mid)) lo = mid;
        else hi = mid - 1;
    }
    printf("%d %d\n", lo, ans);
}
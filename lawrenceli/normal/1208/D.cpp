#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 200100;

ll bit[maxn];

ll qry(int i) {
    ll ret = 0;
    for (i++; i > 0; i -= i & -i) ret += bit[i];
    return ret;
}

void upd(int i, int x) {
    for (i++; i < maxn; i += i & -i) bit[i] += x;
}

int n;
ll s[maxn];
int p[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &s[i]);
    }

    for (int i = 1; i <= n; i++) {
        upd(i, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (qry(mid) > s[i]) hi = mid;
            else lo = mid + 1;
        }

        p[i] = lo;
        upd(lo, -lo);
    }

    for (int i = 0; i < n; i++) printf("%d ", p[i]);
}
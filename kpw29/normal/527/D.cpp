#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 200010;
struct node {
    int l, r;
    bool operator < (const node& x) const {
        return r == x.r ? l < x.l : r < x.r;
    }
}a[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x, w;
        scanf("%d%d", &x, &w);
        a[i].l = x - w, a[i].r = x + w;
    }
    sort(a, a + n);
    int ans = 1, r = a[0].r;
    for (int i = 0; i < n; ++i)
        if (a[i].l >= r)
            ++ans, r = a[i].r;
    printf("%d\n", ans);
    return 0;
}
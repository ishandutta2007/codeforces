#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> point;

const int maxn = 2e5 + 5;
const long long mod = 1e9 + 7;

long long power(long long a, long long x) {
    long long ans = 1;
    while (x) {
        if (x & 1) ans = ans * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return ans;
}

point a[maxn];
int b[maxn];
int fa[maxn], siz[maxn];
bool cir[maxn];

int getFa(int k) { return k == fa[k] ? k : fa[k] = getFa(fa[k]); }

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].first, &a[i].second), b[i] = a[i].first;
    sort(b + 1, b + n + 1);
    int len = unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; i++) a[i].first = lower_bound(b + 1, b + len + 1, a[i].first) - b;
    for (int i = 1; i <= n; i++) b[i] = a[i].second;
    sort(b + 1, b + n + 1);
    len = unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; i++) a[i].second = lower_bound(b + 1, b + len + 1, a[i].second) - b;
    for (int i = 1; i <= n << 1; i++) fa[i] = i, siz[i] = 1;
    for (int i = 1; i <= n; i++) {
        int fx = getFa(a[i].first), fy = getFa(a[i].second + n);
        if (fx ^ fy) {
            fa[fy] = fx;
            siz[fx] += siz[fy];
            cir[fx] |= cir[fy];
        } else
            cir[fx] = true;
    }
    long long ans = 1;
    for (int i = 1; i <= n << 1; i++)
        if (fa[i] == i) {
            long long cnt = power(2, siz[i]);
            if (!cir[i]) cnt = ((cnt - 1) % mod + mod) % mod;
            ans = ans * cnt % mod;
        }
    printf("%lld\n", ans);
    return 0;
}
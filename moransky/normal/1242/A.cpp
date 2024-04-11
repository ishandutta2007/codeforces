#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }

const int N = 1e6 + 5;

int f[N];

LL n;

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

void inline merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    f[x] = y;
}

LL m;

void inline work(LL x) {
    for (int i = 0; i < m; i++)
        merge(i, (i + x) % m);
}

int main() {
    for (int i = 1; i < N; i++) f[i] = i;
    scanf("%lld", &n);
    if (n == 1) {
        puts("1");
        return 0;
    }
    for (LL i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (!m) m = i;
            else work(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) {
        if (!m) m = n;
        else work(n);
    }
    if (m > 1e6) printf("%lld\n", m);
    else {
        int ans = 0;
        for (int i = 0; i < m; i++)
            if (find(i) == i) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e6 + 5;

int n, e, a[N], pr[N], sf[N];

bool st[N];

void inline prework(int n) {
    st[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            for (int j = i + i; j <= n; j += i) st[j] = 1;
        }
    }
}
 
int main() {
    prework(1e6);
    int T; read(T);
    while (T--) {
        read(n); read(e);
        for (int i = 1; i <= n; i++) {
            read(a[i]);
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) {
                pr[i] = 1;
                if (i >= e) pr[i] += pr[i - e];
            } else pr[i] = 0;
        }
        for (int i = n; i; i--) {
            if (a[i] == 1) {
                sf[i] = 1;
                if (i + e <= n) sf[i] += sf[i + e];
            } else sf[i] = 0;
        }
        LL ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!st[a[i]]) {
                int l = 1;
                if (i >= e) l += pr[i - e];
                int r = 1;
                if (i + e <= n) r += sf[i + e];
                ans += (LL)l * r - 1;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
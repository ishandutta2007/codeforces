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

const int N = 1e5 + 5;

int n;

int a[N], b[N], t;
 
int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        int mn = 2e9, mx = -2e9;
        int l; read(l);
        bool o = 0;
        while (l--) {
            int x; read(x);
            if (x > mn)
                o = 1;
            chkMax(mx, x);
            chkMin(mn, x);
        }
        if (!o) {
            a[++t] = mn, b[t] = mx;
        }
    }
    
    sort(a + 1, a + 1 + t);
    LL ans = 0;
    for (int i = 1; i <= t; i++) {
        int u = lower_bound(a + 1, a + 1 + t, b[i]) - a;
        ans += t - u + 1;
    }
    cout << 1ll * n * n - ans;
    return 0;
}
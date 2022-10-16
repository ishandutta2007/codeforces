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

const int N = 2e5 + 5;

int n, a[N], L[N], R[N], t, len;

PII e[N], g[N];
 
int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        if (!L[a[i]]) L[a[i]] = i;
        R[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        if (R[i] && L[i] != R[i]) e[++t] = mp(L[i], R[i]);
    sort(e + 1, e + 1 + t);
    int mx = 0;
    for (int i = 1; i <= t; i++) {
        if (e[i].se > mx) {
            g[++len] = e[i];
        }
        chkMax(mx, e[i].se);
    }
    int ans = 0;
    for (int i = 1; i <= len; i++) {
        int j = i;
        int nr = g[i].se;
        int tj = 0;
        while (j < len && g[j + 1].fi < nr) {
            j++;
            if (j == len || (g[j + 1].fi > nr)) tj++, nr = g[j].se;
        }
        
        ans += nr - g[i].fi - 1 - tj;
        i = j;
    }
    printf("%d\n", ans);
    return 0;
}
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
 
const int N = 1e6 + 5, INF = 1e9;
 
int n, m, a[N], b[N], mn[N], c[N];
 
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
 
int main() {
    int T; read(T);
    while (T--) {
        read(n), read(m);
        LL s = 0;
        for (int i = 1; i <= n; i++) read(a[i]), s += abs(a[i]);
        int d = 0;
        for (int i = 1; i <= m; i++) {
            read(b[i]);
            d = gcd(d, b[i]);
        }
        if (d == 1) {
            printf("%lld\n", s);
            continue;
        }
        for (int i = 0; i < d; i++) mn[i] = INF, c[i] = 0;
        for (int i = 1; i <= n; i++) {
            int t = abs(a[i]);
            chkMin(mn[i % d], t);
            if (a[i] < 0) c[i % d] ^= 1;
        }
        LL s1 = s, s2 = s;
        for (int i = 0; i < d; i++) {
            if (c[i]) s1 -= 2 * mn[i];
            else s2 -= 2 * mn[i];
        }
        printf("%lld\n", max(s1, s2));
    }
    return 0;
}
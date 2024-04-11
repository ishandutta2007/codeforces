#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}
 
const int N = 1e5 + 5, md1 = 998244353, md2 = 1e9 + 7, base1 = 19260817, base2 = 666233;
 
struct ele {
    int l, r, id;
    ele (int a = 0, int b = 0) : l(a), r(b) {}
} pa[N], pb[N], tmp[N];
 
int pw1[N], pw2[N], a1[N], a2[N], b1[N], b2[N];
int n, now1, now2;
 
bool cmp1(ele a, ele b) { return a.l < b.l; }
bool cmp2(ele a, ele b) { return a.r < b.r; }
 
int main() {
    srand(time(0));
    read(n); pw1[0] = pw2[0] = 1;
    for (int i = 1; i <= n; i++) {
        read(pa[i].l); read(pa[i].r);
        read(pb[i].l); read(pb[i].r);
        pa[i].id = pb[i].id = i;
        pw1[i] = 1ll * pw1[i - 1] * base1 % md1;
        pw2[i] = 1ll * pw2[i - 1] * base2 % md2;
    }
    memcpy(tmp, pa, sizeof(tmp));
    sort(tmp + 1, tmp + n + 1, cmp2); sort(pa + 1, pa + n + 1, cmp1);
    int pos = 1;
    for (int i = 1; i <= n; i++) {
        while (pos <= n && tmp[pos].r < pa[i].l) {
            now1 = (now1 + pw1[tmp[pos].id]) % md1;
            now2 = (now2 + pw2[tmp[pos].id]) % md2;
            ++pos;
        }
        if (pos != 1) {
            a1[pa[i].id] = (a1[pa[i].id] + now1) % md1;
            a2[pa[i].id] = (a2[pa[i].id] + now2) % md2;
        }
    }
    sort(tmp + 1, tmp + n + 1, cmp1); sort(pa + 1, pa + n + 1, cmp2);
    pos = n; now1 = now2 = 0;
    for (int i = n; i >= 1; i--) {
        while (pos >= 1 && tmp[pos].l > pa[i].r) {
            now1 = (now1 + pw1[tmp[pos].id]) % md1;
            now2 = (now2 + pw2[tmp[pos].id]) % md2;
            --pos;
        }
        if (pos != n) {
            a1[pa[i].id] = (a1[pa[i].id] + now1) % md1;
            a2[pa[i].id] = (a2[pa[i].id] + now2) % md2;
        }
    }
    memcpy(tmp, pb, sizeof(tmp));
    sort(tmp + 1, tmp + n + 1, cmp2); sort(pb + 1, pb + n + 1, cmp1);
    pos = 1; now1 = now2 = 0;
    for (int i = 1; i <= n; i++) {
        while (pos <= n && tmp[pos].r < pb[i].l) {
            now1 = (now1 + pw1[tmp[pos].id]) % md1;
            now2 = (now2 + pw2[tmp[pos].id]) % md2;
            ++pos;
        }
        if (pos != 1) {
            b1[pb[i].id] = (b1[pb[i].id] + now1) % md1;
            b2[pb[i].id] = (b2[pb[i].id] + now2) % md2;
        }
    }
    sort(tmp + 1, tmp + n + 1, cmp1); sort(pb + 1, pb + n + 1, cmp2);
    pos = n; now1 = now2 = 0;
    for (int i = n; i >= 1; i--) {
        while (pos >= 1 && tmp[pos].l > pb[i].r) {
            now1 = (now1 + pw1[tmp[pos].id]) % md1;
            now2 = (now2 + pw2[tmp[pos].id]) % md2;
            --pos;
        }
        if (pos != n) {
            b1[pb[i].id] = (b1[pb[i].id] + now1) % md1;
            b2[pb[i].id] = (b2[pb[i].id] + now2) % md2;
        }
    }
    for (int i = 1; i <= n; i++) if (a1[i] != b1[i] || a2[i] != b2[i]) {
        // if (n == 64) printf("%d %d %d %d\n", a1[i], b1[i], a2[i], b2[i]);
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}
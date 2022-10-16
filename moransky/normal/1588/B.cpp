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

LL inline ask(int l, int r) {
    printf("? %d %d\n", l, r);
    fflush(stdout);
    LL x; read(x);
    return x;
}

int n;

int inline get(LL x) {
    int l = 0, r = 1e9;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (mid * (mid - 1ll) / 2 >= x) r = mid;
        else l = mid + 1;
    }
    if (r * (r - 1ll) / 2 == x) return r;
    return -1;
}
 
int main() {
    int T; read(T);
    while (T--) {
        read(n);
        LL s = ask(1, n);
        int l = 1, r = n;
        int x = -1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            LL v = ask(1, mid);
            if (v == s) r = mid - 1;
            else if (v == 0) {
                l = mid;
            } else {
                if (x != -1) {
                    if ((LL)(mid - x + 1) * (mid - x) / 2 == v) l = mid;
                    else r = mid - 1;
                } else {
                    int g = get(v);
                    if (g == -1) r = mid - 1;
                    else {
                        if (ask(mid - g + 1, mid) == v) l = mid, x = mid - g + 1;
                        else r = mid - 1;
                    }
                }
            }
        }
        int j = r + 1;
        LL v = ask(1, r);
        int g = get(v);
        int i = j - g;
        int l2 = get(s - v);
        int k = j + l2 - 1;
        printf("! %d %d %d\n", i, j, k);
        fflush(stdout);
    }
    return 0;
}
// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

int a, b;
 
int main() {
    int T; read(T);
    while (T--) {
        read(a), read(b);
        int s = a + b;
        if (a > b) swap(a, b);
        if (s % 2 == 0) {
            int k = (b - a) / 2, mx = s - k;
            int num = (mx - k) / 2 + 1;
            printf("%d\n", num);
            for (int j = k; j <= mx; j += 2) printf("%d ", j);
            puts("");
        } else {
            int x = s / 2, y = s - x;
            int mn = s - min(x, a) - min(y, b), mx = s - mn;
            printf("%d\n", mx - mn + 1);
            for (int j = mn; j <= mx; j++) printf("%d ", j);
            puts("");
        }
    }
    return 0;
}
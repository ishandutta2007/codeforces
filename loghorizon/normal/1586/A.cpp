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

const int N = 105;

int n, a[N];
 
bool inline chk(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return 1;
    return 0;
}

int main() {
    int T; read(T);
    while (T--) {
        read(n);
        int s = 0;
        for (int i = 1; i <= n; i++) read(a[i]), s += a[i];
        if (chk(s)) {
            printf("%d\n", n);
            for (int i = 1; i <= n; i++) printf("%d ", i);
            puts("");
        } else {
            for (int i = 1; i <= n; i++) {
                if (chk(s - a[i])) {
                    printf("%d\n", n - 1);
                    for (int j = 1; j <= n; j++) 
                        if (j != i) printf("%d ", j);
                    puts("");
                    break;
                }
            }
        }
    }
    return 0;
}
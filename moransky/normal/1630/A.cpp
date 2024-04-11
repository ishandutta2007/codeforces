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

int n, k;

int main() {
    int T; read(T);
    while (T--) {
        read(n), read(k);
        if (n == 4 && k == 3) { puts("-1"); continue; }
        if (k == 0) {
            for (int i = 0; i < n / 2; i++) printf("%d %d\n", i, n - i - 1);
        } else if (k == n - 1) {
            printf("%d %d\n", n - 1, n - 2);
            printf("%d %d\n", 0, 1);
            printf("%d %d\n", n - 3, 3);
            printf("%d %d\n", n - 4, 2);
            for (int i = 4; i < n / 2; i++) {
                if (i != k && i != n - 1 - k)
                    printf("%d %d\n", i, n - i - 1);
            }
        } else  {
            printf("%d %d\n", n - 1, k);
            printf("%d %d\n", 0, n - 1 - k);
            for (int i = 1; i < n / 2; i++) {
                if (i != k && i != n - 1 - k)
                    printf("%d %d\n", i, n - i - 1);
            }
        }
    }
    return 0;
}
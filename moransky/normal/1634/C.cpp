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

const int N = 505;

int n, k, a[N][N];
 
int main() {
    int T; read(T);
    while (T--) {
        int n, k; read(n), read(k);
        if (k == 1) {
            puts("YES");
            for (int i = 1; i <= n; i++) printf("%d\n", i);
            continue;
        }
        if ((n & 1)) {
            puts("NO");
            continue;
        }
        if (n % 2 == 0) {
            int c = 0;
            for (int i = 1; i <= n; i += 2) {
                for (int j = 1; j <= k; j++) {
                    a[i][j] = ++c;
                    a[i + 1][j] = ++c;
                }
            }
        } else {
            int c = 0;
            for (int i = 1; i <= k; i += 2) {
                for (int j = 1; j <= n; j++) {
                    a[j][i] = ++c;
                    a[j][i + 1] = ++c;
                }
            }
        }
        puts("YES");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) printf("%d ", a[i][j]);
            puts("");
        }
    }
    return 0;
}
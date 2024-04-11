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

const int N = 75;

int n, a[N];
 
int main() {
    int T; read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]);
        if (n == 1) {
            puts("0");
            continue;
        }
        int ans = 2e9;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int c = 0;
                double d = ((double)a[j] - a[i]) / (j - i);
                for (int k = 1; k <= n; k++) {
                    if (k == i || k == j) continue;
                    if (fabs(((double)a[k] - a[i]) / (k - i) - d) > 1e-6)
                        c++;
                }
                chkMin(ans, c);
            }
        } 
        printf("%d\n", ans);
    }
    return 0;
}
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

int n, a, b, q[N], t;
 
int main() {
    int T; read(T);
    while (T--) {
        read(n), read(a), read(b);
        if (a == 0 && b == 0) {
            for (int i = 1; i <= n; i++) printf("%d ", i);
            puts("");
            continue;
        }
        if (abs(a - b) > 1 || (a + b) > n - 2) puts("-1");
        else {
            t = 0;
            int L = 1, R = n;
            int now = 0;
            if (b > a) {
                q[++t] = R--;
                now = 0;
            } else {
                q[++t] = L++;
                now = 1;
            }
            while (L <= R) {
                if (!a && !b) {
                    if (now == 0)q[++t] = L++;
                    else q[++t] = R--;
                    continue;
                }
                if (now == 0) q[++t] = L++, b--;
                else q[++t] = R--, a--;
                if (a || b) now ^= 1;
            }
            for (int i = 1; i <= t; i++) printf("%d ", q[i]);
            puts("");
        }
    }
    return 0;
}
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
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

const int N = 2e5 + 5;

ll ans[N];
int isp[N];
int T, n;

ll query(int a, int b) {
    printf("? %d %d\n", a, b);
    fflush(stdout);
    ll ans; read(ans); return ans;
}

inline int R() { return (rand() << 15) ^ rand(); }

int main() {
    srand(time(0));
    for (int i = 2; i <= 200000; i++) {
        for (int j = i * 2; j <= 200000; j += i) isp[j] = 1;
    }
    read(T);
    while (T--) {
        read(n);
        if (n <= 99) {
            for (int i = 1; i <= n; i++) ans[i] = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    ll tem = query(i, j);
                    ans[i] = __gcd(ans[i], tem);
                    ans[j] = __gcd(ans[j], tem);
                }
            }
            if (n == 3) {
                ll a[3] = {ans[1], ans[2], ans[3]};
                sort(a, a + 3);
                if (a[0] + 1 != a[1] || a[1] + 1 != a[2]) {
                    if (ans[1] == a[2]) ans[1] /= 2;
                    if (ans[2] == a[2]) ans[2] /= 2;
                    if (ans[3] == a[2]) ans[3] /= 2;
                }
            }
            printf("! ");
            for (int i = 1; i <= n; i++) print(ans[i], i == n ? '\n' : ' ');
            fflush(stdout);
            continue;
        }
        int maxn = 0, pos = 0;
        for (int _ = 1; _ <= 250; _++) {
            int x = R() % n + 1;
            ll val = 0;
            for (int i = 1; i <= 20; i++) {
                int y = R() % n + 1;
                while (x == y) y = R() % n + 1;
                ll tem = query(x, y);
                val = __gcd(val, tem);
            }
            if (val > maxn && !isp[val]) {
                maxn = val;
                pos = x;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (i == pos) ans[i] = maxn;
            else ans[i] = query(i, pos) / maxn;
        }
        printf("! ");
        for (int i = 1; i <= n; i++) print(ans[i], i == n ? '\n' : ' ');
        fflush(stdout);
    }
    return 0;
}
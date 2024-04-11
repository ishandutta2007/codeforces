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

const int md = 998244353;

inline int add(int x, int y) {
    if (x + y >= md) return x + y - md;
    return x + y;
}

inline void addx(int &x, int y) {
    x += y;
    if (x >= md) x -= md;
}

inline int sub(int x, int y) {
    if (x < y) return x - y + md;
    return x - y;
}

inline void subx(int &x, int y) {
    x -= y;
    if (x < 0) x += md;
}

inline int mul(int x, int y) { return 1ull * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

const int N = 2e5 + 5;

char c[N];
int dp1[N][8], dp2[N][8], res[3];
int n, ans, val;

int main() {
    scanf("%s", c + 1); n = strlen(c + 1);
    for (int i = 1; i <= n; i++) {
        val = mul(val, 2);
        if (c[i] == '1') val = add(val, 1);
    }
    val = add(val, 1);
    ans = mul(mul(val, val), val);
    dp1[0][7] = dp2[0][7] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                memset(res, 0, sizeof(res));
                int go = 0;
                for (int t = 0; t < 3; t++) {
                    if (((j >> t) & 1) && ((k >> t) & 1)) go |= (1 << t);
                    if ((k >> t) & 1) {
                        for (int _ = 0; _ < 3; _++) {
                            if (t == _) continue;
                            res[_] ^= 1;
                        }
                    }
                }
                if (go && c[i] == '0') continue;
                if (c[i] == '0') go = j;
                if (res[0] && !res[2]) {

                } else {
                    dp1[i][go] = add(dp1[i][go], dp1[i - 1][j]);
                }
                if (res[1] == res[2]) {
                    dp2[i][go] = add(dp2[i][go], dp2[i - 1][j]);
                }
            }
            // fprintf(stderr, "dp1[%d][%d] = %d\n", i - 1, j, dp1[i - 1][j]);
        }
    }
    for (int i = 0; i < 8; i++) {
        // fprintf(stderr, "dp1[%d][%d] = %d, dp2[%d][%d] = %d\n", n, i, dp1[n][i], n, i, dp2[n][i]);
        ans = sub(ans, mul(dp1[n][i], 3));
        ans = add(ans, mul(dp2[n][i], 3));
    }
    ans = sub(ans, val);
    print(ans, '\n');
    return 0;
}
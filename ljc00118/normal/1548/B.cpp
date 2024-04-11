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

ll a[N], val[N], tval[N];
int pos[N], tpos[N];
int T, n, len, ans;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]);
        if (n == 1) {
            print(1, '\n');
            continue;
        }
        for (int i = 1; i < n; i++) a[i] = abs(a[i] - a[i + 1]);
        --n; len = 0; ans = 1;
        for (int i = 1; i <= n; i++) {
            int tem = 0;
            for (int j = 1; j <= len; j++) {
                ll d = gcd(val[j], a[i]);
                if (d == 1) continue;
                if (!tem || d != tval[tem]) {
                    ++tem;
                    tval[tem] = d;
                    tpos[tem] = pos[j];
                }
            }
            if (a[i] != 1) {
                if (!tem || a[i] != tval[tem]) {
                    ++tem;
                    tval[tem] = a[i];
                    tpos[tem] = i;
                }
            }
            memcpy(val, tval, (tem + 1) * 8);
            memcpy(pos, tpos, (tem + 1) * 8);
            len = tem;
            if (len) ans = max(ans, i - pos[1] + 2);
        }
        print(ans, '\n');
    }
    return 0;
}
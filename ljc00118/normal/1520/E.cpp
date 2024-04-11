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

const int N = 1e6 + 5;

char c[N];
int T, n;

int main() {
    read(T);
    while (T--) {
        read(n);
        scanf("%s", c + 1);
        int cnt = 0; ll ans = 0;
        for (int i = 1; i <= n; i++) cnt += (c[i] == '*');
        if (!cnt) {
            print(0, '\n');
            continue;
        }
        int cnt2 = 0, pos = 0;
        for (int i = 1; i <= n; i++) {
            cnt2 += (c[i] == '*');
            if (cnt2 == (cnt + 1) / 2) {
                pos = i;
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (c[i] == '*') {
                ans += abs(i - pos);
            }
        }
        int c1 = (cnt - 1) / 2, c2 = cnt - 1 - c1;
        ans -= 1ll * c1 * (c1 + 1) / 2;
        ans -= 1ll * c2 * (c2 + 1) / 2;
        print(ans, '\n');
    }
    return 0;
}
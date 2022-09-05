#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
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

const int N = 105;

int a[N], s[N];
int n, ans = 10000;

int main() {
    read(n);
    if (n >= 100) {
        print(1, '\n');
        return 0;
    }
    for (int i = 1; i <= n; i++) read(a[i]), s[i] = s[i - 1] ^ a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int cando = 0;
            for (int k = i + 1; k <= j; k++) {
                int s1 = s[k - 1] ^ s[i - 1];
                int s2 = s[j] ^ s[k - 1];
                if (s1 > s2) {
                    cando = 1;
                    break;
                }
            }
            if (cando) ans = min(ans, j - i - 1);
        }
    }
    if (ans == 10000) ans = -1;
    print(ans, '\n');
    return 0;
}
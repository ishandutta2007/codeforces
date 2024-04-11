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

const int N = 3e5 + 5;

char c[N];
int T, n;

int main() {
    read(T);
    while (T--) {
        read(n); scanf("%s", c + 1);
        bool cando1 = 1, cando2 = 1;
        int fir = 0;
        for (int i = 1; i <= n; i++) {
            if (c[i] != '-' && c[i] != '<') cando1 = 0;
            if (c[i] != '-' && c[i] != '>') cando2 = 0;
            if (c[i] != '-') fir = i;
        }
        if (cando1 || cando2) {
            print(n, '\n');
            continue;
        }
        int ans = 0;
        for (int l = fir % n + 1, r = -1; l != fir; l = r % n + 1) {
            r = l;
            if (c[l] != '-') continue;
            while (c[r % n + 1] == '-') r = r % n + 1;
            if (l <= r) ans += r - l + 2;
            else ans += r + n - l + 2;
        }
        print(ans, '\n');
    }
    return 0;
}
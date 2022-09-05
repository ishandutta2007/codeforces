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

const int N = 1e6 + 5;

int isp[N], s[N];
int T, n;

int main() {
    for (int i = 2; i <= 1000000; i++) {
        if (!isp[i]) {
            for (int j = i + i; j <= 1000000; j += i) isp[j] = 1;
        }
        s[i] = s[i - 1] + (1 - isp[i]);
    }
    read(T);
    while (T--) {
        read(n);
        int lim = ceil(sqrt(n + 0.5));
        print(s[n] - s[lim - 1] + 1, '\n');
    }
    return 0;
}
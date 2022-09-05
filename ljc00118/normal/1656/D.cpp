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

int T; ll n;

int main() {
    read(T);
    while (T--) {
        read(n); ll m = 1, tmp = n;
        while (n % 2 == 0) {
            n /= 2;
            m *= 2;
        }
        if (n == 1) {
            print(-1, '\n');
            continue;
        }
        if (m * 2 <= tmp * 2 / (m * 2 + 1) + 1 && (m * 2) * (m * 2 + 1) / 2 <= tmp) print(m * 2, '\n');
        else if (n <= tmp * 2 / (n + 1) + 1 && n * (n + 1) / 2 <= tmp) print(n, '\n');
        else assert(0);
    }
    return 0;
}
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

int T, x, y, _x, _y;

int main() {
    read(T);
    while (T--) {
        read(x); read(y); read(_x); read(_y);
        if (x == _x && y == _y) {
            print(0, '\n');
        } else if (x == _x || y == _y) {
            print(abs(_x + _y - x - y), '\n');
        } else {
            print(abs(x - _x) + abs(y - _y) + 2, '\n');
        }
    }
    return 0;
}
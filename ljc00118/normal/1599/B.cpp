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

char c[233];
ll n, a, b;
int T;

int main() {
    read(T);
    while (T--) {
        read(n); read(a); read(b);
        int d1, d2;
        scanf("%s", c + 1);
        d1 = (c[1] == 'r');
        scanf("%s", c + 1);
        d2 = (c[2] == 'r');
        if (a == 1) d1 = 1;
        if (a == n) d1 = 0;
        if (b == 1) d2 = 1;
        if (b == n) d2 = 0;
        if (a == b) {
            if (d1 == d2) {
                if (a == n - 1) {
                    print(0, '\n');
                } else if (a == 0) {
                    print(n - 1, '\n');
                } else if (d1 == 1) {
                    print(0, '\n');
                } else {
                    print(n - 1, '\n');
                }
            } else {
                if (d1 == 0) print(n - 1, '\n');
                else print(0, '\n');
            }
            continue;
        }
        int ans = 0;
        if (a > b) {
            ans = 1;
            swap(a, b);
            swap(d1, d2);
        }
        if (d1 == 0 && d2 == 0) {
            int dis = 2 * n - a - b - 1;
            if (dis & 1) ans ^= 1;
        }
        if (d1 == 0 && d2 == 1) {
            int dis = b - a - 1;
            if (dis & 1) ans ^= 1;
        }
        if (d1 == 1 && d2 == 0) {
            int dis = a - 1 + n - b + n - 2;
            if (dis & 1) ans ^= 1;
        }
        if (d1 == 1 && d2 == 1) {
            int dis = a + b - 3;
            if (dis & 1) ans ^= 1;
        }
        if (ans == 0) print(0, '\n');
        else print(n - 1, '\n');
    }
    return 0;
}
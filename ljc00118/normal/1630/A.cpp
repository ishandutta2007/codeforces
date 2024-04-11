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

int T, n, k;

int main() {
    read(T);
    while (T--) {
        read(n); read(k);
        if (k != n - 1) {
            for (int i = 1; i < n / 2; i++) {
                if (i == k || (i ^ (n - 1)) == k) continue;
                print(i, ' '); print(i ^ (n - 1), '\n');
            }
            print(k, ' '); print(n - 1, '\n');
            if (k != 0) {
                print(k ^ (n - 1), ' '); print(0, '\n');
            }
            continue;
        }
        if (n <= 4) {
            print(-1, '\n');
            continue;
        }
        print(0, ' '); print(1, '\n');
        print(n - 2, ' '); print(n - 1, '\n');
        print(2, ' '); print(n - 4, '\n');
        print(3, ' '); print(n - 3, '\n');
        for (int i = 4; i < n / 2; i++) {
            print(i, ' '); print(i ^ (n - 1), '\n');
        }
    }
    return 0;
}
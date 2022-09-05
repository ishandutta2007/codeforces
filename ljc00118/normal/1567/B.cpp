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
    while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
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

int s[N];
int T, n, m;

int main() {
    for (int i = 1; i <= 300000; i++) s[i] = s[i - 1] ^ i;
    read(T);
    while (T--) {
        int a, b;
        read(a); read(b);
        if (s[a - 1] == b) print(a, '\n');
        else if ((s[a - 1] ^ a) == b) print(a + 2, '\n');
        else print(a + 1, '\n');
    }
    return 0;
}
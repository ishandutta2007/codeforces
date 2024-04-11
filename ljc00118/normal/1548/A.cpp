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

int cnt[N];
int n, m, ans;

void add(int x, int y, int z) {
    if (x > y) swap(x, y);
    ans += (cnt[x] > 0);
    cnt[x] += z;
    ans -= (cnt[x] > 0);
}

int main() {
    read(n); read(m); ans = n;
    for (int i = 1; i <= m; i++) {
        int u, v;
        read(u); read(v);
        add(u, v, 1);
    }
    read(m);
    for (int i = 1; i <= m; i++) {
        int opt; read(opt);
        if (opt == 1) {
            int u, v;
            read(u); read(v);
            add(u, v, 1);
        }
        if (opt == 2) {
            int u, v;
            read(u); read(v);
            add(u, v, -1);
        }
        if (opt == 3) print(ans, '\n');
    }
    return 0;
}
#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
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

const int N = 1e6 + 5;

int cnt[N], c[N];
int n, maxn = 1, qaq;

bool check(int x, int y, int _x, int _y) {
    if(_x <= 0 || _y <= 0 || _x > x || _y > y) return 0;
    memset(c, 0, sizeof(c));
    for(register int i = 1; i <= x; i++)
        for(register int j = 1; j <= y; j++)
            c[abs(i - _x) + abs(j - _y)]++;
    for(register int i = 0; i <= qaq; i++)
        if(cnt[i] != c[i]) return 0;
    return 1;
}

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) { int a; read(a); cnt[a]++; qaq = max(qaq, a); }
    while(cnt[maxn] == (maxn << 2)) maxn++;
    for(register int i = 2 * maxn - 1; i * i <= n; i++) {
        if(n % i == 0) {
            int x = i, y = n / i, _x = maxn, _y = x + y - qaq - maxn;
//			fprintf(stderr, "x = %d, y = %d, _x = %d, _y = %d\n", x, y, _x, _y);
            if(check(x, y, _x, _y)) { printf("%d %d\n%d %d\n", x, y, _x, _y); return 0; }
            if(check(x, y, _y, _x)) { printf("%d %d\n%d %d\n", x, y, _y, _x); return 0; }
        }
    }
    printf("-1\n");
    return 0;
} // qaq
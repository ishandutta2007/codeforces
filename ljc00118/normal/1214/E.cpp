#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e5 + 5;

int d[N], id[N << 1], t[N];
int n, now;

bool cmp(int x, int y) { return d[x] > d[y]; }

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(d[i]), t[i] = i;
    sort(t + 1, t + n + 1, cmp); now = n;
    for(register int i = 1; i <= n; i++) id[i] = t[i] * 2 - 1;
    for(register int i = 1; i < n; i++) print(t[i] * 2 - 1, ' '), print(t[i + 1] * 2 - 1, '\n');
    for(register int i = 1; i <= n; i++) {
        int u = t[i];
        if(now > d[u] + i - 1) print(u * 2, ' '), print(id[i + d[u] - 1], '\n');
        else {
            id[++now] = u * 2;
            // fprintf(stderr, "u = %d, id[now - 1] = %d\n", u, id[now - 1]);
            print(id[now], ' '); print(id[now - 1], '\n');
        }
    }
    return 0;
}
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

const int N = 205;

int a[N], pre[N], nxt[N], f[N];
int T, n;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) {
            read(a[i]);
            pre[a[i]] = i;
            f[i] = i;
        }
        for (int i = 1; i <= n; i++) {
            nxt[i] = pre[i];
            f[find(i)] = find(nxt[i]);
        }
        for (int i = 2; i <= n; i++) {
            if (find(i) != find(i - 1)) {
                int tmp = nxt[i - 1];
                nxt[i - 1] = pre[i];
                nxt[i] = tmp;
                f[find(i)] = find(i - 1);
            }
        }
        int now = 1;
        for (int i = 1; i <= n; i++) {
            print(now, i == n ? '\n' : ' ');
            now = nxt[now];
        }
    }
    return 0;
}
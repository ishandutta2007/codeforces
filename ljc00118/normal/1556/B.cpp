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

const ll INF = 1e18;
const int N = 1e5 + 5;

int a[N], b[N];
int T, n, len; ll ans;

void solve(int fir) {
    if (len != (n - fir) / 2 + 1) return;
    ll sum = 0;
    for (int i = fir, j = 1; i <= n; i += 2, j++) sum += abs(i - b[j]);
    ans = min(ans, sum);
}

int main() {
    read(T);
    while (T--) {
        read(n); len = 0;
        for (int i = 1; i <= n; i++) {
            read(a[i]);
            if (a[i] & 1) b[++len] = i;
        }
        if (n == 1) {
            print(0, '\n');
            continue;
        }
        ans = INF;
        solve(1); solve(2);
        if (ans == INF) ans = -1;
        print(ans, '\n');
    }
    return 0;
}
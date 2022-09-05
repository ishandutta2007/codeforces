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

const int N = 1e5 + 5;

multiset <int> dps;
int dp[N], a[N];
int n, all;

int main() {
    read(n);
    for (int i = 0; i <= n; i++) dps.insert(0);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        int mx = dp[a[i]] + all;
        dps.erase(dps.find(dp[a[i]]));
        mx = max(mx, *dps.rbegin() + all + 1);
        dps.insert(dp[a[i]]);
        if (a[i] != a[i - 1]) ++all;
        if (dp[a[i - 1]] + all < mx) {
            dps.erase(dps.find(dp[a[i - 1]]));
            dp[a[i - 1]] = mx - all;
            dps.insert(dp[a[i - 1]]);
        }
    }
    print(*dps.rbegin() + all, '\n');
    return 0;
}
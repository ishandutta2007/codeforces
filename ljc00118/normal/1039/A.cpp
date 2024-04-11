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

ll a[N], ans[N], l[N], r[N];
int x[N], s[N];
int n; ll t;

int main() {
    read(n); read(t);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= n; i++) {
        read(x[i]);
        if (x[i] < i || (i > 1 && x[i] < x[i - 1])) {
            printf("No\n");
            return 0;
        }
        ++s[i + 1]; --s[x[i] + 1];
    }
    for (int i = 1; i <= n; i++) {
        l[i] = a[i] + t;
        r[i] = 3e18;
    }
    for (int i = 2; i <= n; i++) {
        s[i] += s[i - 1];
        if (s[i]) l[i - 1] = a[i] + t;
        else r[i - 1] = a[i] + t - 1;
    }
    for (int i = 1; i <= n; i++) {
        l[i] = max(l[i], ans[i - 1] + 1);
        if (l[i] > r[i]) {
            printf("No\n");
            return 0;
        }
        ans[i] = l[i];
    }
    for (int i = 1; i <= n; i++) {
        if (x[i] < n && a[x[i] + 1] + t <= ans[x[i]]) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    for (int i = 1; i <= n; i++) print(ans[i], i == n ? '\n' : ' ');
    return 0;
}
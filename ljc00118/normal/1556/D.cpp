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

const int N = 1e4 + 5;

int ans[N], val[N];
int n, k;

int query(int a, int b) {
    int ans = 0, qwq;
    printf("or %d %d\n", a, b);
    fflush(stdout);
    read(qwq); ans += qwq;
    printf("and %d %d\n", a, b);
    fflush(stdout);
    read(qwq); ans += qwq;
    return ans;
}

int main() {
    read(n); read(k);
    ll a = query(1, 2), b = query(2, 3), c = query(1, 3);
    ll sum = (a + b + c) / 2;
    ans[1] = sum - b; ans[2] = sum - c; ans[3] = sum - a;
    for (int i = 4; i <= n; i++) {
        int x = query(1, i);
        ans[i] = x - ans[1];
    }
    sort(ans + 1, ans + n + 1);
    printf("finish %d\n", ans[k]);
    fflush(stdout);
    return 0;
}
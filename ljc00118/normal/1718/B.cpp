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

const int N = 105;

priority_queue <int> Q;
ll f[100], s[100];
int T, n;

int main() {
    f[1] = f[2] = 1;
    s[1] = 1; s[2] = 2;
    for (int i = 3; i <= 60; i++) {
        f[i] = f[i - 1] + f[i - 2];
        s[i] = s[i - 1] + f[i];
        // printf("f[%d] = %lld\n", i, f[i]);
    }
    read(T);
    while (T--) {
        while (!Q.empty()) Q.pop();
        read(n);
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            int x; read(x);
            sum += x; Q.push(x);
        }
        int pos = 0;
        for (int i = 1; i <= 60; i++) {
            if (sum == s[i]) {
                pos = i;
                break;
            }
        }
        if (!pos) {
            printf("NO\n");
            continue;
        }
        int las = 0, ans = 1;
        for (int i = pos; i >= 1; i--) {
            if (Q.empty()) {
                ans = 0;
                break;
            }
            int t = Q.top(); Q.pop();
            if (las) Q.push(las);
            if (t < f[i]) {
                ans = 0;
                break;
            }
            las = t - f[i];
        }
        printf("%s\n", ans ? "YES" : "NO");
    }
    return 0;
}
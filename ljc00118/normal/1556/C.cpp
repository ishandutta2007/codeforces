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

const int N = 1005;

int a[N];
int n; ll ans;

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= n; i += 2) {
        ll now = 0, minn = a[i];
        for (int j = i; j < n; j++) {
            if (j % 2 == 0) now -= a[j];
            else now += a[j];
            minn = min(minn, now);
            if (minn < 0) break;
            if (j % 2 == 1) {
                ll tem = min(minn, (ll)a[i] - 1);
                ll tnow = now - tem;
                // fprintf(stderr, "tem = %lld, tnow = %lld\n", tem, tnow);
                ans += max(0ll, min(tem + 1, a[j + 1] + 1 - max(1ll, tnow)));
            }
        }
    }
    print(ans, '\n');
    return 0;
}
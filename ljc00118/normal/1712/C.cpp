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

int a[N], l[N], r[N], s1[N], s2[N];
int T, n;

int main() {
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) l[i] = r[i] = s1[i] = s2[i] = 0;
        for (int i = 1; i <= n; i++) {
            read(a[i]);
            if (!l[a[i]]) l[a[i]] = i;
            r[a[i]] = i;
        }
        for (int i = 1; i <= n; i++) {
            if (r[i]) {
                ++s1[l[i]]; --s1[r[i]];
                ++s2[r[i]];
            }
        }
        for (int i = 1; i <= n; i++) {
            s1[i] += s1[i - 1];
            s2[i] += s2[i - 1];
        }
        int ans = s2[n];
        for (int i = n; i >= 0; i--) {
            if (!s1[i]) ans = min(ans, s2[i]);
            if (i != 0 && i < n && a[i] > a[i + 1]) break;
        }
        print(ans, '\n');
    }
    return 0;
}
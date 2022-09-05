#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
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

ull seed = 416;
inline ull R() {
    seed ^= seed << 17;
    seed ^= seed >> 13;
    seed ^= seed << 5;
    return seed;
}

map <ull, ll> s1, s2;
ull s[N];
int ss[N];
int n, m; ll ans;

int main() {
    read(n); read(m);
    for (int i = 1; i <= n; i++) {
        int l, r;
        read(l); read(r);
        ull rng = R();
        s[l + 1] ^= rng; s[r + 1] ^= rng;
        ++ss[l]; --ss[r + 1];
    }
    for (int i = 1; i <= m; i++) ss[i] += ss[i - 1];
    for (int i = 1; i <= m; i++) s[i] ^= s[i - 1];
    for (int i = 1; i <= m; i++) s[i] ^= s[i - 1];
    for (int i = 1, j = 1; i <= m; i++) {
        if (ss[i]) {
            while (j <= i) {
                ++s1[s[j]];
                s2[s[j]] += j - 1;
                ++j;
            }
        }
        ans += s1[s[i]] * i - s2[s[i]];
    }
    print(ans, '\n');
    return 0;
}
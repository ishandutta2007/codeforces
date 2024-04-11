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

// f[1500000] : 354898000000
// f[1500001] : 677449000001
const ll md = 1000000000000ll;
const ll f0 = 354898000000ll, f1 = 677449000001ll;
const ll L = 667573500000ll;

int main() {
    // for (ll i = 2, a = 0, b = 1; ; i++) {
    //     ll c = (a + b) % md;
    //     a = b; b = c;
    //     if (a % 1000000 == 0 || b % 1000000 == 0) {
    //         printf("%lld : %lld\n", i, b);
    //     }
    // }
    // for (ll i = 1500001, f = 1; ; i += 1500000) {
    //     f = (__int128)f1 * f % md;
    //     if (f == 1000001) {
    //         printf("%lld : %lld\n", i, f);
    //         break;
    //     }
    // }
    int n, a, d;
    read(n); read(a); read(d);
    print(L * a + 1, ' '); print(L * d, '\n');
    return 0;
}
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

mt19937 rng(time(0));
char c[10];
ll n; int k, cnt;

int query(ll l, ll r) {
    ++cnt;
    if (cnt > 4500) assert(0);
    printf("%lld %lld\n", l, r);
    fflush(stdout);
    scanf("%s", c + 1);
    return c[1] == 'Y';
}

int main() {
    read(n); read(k);
    ll l = 1, r = n;
    while (1) {
        if (r - l + 1 <= 60) {
            ll x = l + rng() % (r - l + 1);
            if (query(x, x)) return 0;
        } else {
            ll mid = (l + r) / 2;
            if (query(l, mid)) r = mid;
            else l = mid + 1;
        }
        l = max(1ll, l - k); r = min(n, r + k);
    }
    return 0;
}
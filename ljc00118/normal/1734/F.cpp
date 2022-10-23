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

int T;
ll n, m;

pair <ll, ll> calc(ll n, ll m) {
    ll a0 = 1, a1 = 0, b0 = 0, b1 = 0;
    for (int i = 0; i <= 60; i++) {
        if ((m >> i) & 1) {
            ll t0 = a0, t1 = a1;
            a0 += (b1 - b0);
            a1 += (b0 - b1);
            swap(b0, b1);
            if ((1ll << i) < n) {
                a0 += t1; b0 += t1;
                a1 += t0; b1 += t0;
            }
        } else {
            if ((1ll << i) >= n) return make_pair(a0, a1);
            a0 *= 2; a1 *= 2;
            a0 += (b1 - b0);
            a1 += (b0 - b1);
            swap(b0, b1);
        }
    }
    return make_pair(a0, a1);
}

int main() {
    read(T);
    while (T--) {
        read(n); read(m);
        ll s = 0, ans = 0;
        int cnt = 0;
        for (int i = 60; i >= 0; i--) {
            if ((m >> i) & 1) {
                pair <ll, ll> now = calc(1ll << i, s + n);
                if ((__builtin_popcountll(s + n) + cnt) % 2 == 0) ans += now.second;
                else ans += now.first;
                s |= (1ll << i); ++cnt;
            }
        }
        print(ans, '\n');
    }
    return 0;
}
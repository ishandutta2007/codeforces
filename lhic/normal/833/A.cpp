#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

int ch(ll x) {
    ll l = 0;
    ll r = 1000000;
    while (r - l > 1) {
        ll mid = (l + r) >> 1;
        if (mid * mid * mid <= x)
            l = mid;
        else
            r = mid;
    }
    if (l * l * l == x)
        return 1;
    return 0;
}

void solve() {
    ll a, b;
    scanf("%lld%lld", &a, &b);
    ll g = __gcd(a, b);
    a /= g;
    b /= g;
    ll x = a * b;
    if (g % x != 0) {
        printf("No\n");
    }
    else {
        x = g / x;
        if (ch(x))
            printf("Yes\n");
        else
            printf("No\n");
    }
}

int main() {
    int tt;
    scanf("%d", &tt);
    for (int i = 0; i < tt; ++i) {
        solve();
    }
    return 0;
}
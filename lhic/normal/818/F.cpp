#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

int main() {
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        ll n;
        scanf("%lld", &n);
        ll l = 0;
        ll r = 2 * n;
        while (r - l > 1) {
            ll m = (l + r) >> 1;
            ll k = (m + 1) / 2;
            ll x = n - k;
            if (k <= n - 1 && x * (x - 1) / 2 + k >= m)
                l = m;
            else
                r = m;
        }
        printf("%lld\n", l);
    }
    return 0;
}
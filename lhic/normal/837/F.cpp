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

ll a[220000];
ll k;
int n;

int check() {
    for (int i = 0; i < n; ++i)
        if (a[i] >= k)
            return 1;
    return 0;
}

const ll MX = 8e18;

ll add(ll a, ll b) {
    if (MX - a <= b)
        return MX;
    return a + b;
}

ll mult(ll a, ll b) {
    if (MX / a < b)
        return MX;
    return a * b;
}

int check2(ll x) {
    ll cur = 0;
    ll now = 1;
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            now = mult(now, x + i);
            now /= i;
        }
        cur = add(cur, mult(now, a[i]));
    }
    if (cur >= k)
        return 1;
    return 0;
}

int main() {
    scanf("%d%lld", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%lld", a + i);
    int st = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] != 0) {
            st = i;
            break;
        }
    rotate(a, a + st, a + n);
    n -= st;
    if (check()) {
        cout << 0 << "\n";
        return 0;
    }
    if (n >= 5) {
        for (int i = 0;; ++i) {
            if (check()) {
                cout << i << "\n";
                return 0;
            }
            for (int i = 0; i < n - 1; ++i)
                a[i + 1] += a[i];
        }
    }
    else {
        reverse(a, a + n);
        ll r = 2e18;
        ll l = -1;
        while (r - l > 1) {
            ll mid = (l + r) >> 1;
            if (check2(mid))
                r = mid;
            else
                l = mid;
        }
        cout << r + 1 << "\n";
    }
    return 0;
}
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

const int LOG = 20;
int n;
ll k;
ll a[120000];
ll up[LOG][120000];


int main() {
    scanf("%d%lld", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%lld", a + i);
    for (int i = 0; i < n; ++i)
        up[0][i] = a[i] % k;
    for (int i = 1; i < LOG; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j + (1 << (i - 1)) < n)
                up[i][j] = (up[i - 1][j] * up[i - 1][j + (1 << (i - 1))]) % k;
            else
                up[i][j] = up[i - 1][j];
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll cur = 1 % k;
        int now = i;
        for (int j = LOG - 1; j >= 0 && now < n; --j) {
            if ((cur * up[j][now]) % k)
                cur = (cur * up[j][now]) % k, now += (1 << j);
        }
        if (now < n) {
            ans += n - now;
        }
    }
    cout << ans << "\n";
    return 0;
}
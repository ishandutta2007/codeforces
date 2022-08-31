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
const ll MOD = 1e9 + 7;

int n;
ll a[310000];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", a + i);
    sort(a, a + n);
    ll ans = 0;
    ll now = 1;
    for (int i = 0; i < n; ++i) {
        ans = (ans + a[i] * now)  % MOD;
        now = (now * 2) % MOD;
    }
    now = 1;
    for (int i = n - 1; i >= 0; --i) {
        ans = (ans - a[i] * now + MOD * MOD)  % MOD;
        now = (now * 2) % MOD;
    }
    cout << ans << "\n";
    return 0;
}
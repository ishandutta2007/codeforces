#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) (a).begin(), (a).end()
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    ll k;
    cin >> n >> k;
    vec<ll> a;
    bool was = false;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        was |= (x != 0);
        if (was) {
            a.push_back(x);
        }
    }
    n = len(a);
    if (*max_element(all(a)) >= k) {
        cout << "0\n";
        return 0;
    }
    if (n > 3) {
        int ans = 0;
        while (*max_element(all(a)) < k) {
            ans++;
            for (int i = 1; i < n; i++) {
                a[i] += a[i - 1];
            }
        }
        cout << ans << '\n';
        return 0;
    }
    if (n == 3) {
        using int128 = __int128;
        ll x = a[0], y = a[1], z = a[2];
        ll l = -1, r = 1e10;
        while (r - l > 1) {
            ll m = (l + r) / 2;
            if (int128(m) * x + y >= k || int128(m) * (m + 1) / 2 * x + m * y + z >= k) {
                r = m;
            } else {
                l = m;
            }
        }
        cout << r << '\n';
        // x, y, z
        // x, 1 * x + y, x + y + z
        // x, 2 * x + y, 3 * x + 2 * y + z
        // x, 3 * x + y, 6 * x + 3 * y + z
        // x, 4 * x + y, 10 * x + 4 * y + z
        // x, 5 * x + y, 15 * x + 5 * y + z
        // x, 6 * x + y, 21 * x + 6 * y + z
        // x, 7 * x + y, 28 * x + 7 * y + z
        // x, 8 * x + y, 36 * x + 8 * y + z
        // x, 9 * x + y, 45 * x + 9 * y + z
        // x, 10 * x + y, 55 * x + 10 * y + z
        // 1, 3, 6, 10, 15, 21, 28, 36, 45, 55
        return 0;
    }
    ll x = a[0], y = a[1];
    cout << (k - y + x - 1) / x << '\n';
}
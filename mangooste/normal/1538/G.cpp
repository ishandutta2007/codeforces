#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
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

void solve() {
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    if (a == b) {
        cout << min(x, y) / a << '\n';
        return;
    }

    if (a > b)
        swap(a, b);

    ll l = 0, r = max(x, y) / a + 1;
    while (r - l > 1) {
        ll mid = (l + r) >> 1;
        ll low = max(0ll, (b * mid - x + b - a - 1) / (b - a));
        ll high = min(mid, (y - a * mid) / (b - a));
        (low <= high && y >= a * mid ? l : r) = mid;
    }
    cout << l << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}
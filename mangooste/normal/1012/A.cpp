#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

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



int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vec<int> a(2 * n);
    for (auto &x : a)
        cin >> x;

    sort(all(a));
    ll ans = LLONG_MAX;

    for (int i = n - 1; i < 2 * n - 1; i++) {
        int mn = n - 1 + (i == (n - 1));
        ans = min(ans, ll(a[i] - a[0]) * (a.back() - a[mn]));
    }

    for (int i = 1; i + n - 1 < 2 * n - 1; i++)
        ans = min(ans, ll(a.back() - a[0]) * (a[i + n - 1] - a[i]));

    cout << ans << '\n';
}
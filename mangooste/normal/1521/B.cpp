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

inline void solve() {
    int n;
    cin >> n;
    vec<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    if (n == 1) {
        cout << "0\n";
        return;
    }
    vec<ar<int, 4>> ops;
    int where_min = min_element(all(a)) - a.begin();
    int big = a[where_min];
    while (big < n) {
        big += a[where_min];
    }
    big *= 2;
    big--;
    cout << n - 1 << '\n';
    for (int i = where_min - 1; i >= 0; i--) {
        cout << i + 1 << ' ' << where_min + 1 << ' ' << big - (where_min - 1 - i) << ' ' << a[where_min] << '\n';
    }
    for (int i = where_min + 1; i < n; i++) {
        cout << i + 1 << ' ' << where_min + 1 << ' ' << big - (i - where_min - 1) << ' ' << a[where_min] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
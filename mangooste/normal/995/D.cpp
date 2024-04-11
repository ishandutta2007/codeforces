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
    cout << fixed << setprecision(10);

    int n, q;
    cin >> n >> q;
    const int MASK = (1 << n);

    vec<int> a(MASK);
    for (auto &x : a)
        cin >> x;

    ll sum = accumulate(all(a), 0ll);

    auto solve = [&]() {
        cout << ld(sum) / MASK << '\n';
    };

    solve();

    while (q--) {
        int pos, value;
        cin >> pos >> value;

        sum -= a[pos];
        a[pos] = value;
        sum += a[pos];

        solve();
    }
}
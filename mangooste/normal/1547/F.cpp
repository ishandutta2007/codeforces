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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    set<pair<int, int>> st;
    set<pair<int, int>> nst;

    auto relax = [&](int pos) {
        int g = gcd(a[pos], a[(pos + 1) % n]);
        if (g != a[pos])
            nst.emplace(pos, g);
    };

    for (int i = 0; i < n; i++)
        relax(i);

    swap(st, nst);
    int answer = 0;
    while (len(st)) {
        answer++;
        for (const auto [pos, val] : st)
            a[pos] = val;

        while (len(st)) {
            int pos = st.begin()->first;
            st.erase(st.begin());
            relax(pos);
            relax((pos + n - 1) % n);
        }
        swap(st, nst);
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}
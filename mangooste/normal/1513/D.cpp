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

void solve() {
    int n, p;
    cin >> n >> p;
    vec<int> a(n);
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.emplace(a[i], i);
    }
    vec<char> used(n);
    int comps = n;
    ll ans = 0;
    while (len(st)) {
        auto [v, i] = *st.begin();
        st.erase(st.begin());
        if (used[i] || v >= p) {
            continue;
        }
        for (int j = i; j > 0 && !used[j - 1] && a[j - 1] % a[i] == 0; j--) {
            used[j - 1] = 1;
            comps--;
            ans += a[i];
        }
        for (int j = i; j < n - 1 && !used[j] && a[j + 1] % a[i] == 0; j++) {
            used[j] = 1;
            comps--;
            ans += a[i];
        }
    }
    cout << ans + 1ll * (comps - 1) * p << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
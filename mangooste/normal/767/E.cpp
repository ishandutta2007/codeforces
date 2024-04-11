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

    int n, m;
    cin >> n >> m;
    vec<int> c(n);
    for (auto &x : c) {
        cin >> x;
    }
    vec<int> w(n);
    for (auto &x : w) {
        cin >> x;
    }
    set<pair<int, int>> st;
    vec<char> take(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] % 100 == 0) {
            continue;
        }
        int need = c[i] % 100;
        st.emplace((100 - need) * w[i], i);
        while (m < need) {
            auto [val, j] = *st.begin();
            st.erase(st.begin());
            ans += val;
            m += 100;
            take[j] = 1;
        }
        if (need <= m) {
            m -= need;
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
        if (take[i]) {
            cout << c[i] / 100 + 1 << " 0\n";
        } else {
            cout << c[i] / 100 << ' ' << c[i] % 100 << '\n';
        }
    }
}
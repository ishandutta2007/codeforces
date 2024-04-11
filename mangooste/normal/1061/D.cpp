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

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, x, y;
    cin >> n >> x >> y;
    vec<pair<int, int>> evs;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        evs.emplace_back(l, 0);
        evs.emplace_back(r, 1);
        ans += 1ll * (r - l) * y % mod;
        if (ans >= mod)
            ans -= mod;
    }
    sort(all(evs));
    vec<int> st;
    st.reserve(n);
    for (auto [e, type] : evs) {
        if (!type) {
            if (len(st) && 1ll * (e - st.back()) * y < x) {
                ans += 1ll * (e - st.back()) * y % mod;
                st.pop_back();
            } else
                ans += x;
        } else
            st.push_back(e);
        if (ans >= mod)
            ans -= mod;
    }
    cout << ans << '\n';
}
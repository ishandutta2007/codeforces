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
    int n, q;
    string s;
    cin >> n >> q >> s;

    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + (((s[i] == '+') ^ (i & 1)) ? 1 : -1);

    vector<int> suf(n + 1);
    for (int i = n - 1; i >= 0; i--)
        suf[i] = suf[i + 1] + (((s[i] == '+') ^ (i & 1)) ? -1 : 1);

    map<int, vector<int>> freq;
    for (int i = 0; i < n; i++)
        freq[pref[i] + suf[i + 1]].push_back(i);

    auto get_id = [&](int l, int r) {
        return *lower_bound(all(freq[pref[l] + suf[r]]), l);
    };

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;

        int sum = pref[r] - pref[l];
        if (sum == 0)
            cout << "0\n";
        else if (sum & 1)
            cout << "1\n" << get_id(l, r) + 1 << '\n';
        else
            cout << "2\n" << get_id(l, r - 1) + 1 << ' ' << r << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}
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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = s[i] - 'a';

    const array<int, 4> p3{1, 3, 9, 27};
    const int MASK = p3[3];

    auto get_bit = [&](int mask, int pos) {
        return (mask / p3[pos]) % 3;
    };

    array<vector<int>, MASK> pref;
    pref.fill(vector<int>(n + 1));

    vector<char> valid(MASK, 1);
    for (int mask = 0; mask < MASK; mask++) {
        set<int> st;
        for (int i = 0; i < 3; i++)
            st.insert(get_bit(mask, i));

        if (len(st) != 3) {
            valid[mask] = 0;
            continue;
        }

        for (int i = 0; i < n; i++)
            pref[mask][i + 1] = pref[mask][i] + (a[i] == get_bit(mask, i % 3));
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        l--;

        int answer = n;
        for (int mask = 0; mask < MASK; mask++)
            if (valid[mask])
                answer = min(answer, r - l - (pref[mask][r] - pref[mask][l]));

        cout << answer << '\n';
    }
}
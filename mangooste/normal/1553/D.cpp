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
    string s, t;
    cin >> s >> t;
    int n = len(s), m = len(t);
    vector<vector<array<int, 2>>> nxt(n, vector<array<int, 2>>(26, {-1, -1}));
    for (int i = 0; i < n; i++) {
        if (i)
            for (int j = 0; j < 26; j++) {
                nxt[i][j][0] = nxt[i - 1][j][0];
                nxt[i][j][1] = nxt[i - 1][j][1];
            }

        nxt[i][s[i] - 'a'][i & 1] = i;
    }

    cout << ([&]() -> bool {
        int who = (n & 1);
        int pos = n - 1;
        for (int i = m - 1; i >= 0; i--) {
            if (nxt[pos][t[i] - 'a'][who ^ 1] == -1)
                return false;

            pos = nxt[pos][t[i] - 'a'][who ^ 1];
            who ^= 1;
        }
        return true;
    }() ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests = 1;
    cin >> tests;
    while (tests--)
        solve();
}
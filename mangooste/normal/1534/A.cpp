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

void solve() {
    int n, m;
    cin >> n >> m;
    vec<string> a(n);
    for (auto &x : a)
        cin >> x;

    int k1 = -1, k2 = -1;
    bool ok = true;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == 'W') {
                if (k1 == -1)
                    k1 = (i + j) % 2;
                else
                    ok &= k1 == (i + j) % 2;
            } else if (a[i][j] == 'R') {
                if (k2 == -1)
                    k2 = (i + j) % 2;
                else
                    ok &= k2 == (i + j) % 2;
            }

    if (!ok || (k1 != -1 && k2 != -2 && k1 == k2)) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    if (k1 == -1) {
        if (k2 == -1)
            k1 = 0, k2 = 1;
        else
            k1 = k2 ^ 1;
    } else if (k2 == -1)
        k2 = k1 ^ 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << ((i + j) % 2 == k1 ? 'W' : 'R');

        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
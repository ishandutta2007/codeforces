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
    int n;
    string s;
    cin >> n >> s;

    int diff = 0;
    for (int i = 0; i < n / 2; i++)
        diff += s[i] != s[n - 1 - i];

    int zeroes = count(all(s), '0');

    bool palindrom = true;
    for (int i = 0; i < n / 2; i++)
        palindrom &= s[i] == s[n - 1 - i];

    if (palindrom) {
        if (zeroes % 2 == 0 || zeroes == 1)
            cout << "BOB\n";
        else
            cout << "ALICE\n";

        return;
    }

    if (diff == 1 && zeroes == 2)
        cout << "DRAW\n";
    else
        cout << "ALICE\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
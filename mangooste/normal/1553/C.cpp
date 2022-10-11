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

int get(int r, int c) {
    int answer = 0;
    for (int i = 0; i <= r; i++)
        answer += (i & 1) == c;

    return answer;
}

void solve() {
    string s;
    cin >> s;
    const int n = 10;
    array<array<int, 2>, 2> pref;
    pref.fill(array<int, 2>{0, 0});
    for (int i = 0; i < n; i++) {
        for (int j : {0, 1})
            if (pref[j][1] > pref[j ^ 1][0] + get(9, j ^ 1) - get(i - 1, j ^ 1)) {
                cout << i << '\n';
                return;
            }

        pref[i & 1][1] += (s[i] == '1' || s[i] == '?');
        pref[i & 1][0] += (s[i] == '1');
    }
    cout << "10\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests = 1;
    cin >> tests;
    while (tests--)
        solve();
}
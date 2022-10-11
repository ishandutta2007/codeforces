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
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (auto &x : a)
        cin >> x, x--;

    vector<int> t(k);
    for (auto &x : t)
        cin >> x;

    vector<int> what(n);
    for (int i = 0; i < k; i++)
        what[a[i]] = t[i];

    const int INF = 1e9 + n + 1;
    vector<int> answer(n, INF);
    for (int rot = 0; rot < 2; rot++) {
        int mn = INF;
        for (int i = 0; i < n; i++) {
            if (what[i])
                mn = min(mn, what[i] - i);

            if (mn != INF)
                answer[i] = min(answer[i], mn + i);
        }

        reverse(all(what));
        reverse(all(answer));
    }

    for (auto x : answer)
        cout << x << ' ';

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}
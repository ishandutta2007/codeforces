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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    sort(all(a));
    int mn = a[1] - a[0];
    for (int i = 1; i < n - 1; i++)
        mn = min(mn, a[i + 1] - a[i]);

    int best = -1;
    int best_result = -1;

    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] - a[i] != mn)
            continue;

        int answer = n - 1;

        if (answer > best_result) {
            best_result = answer;
            best = i;
        }
    }

    cout << a[best];
    for (int i = best + 2; i < n; i++)
        cout << ' ' << a[i];

    for (int i = 0; i < best; i++)
        cout << ' ' << a[i];

    cout << ' ' << a[best + 1] << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}
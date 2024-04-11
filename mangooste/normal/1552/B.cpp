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
    vector<array<int, 5>> a(n);
    for (auto &element : a)
        for (auto &x : element)
            cin >> x;

    auto better = [&](int i, int j) {
        int cnt = 0;
        for (int k = 0; k < 5; k++)
            cnt += a[i][k] < a[j][k];

        return cnt >= 3;
    };

    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), better);

    for (int i = 1; i < n; i++)
        if (!better(ord[0], ord[i])) {
            cout << "-1\n";
            return;
        }

    cout << ord[0] + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}
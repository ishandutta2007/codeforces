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
    pair<int, int> a;
    cin >> a.first >> a.second;
    pair<int, int> b;
    cin >> b.first >> b.second;
    pair<int, int> f;
    cin >> f.first >> f.second;

    int answer = abs(a.first - b.first) + abs(a.second - b.second);
    if (a.first == b.first && a.first == f.first && min(a.second, b.second) <= f.second && f.second <= max(a.second, b.second))
        answer += 2;
    else if (a.second == b.second && a.second == f.second && min(a.first, b.first) <= f.first && f.first <= max(a.first, b.first))
        answer += 2;

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}
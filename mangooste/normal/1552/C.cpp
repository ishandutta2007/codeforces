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
    set<int> free;
    for (int i = 1; i <= 2 * n; i++)
        free.insert(i);

    vector<pair<int, int>> segs;
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        free.erase(l);
        free.erase(r);
        segs.push_back(minmax(l, r));
    }

    vector<int> positions(all(free));
    for (int i = 0; i < n - k; i++)
        segs.emplace_back(positions[i], positions[i + n - k]);

    int answer = 0;
    for (int i = 0; i < len(segs); i++)
        for (int j = i + 1; j < len(segs); j++) {
            auto [l1, r1] = segs[i];
            auto [l2, r2] = segs[j];

            bool any = false;
            for (int rot = 0; rot < 2; rot++, swap(l1, l2), swap(r1, r2))
                any |= l1 < l2 && l2 < r1 && r1 < r2;

            answer += any;
        }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}
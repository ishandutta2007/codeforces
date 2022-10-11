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
    ll n, m, si, sj;
    cin >> n >> m >> si >> sj;

    vector<pair<ll, ll>> where;
    where.reserve(4);
    where.emplace_back(n, m);
    where.emplace_back(1, m);
    where.emplace_back(1, 1);
    where.emplace_back(n, 1);

    auto dist = [&](pair<ll, ll> start, pair<ll, ll> finish) {
        return abs(start.first - finish.first) + abs(start.second - finish.second);
    };

    ll answer = 0;
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            answer = max(answer, min(dist({si, sj}, where[i]) + dist(where[i], where[j]) + dist(where[j], {si, sj}), dist({si, sj}, where[j]) + dist(where[i], where[j]) + dist(where[i], {si, sj})));

    [&]() {
        for (int i = 0; i < 4; i++)
            for (int j = i + 1; j < 4; j++)
                if (answer == min(dist({si, sj}, where[i]) + dist(where[i], where[j]) + dist(where[j], {si, sj}), dist({si, sj}, where[j]) + dist(where[i], where[j]) + dist(where[i], {si, sj}))) {
                    cout << where[i].first << ' ' << where[i].second << ' ' << where[j].first << ' ' << where[j].second << '\n';
                    return;
                }
    }();
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}
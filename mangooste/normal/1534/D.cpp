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



int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    cout << "? 1" << endl;
    vec<int> d(n);
    for (auto &x : d)
        cin >> x;

    vec<pair<int, int>> edges;
    ar<vec<int>, 2> who;
    for (int i = 1; i < n; i++) {
        if (d[i] == 1)
            edges.emplace_back(0, i);

        who[d[i] % 2].push_back(i);
    }

    if (len(who[0]) > len(who[1]))
        swap(who[0], who[1]);

    for (auto i : who[0]) {
        cout << "? " << i + 1 << endl;
        for (auto &x : d)
            cin >> x;

        for (int j = 0; j < n; j++)
            if (d[j] == 1)
                edges.emplace_back(i, j);
    }

    for (int i = 0; i < n - 1; i++)
        if (edges[i].first > edges[i].second)
            swap(edges[i].first, edges[i].second);

    sort(all(edges));
    edges.resize(unique(all(edges)) - edges.begin());

    cout << "!" << '\n';
    for (auto [v, u] : edges)
        cout << v + 1 << ' ' << u + 1 << '\n';
}
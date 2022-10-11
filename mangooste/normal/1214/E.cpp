#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

template<typename A, typename B> ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }
template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type> ostream& operator<<(ostream &out, A v) { out << '{'; string sep; for (const B &x : v) out << sep << x, sep = ", "; return out << '}'; }

void dbgPrint() { cerr << endl; }
template<typename A, typename... B> void dbgPrint(A a, B... b) { cerr << ' ' << a; dbgPrint(b...); }

#ifdef LOCAL
#define dbg(...) cerr << "line #" << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbgPrint(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define sz(a) int(a.size())
#define all(a) (a).begin(), (a).end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x, x--;

    vector<int> inds(n);
    iota(all(inds), 0);
    sort(all(inds), [&](int i, int j) {
        return a[i] > a[j];
    });

    auto printEdge = [](int v, int u) {
        cout << v + 1 << ' ' << u + 1 << '\n';
    };
    for (int i = 0; i < n - 1; i++) {
        printEdge(2 * inds[i], 2 * inds[i + 1]);
    }

    int from = a[inds[0]];
    vector<int> outPath;
    outPath.push_back(2 * inds[0] + 1);
    printEdge(inds[from] * 2, 2 * inds[0] + 1);

    for (int i = 1; i < sz(inds); i++) {
        int id = inds[i];
        int dist = abs(from - i);
        while (sz(outPath) && dist + sz(outPath) > a[id]) outPath.pop_back();

        if (sz(outPath)) {
            printEdge(outPath.back(), 2 * id + 1);
            outPath.push_back(2 * id + 1);
        } else {
            if (i <= from) {
                from = i + a[id];
            } else {
                from = i - a[id];
            }
            outPath = {2 * id + 1};
            printEdge(inds[from] * 2, 2 * id + 1);
        }
    }
}
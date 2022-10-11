#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
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
    vector<int> p(n);
    for (auto &x : p) cin >> x, x--;

    vector<vector<int>> ops;
    while (!is_sorted(all(p))) {
        vector<int> where(n);
        for (int i = 0; i < n; i++) {
            where[p[i]] = i;
        }

        int j = 0;
        while (j < n - 1 && where[j + 1] > where[j]) j++;
        assert(j != n - 1);

        int a = where[j + 1];
        int b = where[j];
        assert(a < b);
        j = a;
        while (p[j] < p[j + 1]) j++;
        vector<int> curOps{ 0, a, j + 1, b + 1 };
        if (b + 1 == n) curOps.pop_back();
        sort(all(curOps));
        curOps.resize(unique(all(curOps)) - curOps.begin());
        ops.push_back(curOps);

        curOps.push_back(n);
        vector<int> newP;
        for (int i = sz(curOps) - 2; i >= 0; i--) {
            for (int j = curOps[i]; j < curOps[i + 1]; j++) {
                newP.push_back(p[j]);
            }
        }
        p = newP;
    }

    assert(sz(ops) <= n);
    cout << sz(ops) << '\n';
    for (auto &xs : ops) {
        cout << sz(xs);
        xs.push_back(n);
        for (int i = 1; i < sz(xs); i++) {
            cout << ' ' << xs[i] - xs[i - 1];
        }
        cout << '\n';
    }
}
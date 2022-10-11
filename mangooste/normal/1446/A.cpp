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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        ll w; cin >> w;
        vector<pair<ll, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(all(a));

        while (sz(a) && a.back().first > w) a.pop_back();
        if (!sz(a)) {
            cout << "-1\n";
            continue;
        }
        ll half = (w + 1) / 2;
        if (a.back().first >= half) {
            cout << "1\n";
            cout << a.back().second + 1 << '\n';
            continue;
        }

        vector<int> inds;
        ll sum = 0;
        for (auto [x, ind] : a) {
            sum += x;
            inds.push_back(ind);
            if (sum >= half) break;
        }
        if (sum < half) {
            cout << "-1\n";
        } else {
            cout << sz(inds) << '\n';
            for (auto x : inds) cout << x + 1 << ' ';
            cout << '\n';
        }
    }
}
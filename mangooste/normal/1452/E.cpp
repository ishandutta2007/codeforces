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

inline int intersection(int l1, int r1, int l2, int r2) {
    return max(0, min(r1, r2) - max(l1, l2) + 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k; cin >> n >> m >> k;
    vector<int> l(m);
    vector<int> r(m);
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i];
        l[i]--, r[i]--;
    }

    ll ans = 0;
    for (int leftL = 0; leftL + k <= n; leftL++) {
        vector<ll> sums(n + 1, 0);
        auto add = [&](int l, int r, int delta) {
            if (r <= l) return;
            sums[l] += delta;
            sums[r] -= delta;
        };

        vector<vector<array<int, 3>>> events(n);
        auto addProg = [&](int l, int r, int start, int delta) {
            if (l < 0) {
                start += abs(l) * delta;
                l = 0;
            }
            if (r <= l) return;
            events[l].push_back({ start, delta, 0 });
            r--;
            events[r].push_back({ start + delta * (r - l), delta, 1 });
        };

        int leftR = leftL + k - 1;
        for (int j = 0; j < m; j++) {
            if (r[j] <= leftR || l[j] <= leftL) {
                add(leftL, n, intersection(leftL, leftR, l[j], r[j]));
            } else if (l[j] > leftR) {
                if (r[j] - l[j] + 1 >= k) {
                    addProg(l[j] - k + 1, l[j], 1, 1);
                    add(l[j], r[j] - k + 1, k);
                    addProg(r[j] - k + 1, r[j] + 1, k, -1);
                } else {
                    addProg(l[j] - k + 1, r[j] - k + 1, 1, 1);
                    add(r[j] - k + 1, l[j], r[j] - l[j] + 1);
                    addProg(l[j], r[j] + 1, r[j] - l[j] + 1, -1);
                }
            } else {
                int inter = intersection(leftL, leftR, l[j], r[j]);
                if (r[j] - l[j] + 1 >= k) {
                    addProg(l[j] - k + 1, l[j], 1, 1);
                    add(l[j], r[j] - k + 1, k);
                    addProg(r[j] - k + 1, r[j] - inter + 2, k, -1);
                } else {
                    addProg(l[j] - k + 1, r[j] - k + 1, 1, 1);
                    add(r[j] - k + 1, l[j], r[j] - l[j] + 1);
                    addProg(l[j], r[j] - inter + 2, r[j] - l[j] + 1, -1);
                }
                add(r[j] - inter + 2, n, inter);
            }
        }

        for (int i = 1; i <= n; i++) {
            sums[i] += sums[i - 1];
        }
        ll needToAdd = 0;
        ll step = 0;
        for (int i = 0; i < n; i++) {
            needToAdd += step;
            for (auto [start, delta, type] : events[i]) {
                if (type) continue;
                needToAdd += start;
                step += delta;
            }
            sums[i] += needToAdd;
            for (auto [endValue, delta, type] : events[i]) {
                if (!type) continue;
                needToAdd -= endValue;
                step -= delta;
            }
        }
        ans = max(ans, *max_element(all(sums)));
    }
    assert(ans);
    cout << ans << '\n';
}
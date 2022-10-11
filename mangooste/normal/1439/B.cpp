#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <set>
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
        int n, m, k; cin >> n >> m >> k;
        vector<vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            int v, u; cin >> v >> u;
            v--, u--;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        for (int i = 0; i < n; i++) {
            sort(all(g[i]));
        }

        set<pair<int, int>> st;
        vector<int> deg(n);
        for (int i = 0; i < n; i++) {
            deg[i] = sz(g[i]);
            st.emplace(deg[i], i);
        }

        vector<char> alreadyDeleted(n, false);
        auto deleteOne = [&](int v) {
            assert(!alreadyDeleted[v]);
            alreadyDeleted[v] = true;
            for (auto u : g[v]) {
                if (alreadyDeleted[u]) continue;
                st.erase({ deg[u], u });
                deg[u]--;
                st.emplace(deg[u], u);
            }
        };

        vector<int> ans;
        while (sz(st)) {
            auto [dg, v] = *st.begin();
            st.erase(st.begin());
            if (dg < k - 1) {
                deleteOne(v);
                continue;
            }

            if (dg == k - 1) {
                if ((ll)k * (k - 1) / 2 <= m) {
                    bool isCleque = true;
                    vector<int> cur{ v };
                    for (auto u : g[v]) {
                        if (alreadyDeleted[u]) continue;
                        cur.push_back(u);
                    }
                    assert(sz(cur) == k);
                    for (int i = 0; i < k; i++) {
                        for (int j = i + 1; j < k; j++) {
                            isCleque &= binary_search(all(g[cur[i]]), cur[j]);
                        }
                    }

                    if (isCleque) {
                        ans = { 2, v + 1 };
                        for (auto u : g[v]) {
                            if (alreadyDeleted[u]) continue;
                            ans.push_back(u + 1);
                        }
                        break;
                    }
                }
                deleteOne(v);
                continue;
            }

            assert(dg >= k);
            ans = { 1, v + 1 };
            for (auto [dg, v] : st) ans.push_back(v + 1);
            break;
        }

        if (ans.empty()) {
            cout << "-1\n";
        }
        else {
            cout << ans[0];
            if (ans[0] == 1) cout << ' ' << sz(ans) - 1;
            cout << '\n';
            for (int i = 1; i < sz(ans); i++) {
                cout << ans[i] << ' ';
            }
            cout << '\n';
        }
    }
}
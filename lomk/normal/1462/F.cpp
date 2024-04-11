/*input
4
3
1 4
2 3
3 6
4
1 2
2 3
3 5
4 5
5
1 2
3 8
4 5
6 7
9 10
5
1 5
2 4
3 5
3 8
4 8

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x, y) ((x >> y) & 1)
#define loop(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rloop(i, l, r) for (int i = (int)l; i >= (int)r; --i)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
void debug() {cerr << endl;} template<typename T, typename... Ts> void debug(const T& value, const Ts&... values) {cerr << value << ' ', debug(values...);}
#endif
class Solver {
public:
    vector<pair<int, int> > seg;
    vector<int> al, ar;
    Solver() {
    }
    int calSmall(int lim) {
        // r<=lim
        auto iter = upper_bound(ar.begin(), ar.end(), lim) - ar.begin();
        return iter;
    }
    int calLarge(int lim) {
        // r<=lim
        auto iter = al.end() - lower_bound(al.begin(), al.end(), lim);
        return iter;
    }
    void operator()() {
        int n; cin >> n;
        loop(i, 1, n) {
            int l, r; cin >> l >> r;
            seg.push_back({l, r});
            al.push_back(l); ar.push_back(r);
        }
        sort(al.begin(), al.end()); sort(ar.begin(), ar.end());
        int ans = n;
        for (auto [l, r] : seg) {
            ans = min(ans, calSmall(l - 1) + calLarge(r + 1));
        }
        cout << ans << endl;
    }
};

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        Solver solve;
        solve();
    }
}
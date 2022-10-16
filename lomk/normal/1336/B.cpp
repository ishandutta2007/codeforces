/*input
1
7 3 8
10 9 10 7 10 1 8
8 3 7
10 1 5 9 5 8 6 1
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#define sq(x) ((x)*(x))
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
void debug() {cerr << endl;} template<typename T, typename... Ts> void debug(const T& value, const Ts&... values) {cerr << value << ' ', debug(values...);}
#endif
// const int N =;

int n[3];
vector<vector<int> > a(3);
int INF = numeric_limits<int>::max();

int solve() {
    int ans = INF;
    auto findRem = [&](int x, int y) -> pair<int, int> {
        auto it = upper_bound(a[2].begin(), a[2].end(), (x + y) / 2);
        if (it == a[2].begin()) return {*it, *it};
        if (it == a[2].end()) return {*prev(it), *prev(it)};
        return {*prev(it), *it};
    };
    auto opt = [&](int x, int y) {
        auto [z1, z2] = findRem(x, y);
        ans = min(ans, sq(x - y) + sq(y - z1) + sq(x - z1));
        ans = min(ans, sq(x - y) + sq(y - z2) + sq(x - z2));
    };
    for (auto x : a[0]) {
        auto it = lower_bound(a[1].begin(), a[1].end(), x);
        if (it != a[1].end()) opt(x, *it);
        if (it != a[1].begin()) opt(x, *(--it));
        it = upper_bound(a[1].begin(), a[1].end(), x);
        if (it != a[1].end()) opt(x, *it);
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        loop(i, 0, 2) a[i].clear();
        loop(i, 0, 2) cin >> n[i];
        loop(i, 0, 2) {
            loop(j, 1, n[i]) {
                int t; cin >> t;
                a[i].push_back(t);
            }
            sort(a[i].begin(), a[i].end());
            a[i].resize(distance(a[i].begin(), unique(a[i].begin(), a[i].end())));
        }
        // print(a);
        int ans = solve();
        swap(a[1], a[2]);
        ans = min(ans, solve());
        cout << ans << endl;
    }
}
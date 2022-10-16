/*input
4
1
5
15
50
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
// const int N =;

const int INF = numeric_limits<int>::max() / 2;
class Solver {
public:
    int ans = INF;
    bool mark[10];
    void back(int rem, int val) {
        if (val > ans) return;
        if (rem == 0) {
            ans = min(ans, val);
            return;
        }
        rloop(i, 9, 1) {
            if (i > rem || mark[i]) continue;
            mark[i] = true;
            back(rem - i, val * 10 + i);
            mark[i] = false;
        }
    }
    Solver() {
        memset(mark, 0, sizeof(mark));
    }
    void operator()() {
        int n;
        cin >> n;
        back(n, 0);
        if (ans == INF) cout << -1 << endl;
        else cout << ans << endl;
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
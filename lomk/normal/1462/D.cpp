/*input
4
5
3 1 6 6 2
4
1 2 2 1
3
2 2 2
4
6 3 2 1
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
    int n;
    vector<int> a;
    Solver() {
    }

    int cal(int need) {
        int cur = 0; int ret = 0;
        for (auto it : a) {
            if (cur != 0) ret++;
            cur += it;
            if (cur == need) {
                cur -= need;
            }
            else if (cur > need) {
                return INF;
            }
        }
        if (cur != 0) return INF;
        return ret;
    }
    void operator()() {
        cin >> n;
        int sum = 0;
        loop(i, 1, n) {
            int t; cin >> t; a.push_back(t);
            sum += t;
        }
        int ans = n - 1;
        loop(i, 1, n) {
            if (sum % i != 0) continue;
            ans = min(ans, cal(sum / i));
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
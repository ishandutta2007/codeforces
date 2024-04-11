/*input

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

class Solver {
public:
    void operator()() {
        int n;
        cin >> n;
        deque<int> dq; loop(i, 1, n) {
            int t; cin >> t; dq.push_back(t);
        }
        vector<int> ans;
        loop(i, 1, n) {
            if (i % 2) {
                ans.push_back(dq.front());
                dq.pop_front();
            }
            else {
                ans.push_back(dq.back());
                dq.pop_back();
            }
        }
        for (auto it : ans) cout << it << sp;
        cout << endl;
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
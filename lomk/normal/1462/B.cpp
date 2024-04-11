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
        int n; cin >> n;
        string s; cin >> s;
        if (s == "2020") {
            cout << "YES" << endl;
            return;
        }
        int diff = s.size() - 4;
        loop(i, 0, n - 1) {
            if (i + diff - 1 >= n) break;
            string t = s;
            t.erase(t.begin() + i, t.begin() + i + diff);
            if (t == "2020") {
                cout << "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
        return;
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
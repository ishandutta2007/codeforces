/*input
8
1 4
487 1
487 2
487 3
487 4
487 5
487 6
487 7
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
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
void debug() {cerr << endl;} template<typename T, typename... Ts> void debug(const T& value, const Ts&... values) {cerr << value << ' ', debug(values...);}
#endif
// const int N =;

pair<int, int> fn(int x) {
    pair<int, int> ret = {x % 10, x % 10};
    while (x) {
        int t = x % 10;
        x /= 10;
        ret.fi = min(ret.fi, t); ret.se = max(ret.se, t);
    }
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        k--;
        loop(i, 1, k) {
            auto rec = fn(n);
            if (rec.fi * rec.se == 0) break;
            n += rec.fi * rec.se;
        }
        cout << n << endl;
    }
}
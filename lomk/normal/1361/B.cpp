/*input
1
7 2
4 3 2 1 1 0 0
3 1
2 10 1000
4 5
0 1 1 100
1 8
89
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

const int mod = 1e9 + 7;
#define pow binPow
int binPow(int a, long long q) {
    int ret = 1;
    while (q) {
        if (q & 1LL) ret = 1LL * ret * a % mod;
        a = 1LL * a * a % mod;
        q >>= 1LL;
    }
    return ret;
}

struct Solver {
    int n, p;
    vector<int> a;
    map<int, int> mark;
    Solver() {};
    int operator()() {
        cin >> n >> p;
        loop(i, 1, n) {
            int t; cin >> t; a.push_back(t);
        }
        if (p == 1) return (n % 2);
        sort(a.begin(), a.end());
        int other = -1;
        while (true) {
            if (a.empty()) break;
            other = a.back(); a.pop_back();
            mark.clear();
            while (!a.empty()) {
                int u = a.back(); a.pop_back();
                mark[u]++;
                while (mark[u] == p) {
                    mark[u] = 0; u++;
                    mark[u]++;
                }
                if (mark[other] == 1) {
                    other = -1;
                    break;
                }
            }
        }
        if (other == -1) return 0;
        else {
            int ret = binPow(p, other);
            for (auto it : mark) {
                ret = (ret - it.se * binPow(p, it.fi) % mod) % mod;
                ret = (ret + mod) % mod;
            }
            return ret;
        }
    }
};

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        Solver solve;
        cout << solve() << endl;
    }
}
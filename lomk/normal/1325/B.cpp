/*input
2
3
3 2 1
6
3 1 4 1 5 9
*/
#ifdef UncleGrandpa
#include <prettyprint.hpp>
#define LOCAL 1
#else
#define LOCAL 0
#endif
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define all(x) (x).begin(), (x).end()
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#define debug(x...) {if (!LOCAL) return; cout << "[" << #x << "] ="; print(x);}
void print() {cout << endl;}
template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {if (!LOCAL) return; cout << value << ' '; print(values...);}
// const int N =;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a;
        loop(i, 1, n) {
            int t; cin >> t; a.push_back(t);
        }
        sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())));
        cout << a.size() << endl;
    }
}
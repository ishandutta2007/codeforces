/*input
3 8

3 4
1 4
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

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, S;
    cin >> n >> S;
    if (S - n < n) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    loop(i, 1, n - 1) cout << 1 << sp;
    cout << S - n + 1 << endl;
    cout << S - n << endl;
}
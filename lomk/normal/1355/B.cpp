/*input
2
3
1 1 1
5
2 3 1 2 2
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

const int INF = 1e9;
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a;
        loop(i, 1, n) {
            int t; cin >> t;
            a.push_back(t);
        }
        sort(a.begin(), a.end());
        vector<int> dp(n + 5, -INF);
        dp[0] = 0;
        loop(i, 1, n) {
            int cur = a[i - 1];
            if (i - cur >= 0) {
                dp[i] = max(dp[i], dp[i - cur] + 1);
            }
            dp[i] = max(dp[i], dp[i - 1]);
        }
        cout << dp[n] << endl;
    }
}
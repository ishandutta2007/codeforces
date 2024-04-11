/*input
5
1 1 4 2 2
*/
#include <bits/stdc++.h>
using namespace std;
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
const int N = 100010;
int n;
int a[N];
bool dp[N][10];
int tr[N][10];
vector<int> ans;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    loop(i, 1, n) cin >> a[i];
    loop(i, 1, 5) dp[1][i] = true;
    loop(i, 2, n) {
        loop(cur, 1, 5) {
            loop(pre, 1, 5) {
                if (!dp[i - 1][pre]) continue;
                bool ok = false;
                if (a[i - 1] == a[i] && cur != pre) ok = true;
                if (a[i - 1] < a[i] && pre < cur) ok = true;
                if (a[i - 1] > a[i] && pre > cur) ok = true;
                if (ok) {
                    dp[i][cur] = true;
                    tr[i][cur] = pre;
                }
            }
        }
    }
    int cur = -1;
    loop(i, 1, 5) {
        if (dp[n][i]) {
            cur = i;
            break;
        }
    }
    if (cur == -1) {
        cout << -1 << endl;
        return 0;
    }
    rloop(i, n, 1) {
        ans.push_back(cur);
        cur = tr[i][cur];
    }
    rloop(i, ans.size() - 1, 0) cout << ans[i] << sp;
    cout << endl;
}
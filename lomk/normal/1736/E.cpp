/*input
5
7 3 9 6 12

2
3 1
*/
#include <bits/stdc++.h>
using namespace std;
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
#endif
const int N = 505;
const int INF = numeric_limits<int>::max()/3;
 
// position I, position to plus, num swaps used
int dp[N][N][N];
int mx[N][N][N];
int n;
array<int,N> a;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    #ifdef in1code
    freopen("1test.inp","r",stdin);
    #endif
    cin >> n;
    loop(i,1,n) cin >> a[i];
    
    auto maximize = [&](int &x, int y){
      x = max(x,y);  
    };
    
    // auto mx2 = [&](int _i, int _j, int _k){
    //   int ret = -INF;
    //   loop(j,0,_j) loop(k,0,_k) ret = max(ret,dp[_i][j][k]);
    //   return ret;
    // };
    
    loop(i,0,N-1) loop(j,0,N-1) loop(k,0,N-1) dp[i][j][k] = mx[i][j][k] = -INF;
    loop(k,0,N-1) dp[0][0][k] = 0;
    loop(j,0,N-1) loop(k,0,N-1) mx[0][j][k] = 0;
    
    loop(pos,1,n) loop(i,1,n) loop(s,0,n){
      if (s>pos) continue;
      if (i>=pos&&s>=(i-pos)){
        maximize(dp[pos][i][s],mx[pos-1][i-1][s-(i-pos)]+a[i]);
      }
      if (s>=1){
          maximize(dp[pos][i][s],dp[pos-1][i][s-1]+a[i]);
          maximize(dp[pos][i][s],dp[pos][i][s-1]);
      }
      mx[pos][i][s] = max(dp[pos][i][s],mx[pos][i-1][s]);
      if (s>=1) maximize(mx[pos][i][s],mx[pos][i][s-1]);
      // print(pos,i,s,mx[pos][i][s],mx2(pos,i,s));
      // assert(mx[pos][i][s]==mx2(pos,i,s));
    }
    
    int ans = -INF;
    loop(pos,1,n) loop(i,1,n) loop(s,0,n) ans = max(ans,dp[pos][i][s]);
    cout << ans << endl;
}
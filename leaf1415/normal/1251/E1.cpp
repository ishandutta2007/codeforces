#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n;
P p[200005];
vector<P> vec;
priority_queue<llint> Q;
multiset<llint> S;
llint dp[2][5005];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for(int z = 0; z < T; z++){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> p[i].first >> p[i].second;
    sort(p+1, p+n+1);

    vec.clear();
    for(int i = 1; i <= n; i++) vec.push_back(make_pair(max(0LL, p[i].first-i+1), p[i].second));
    //for(int i = 1; i <= n; i++) vec.push_back(make_pair(p[i].first, p[i].second));
    //sort(vec.begin(), vec.end());

    for(int j = 0; j <= n; j++) dp[n%2][j] = inf;
    dp[n%2][0] = 0;

    for(int i = n; i > 0; i--){
      for(int j = 0; j <= n; j++) dp[(i-1)%2][j] = inf;
      for(int j = 0; j <= n; j++){
        if(vec[i-1].first <= j) dp[(i-1)%2][j] = min(dp[(i-1)%2][j], dp[i%2][j]);
        if(j+1 <= n) dp[(i-1)%2][j+1] = min(dp[(i-1)%2][j+1], dp[i%2][j] + vec[i-1].second);
      }
    }
    llint ans = inf;
    for(int j = 0; j <= n; j++) ans = min(ans, dp[0][j]);
    cout << ans << "\n";

  }
  flush(cout);

  return 0;
}
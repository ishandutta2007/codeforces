#include <iostream>
#include <utility>
#include <algorithm>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n, m;
llint x[300005], y[300005];
llint u[300005], v[300005];
P p[300005];

llint X[300005], Y[300005];
llint sumX[300005], sumY[300005];
llint ans[300005];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> x[i] >> y[i];
  }
  for(int i = 1; i <= m; i++){
    cin >> u[i] >> v[i];
  }

  for(int i = 1; i <= n; i++) p[i] = make_pair(x[i]-y[i],i);
  sort(p+1, p+n+1);

  for(int i = 1; i <= n; i++){
    X[i] = x[p[i].second], Y[i] = y[p[i].second];
  }
  for(int i = 1; i <= n; i++){
    sumX[i] = sumX[i-1] + X[i];
    sumY[i] = sumY[i-1] + Y[i];
  }

  for(int i = 1; i <= n; i++){
    ans[p[i].second] += (n-i)*X[i] + (sumY[n]-sumY[i]);
    ans[p[i].second] += (i-1)*Y[i] + (sumX[i-1]);
  }
  //for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
  for(int i = 1; i <= m; i++){
    llint val = min(x[u[i]]+y[v[i]], x[v[i]]+y[u[i]]);
    ans[u[i]] -= val, ans[v[i]] -= val;
  }

  for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
  return 0;
}
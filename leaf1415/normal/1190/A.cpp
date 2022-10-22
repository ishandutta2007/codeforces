#include <iostream>
#include <algorithm>
#define llint long long

using namespace std;

llint n, m, k;
llint p[100005];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  for(int i = 0; i < m; i++) cin >> p[i];

  llint del = 0, right = k, ans = 0;
  while(1){
    int nx = upper_bound(p, p+m, right) - p;
    if(nx == del){
      if(nx == m) break;
      right = (p[nx]-right%k+(k-1)) / k * k + right%k;
    }
    else{
      ans++;
      right += nx - del;
      del = nx;
    }
    //cout << del << " " << right << endl;
  }
  cout << ans << endl;

  return 0;
}
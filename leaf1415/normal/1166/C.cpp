#include <iostream>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;

llint n;
llint a[200005];
vector<llint> pvec, nvec;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++){
    if(a[i] >= 0) pvec.push_back(a[i]);
    else nvec.push_back(-a[i]);
  }
  sort(pvec.begin(), pvec.end());
  sort(nvec.begin(), nvec.end());

  llint ans = 0;
  for(int i = 0; i < pvec.size(); i++){
    llint x = pvec[i];
    ans += upper_bound(pvec.begin(), pvec.end(), x*2) - upper_bound(pvec.begin(), pvec.end(), x);
  }
  for(int i = 0; i < nvec.size(); i++){
    llint x = nvec[i];
    ans += upper_bound(nvec.begin(), nvec.end(), x*2) - upper_bound(nvec.begin(), nvec.end(), x);
  }
  //cout << ans << endl;
  for(int i = 0; i < pvec.size(); i++){
    llint x = pvec[i];
    ans += upper_bound(nvec.begin(), nvec.end(), 2*x) - lower_bound(nvec.begin(), nvec.end(), x);
  }
  for(int i = 0; i < nvec.size(); i++){
    llint x = nvec[i];
    ans += upper_bound(pvec.begin(), pvec.end(), 2*x) - upper_bound(pvec.begin(), pvec.end(), x);
  }
  cout << ans << endl;
  return 0;
}
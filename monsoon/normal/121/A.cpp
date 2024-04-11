#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

int l,r,n;
vector<ll> nums,pref;

ll count(int r) {
  int i = upper_bound(nums.begin(),nums.end(),r) - nums.begin();
  return pref[i] + ll(r-nums[i]) * nums[i];
}

int main() {
  nums.push_back(0);
  REP(i,9) {
    REP(msk,1<<i+1) {
      int val=0;
      REP(j,i+1) val=val*10 + ((msk&1<<j) ? 4 : 7);
      nums.push_back(val);
    }
  }
  nums.push_back(4444444444LL);
  sort(nums.begin(),nums.end());
  n = nums.size();
  pref.resize(n);
  REP(i,n-1) {
    ll cnt = nums[i+1] - nums[i];
    pref[i+1] = pref[i] + cnt * nums[i+1];
  }

  scanf("%d%d",&l,&r);
  ll ans = count(r) - count(l-1);
  printf("%lld\n",ans);
}
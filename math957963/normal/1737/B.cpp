#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200010
#define MOD 998244353
#define INF (ll)1e+18
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;

ll solve(ll x){
  if(x==0)return 0;
  ll l=0;
  ll r=1000000007;
  ll m;
  while((l+1)<r){
    m=(l+r)/2;
    if((m*m)<=x)l=m;
    else r=m;
  }
  if((l*(l+2))==x)return (3*l);
  else if((l*(l+1))<=x)return (3*l-1);
  else return (3*l-2);
}


int main() {
  int t;
  ll x,y,ans;
  cin >> t;
  rep(tt,t){
    cin>>x>>y;
    ans=solve(y)-solve(x-1);
    cout<<ans<<endl;
  }

    
	return 0;
}
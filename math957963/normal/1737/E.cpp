#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 1000010
#define MOD 1000000007
#define INF (ll)1e+18
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
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


int main() {
	int n;
  ll r2[N];
  ll ans[N];
  ll x;
  r2[0]=1;
  rep(i,N-1)r2[i+1]=(r2[i]*500000004LL)%MOD;
  int t;
  cin>>t;
  rep(tt,t){
    cin>>n;
    if(n==1){
      cout<<1<<"\n";
      continue;
    }
    x=1;
    ans[n]=r2[(n-1)/2];
    rep3(i,n-1,2){
      if((2*i)<=n)x=(x-ans[2*i]+MOD)%MOD;
      if((2*i+1)<=n)x=(x-ans[2*i+1]+MOD)%MOD;
      ans[i]=(x*r2[(i+1)/2])%MOD;
    }
    ans[1]=0;
    rep(i,n)cout<<ans[i+1]<<"\n";
  }
    
	return 0;
}
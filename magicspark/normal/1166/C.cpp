#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
int a[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;a[i]=abs(x);
	}
	ll ans=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ans+=upper_bound(a,a+n+1,a[i]*2)-a-i-1;
	}
	cout<<ans<<endl;
	return 0;
}
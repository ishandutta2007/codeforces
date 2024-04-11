#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,a[511111];
signed main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	int ans=0,pre=inf;
	for(int i=n-1;i>=0;i--){
		int tmp=min(max(pre-1,0ll),a[i]);
		ans+=tmp;
		pre=tmp;
	}
	cout<<ans<<endl;
	return 0;
}
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
int n;
int a[222222],even[222222],odd[222222];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)if(i&1)odd[i]=i==1?a[1]:odd[i-1]+a[i],even[i]=even[i-1];else even[i]=even[i-1]+a[i],odd[i]=odd[i-1];
	int ans=0;
	for(int i=1;i<=n;i++){
		//cerr<<odd[i]<<" "<<even[n]-even[i-1]<<" "<<even[i]<<" "<<odd[n]-odd[i-1]<<endl;
		if(odd[i]+even[n]-even[i-1]==even[i]+odd[n]-odd[i-1])ans++;
	}
	cout<<ans<<endl;
	return 0;
}
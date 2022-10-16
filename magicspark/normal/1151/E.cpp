#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,stdans;
int a[111111];
int cnt[111111],b[111111];
void duipai(){
	for(int l=1;l<=n;l++)
		for(int r=l;r<=n;r++){
			for(int i=1;i<=n;i++)b[i]=(a[i]<=r&&a[i]>=l?1:0);
			for(int i=0;i<n;i++)if(b[i]==0&&b[i+1]==1)cnt[i+1]++,stdans++;
		}
}
int main(){
	cin>>n;a[0]=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	#ifndef ONLINE_JUDGE
	duipai();
	#endif
	ll ans=(ll)(a[1])*(n-a[1]+1);
//	cerr<<"cmp:"<<cnt[1]<<" "<<ans<<endl;
	for(int i=1;i<n;i++){
		int x=a[i],y=a[i+1];
//		cerr<<"cmp:"<<cnt[i+1]<<" ";
		if(x>y){
//			cerr<<(x-y)*y<<endl;
			ans+=(ll)(x-y)*y;
		}else{
//			cerr<<(y-x)*(n-y+1)<<endl;
			ans+=(ll)(y-x)*(n-y+1);
		}
	}
//	cerr<<stdans<<" ";
	cout<<ans<<endl;
	return 0;
}
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
int m,miu[100005];
inline int orzsjc(int x){
	return modpow(x,mod-2,mod);
}
inline int sjctxdy(int x){
	int ret=0;
	while(x){
		ret++;
		x=x&(x-1);
	}
	return ret;
}
inline int sjcakioi(int x){
	return m-m/x;
}
inline void get_miu(){
	miu[1]=1;
	for(int i=1;i<=m;i++)
		for(int j=i+i;j<=m;j+=i)miu[j]-=miu[i];
}
signed main(){
	int ans=1;cin>>m;get_miu();
	for(int i=2;i<=m;i++){
		int res=m*orzsjc(sjcakioi(i))%mod;res--;
		if(miu[i]==1)(ans-=(res-mod))%=mod;
		else if(miu[i]==-1)(ans+=res)%=mod;
	}
	cout<<ans<<endl;
	return 0;
}
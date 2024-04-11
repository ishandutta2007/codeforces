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
int q;
int l[123],r[123],dat[123];
signed main(){
	cin>>q;dat[1]=1;
	for(int i=2;i<=100;i++)dat[i]=1ll<<i-2;
	while(q--){
		int a,b,m;cin>>a>>b>>m;
		if(a==b){
			cout<<1<<" "<<a<<endl;continue;
		}
		l[1]=a;r[1]=a;int suml=a,sumr=a;
		int step,dif;
		for(int i=2;;i++){
			l[i]=suml+1;
			r[i]=sumr+m;
			cerr<<l[i]<<' '<<r[i]<<endl;
			if(l[i]>b){
				step=-1;cout<<-1;
				break;
			}
			if(l[i]<=b&&b<=r[i]){
				step=i;//cerr<<"step:"<<step<<endl;
				cout<<step<<" ";dif=b-l[i];
				break;
			}
			suml+=l[i];sumr+=r[i];
		}
		int cur=a,sum=a;
		vector<int>ans(step+5,0),add(step+5,0);
		ans[1]=a;
		for(int i=2;i<=step;i++){
			ans[i]=l[i];
			int div=dat[step-i+1];
			int mx=dif/div;
			mx=max(mx,0ll);mx=min(mx,m-1);
			dif-=mx*div;//cerr<<i<<" "<<mx<<endl;
			for(int j=i;j<=step;j++)add[j]+=mx*dat[j-i+1];
		}
//		for(int i=1;i<=step;i++)cerr<<i<<" "<<ans[i]<<" "<<add[i]<<endl;
		for(int i=1;i<=step;i++)cout<<ans[i]+add[i]<<" ";
		cout<<endl;
	}
	return 0; 
}
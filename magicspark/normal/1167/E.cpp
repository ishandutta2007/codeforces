#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,x,a[1000005];
int l[1000005],r[1000005];
int main(){
	scanf("%d%d",&n,&x);
	memset(l,inf,sizeof l);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)l[a[i]]=min(l[a[i]],i),r[a[i]]=max(r[a[i]],i);
	ll ans=0;int mx=*max_element(a+1,a+n+1);
	int lpos,L,R=inf,rpos=mx+1;
	while(1){
		if(rpos==0||r[rpos-1]>R)break;
		rpos--;if(l[rpos]!=inf)R=l[rpos];
	}
	for(lpos=0;lpos<=x;lpos++){
		if(l[lpos]<L)break;
		if(r[lpos]>L)L=r[lpos];
		int pre=-1;
		while(R<L){
			if(rpos<mx+1)rpos++;
			if(rpos>=mx+1)R=inf;
			if(l[rpos]!=inf){
				R=l[rpos];
				if(R>=L){
					if(pre+1)rpos=pre+1;
			//		cerr<<rpos<<" "<<pre<<endl;
				}
				pre=rpos;
			}
		}
		//cerr<<lpos<<" "<<rpos<<" "<<L<<" "<<R<<" "<<x-max(lpos+2,rpos)+2<<endl;
		ans+=(x-max(lpos+2,rpos)+2);
	}
	printf("%I64d\n",ans);
	return 0;
}
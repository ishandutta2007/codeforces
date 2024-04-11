#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],k,l[maxn],n,r[maxn];
ll ans,cur,f[maxn];
signed main(){
	scanf("%d%d",&n,&k);
	for(ri i=1;i<=n;++i)scanf("%d%d%d",l+i,r+i,a+i);
	for(ri i=n;i;--i){
		ll req=a[i]+(r[i]==l[i+1]?f[i+1]:0);
		if(1ll*(r[i]-l[i]+1)*k<req)return puts("-1"),0;
		f[i]=max(req-1ll*(r[i]-l[i])*k,0ll);
	}
	for(ri i=1;i<=n;++i){
		if(cur<f[i])ans+=cur,cur=k;
		ans+=a[i],cur-=a[i];
		if(cur<0)cur=cur%k+k;
	}
	printf("%lld",ans);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
int a[maxn],b[maxn],id[maxn],n,t_case;
ll suf[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i),id[i]=i;
		for(ri i=1;i<=n;++i)scanf("%d",b+i);
		sort(id+1,id+n+1,[&](const int &x,const int &y){return a[x]!=a[y]?a[x]<a[y]:b[x]>b[y];});
		suf[n+1]=0;
		for(ri j=n;j;--j)suf[j]=suf[j+1]+b[id[j]];
		ll ans=LLONG_MAX;
		for(ri j=0;j<=n;++j){
			ri i=id[j];
			ckmin(ans,max((ll)a[i],suf[j+1]));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
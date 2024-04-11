#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=1e6+10;
int k,m,n,nxtx[maxn],nxty[maxn],px[maxn],py[maxn],sumx[maxn],sumy[maxn],t_case,x[maxn],y[maxn];
bool vis[maxn],visx[maxn],visy[maxn];
vector<int>c[maxn],r[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d",&n,&m,&k);
		for(ri i=1;i<=n;++i)scanf("%d",x+i),c[x[i]].clear(),visx[x[i]]=true;
		for(ri i=1;i<=m;++i)scanf("%d",y+i),r[y[i]].clear(),visy[y[i]]=true;
		for(ri i=1;i<=k;++i){
			scanf("%d%d",px+i,py+i);
			nxtx[i]=*lower_bound(x+1,x+n+1,px[i]);
			nxty[i]=*lower_bound(y+1,y+m+1,py[i]);
			if(visx[px[i]]&&visy[py[i]])vis[i]=true;
			if(visx[px[i]])c[px[i]].push_back(i);
			if(visy[py[i]])r[py[i]].push_back(i);
		}
		ll ans=0;
		for(ri i=1;i<=m;++i){
			for(auto j:r[y[i]]){
				if(vis[j])continue;
				ans+=sumx[nxtx[j]];
			}
			for(auto j:r[y[i]]){
				if(vis[j])continue;
				++sumx[nxtx[j]];
			}
		}
		for(ri i=1;i<=n;++i){
			for(auto j:c[x[i]]){
				if(vis[j])continue;
				ans+=sumy[nxty[j]];
			}
			for(auto j:c[x[i]]){
				if(vis[j])continue;
				++sumy[nxty[j]];
			}
		}
		printf("%lld\n",ans);
		for(ri i=1;i<=n;++i)visx[x[i]]=false;
		for(ri i=1;i<=m;++i)visy[y[i]]=false;
		for(ri i=1;i<=k;++i){
			vis[i]=false;
			sumx[nxtx[i]]=sumy[nxty[i]]=0;
		}
	}
	return 0;
}
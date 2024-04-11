#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=610;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
struct edge{
	int to,nxt;
}e[maxn*maxn];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int a[maxn],cnt,dis[maxn][maxn],l,m,mch[maxn],n,v,vis[maxn];
bool dfs(int p){
	if(vis[p]==cnt)return false;
	vis[p]=cnt;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(!mch[e[i].to]||dfs(mch[e[i].to])){
			mch[e[i].to]=p;
			return true;
		}
	return false;
}
inline bool check(int k){
	memset(hd,0,sizeof hd);
	len=0;
	for(ri i=1;i<=n;++i)
		for(ri j=1;j<=v;++j)
			if(dis[a[i]][j]<=k)
				addedge(i,j);
	memset(mch,0,sizeof mch);
	ri ret=0;
	for(ri i=1;i<=n;++i)++cnt,ret+=dfs(i);
	return ret>=m;
}
inline int half(){
	ri l=0,r=1731311,ret=-1;
	while(l<=r){
		ri mid=l+r>>1;
		if(check(mid))ret=mid,r=mid-1;
		else l=mid+1;
	}
	return ret;
}
signed main(){
	scanf("%d%d%d%d",&v,&l,&n,&m);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	memset(dis,0x3f,sizeof dis);
	for(ri i=1;i<=v;++i)dis[i][i]=0;
	while(l--){
		ri x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		ckmin(dis[x][y],z);
		ckmin(dis[y][x],z);
	}
	for(ri k=1;k<=v;++k)
		for(ri i=1;i<=v;++i)
			for(ri j=1;j<=v;++j)
				ckmin(dis[i][j],dis[i][k]+dis[k][j]);
	printf("%d",half());
	return 0;
}
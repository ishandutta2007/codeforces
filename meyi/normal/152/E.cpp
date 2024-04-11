#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}},inf=0x3f3f3f3f,maxk=7,maxn=201;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct edge{
	int to,nxt;
}e[maxn<<2];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int a[maxn],all,f[1<<maxk][maxn],k,m,mx,n,pre[1<<maxk][maxn];
char ans[maxn];
inline int idx(int x,int y){return (x-1)*m+y;}
int q[maxn*maxn];
bool vis[maxn];
inline void spfa(int id){
	ri *f=::f[id],h=0,*pre=::pre[id],t=0;
	for(ri i=1;i<=mx;++i)
		if(f[i]<inf)
			q[t++]=i;
	while(h<t){
		ri p=q[h++];
		vis[p]=false;
		for(ri i=hd[p];i;i=e[i].nxt)
			if(f[p]+a[e[i].to]<f[e[i].to]){
				f[e[i].to]=f[p]+a[e[i].to];
				pre[e[i].to]=-p;
				if(!vis[e[i].to])q[t++]=e[i].to,vis[e[i].to]=true;
			}
	}
}
void dfs(int id1,int id2){
	ans[id2]='X';
	if(pre[id1][id2]>0)dfs(pre[id1][id2],id2),dfs(id1^pre[id1][id2],id2);
	if(pre[id1][id2]<0)dfs(id1,-pre[id1][id2]);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(ri i=1;i<=n;++i)
		for(ri j=1;j<=m;++j){
			ri id=idx(i,j);
			scanf("%d",a+id);
			for(ri l=0;l<4;++l){
				ri mx=i+d[l][0],my=j+d[l][1];
				if(mx>0&&mx<=n&&my>0&&my<=m)addedge(id,idx(mx,my));
			}
		}
	all=(1<<k)-1,mx=idx(n,m);
	clear(ans,mx,'.');
	for(ri i=1;i<=all;++i)clear(f[i],mx,0x3f);
	for(ri i=0,x,y;i<k;++i){
		scanf("%d%d",&x,&y);
		f[1<<i][idx(x,y)]=a[idx(x,y)];
	}
	for(ri S=1;S<=all;++S){
		for(ri T=(S-1)&S;T;T=(T-1)&S){
			if(T<(S^T))break;
			for(ri i=1;i<=mx;++i)
				if(f[T][i]+f[S^T][i]-a[i]<f[S][i]){
					f[S][i]=f[T][i]+f[S^T][i]-a[i];
					pre[S][i]=T;
				}
		}
		spfa(S);
	}
	auto it=min_element(f[all]+1,f[all]+mx+1);
	printf("%d\n",*it);
	dfs(all,it-f[all]);
	for(ri i=1;i<=n;++i,putchar(10))
		for(ri j=1;j<=m;++j)
			putchar(ans[idx(i,j)]);
	return 0;
}
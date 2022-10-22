#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int ans[maxn],m,n,q;
int dfs(int p,int f){
	ri mx=0;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			ri len=dfs(e[i].to,p)+1;
			ckmax(ans[p],max(ans[e[i].to],len+mx));
			ckmax(mx,len);
		}
	return mx;
}
struct dsu{
	int fa[maxn];
	inline void init(int k){for(ri i=1;i<=k;++i)fa[i]=i;}
	int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
	inline void merge(int x,int y){
		x=find(x),y=find(y);
		if(x!=y)fa[x]=y;
	}
}d;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	d.init(n);
	while(m--){
		ri x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
		d.merge(x,y);
	}
	for(ri i=1;i<=n;++i)
		if(d.find(i)==i)
			dfs(i,0);
	while(q--){
		ri op,x,y;
		scanf("%d%d",&op,&x);
		if(op&1)printf("%d\n",ans[d.find(x)]);
		else{
			scanf("%d",&y);
			x=d.find(x),y=d.find(y);
			if(x!=y){
				ckmax(ans[y],max(ans[x],(ans[x]+1)/2+(ans[y]+1)/2+1));
				d.fa[x]=y;
			}
		}
	}
	return 0;
}
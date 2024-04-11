#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int a[maxn],m,n,t_case;
void dfs1(int p,int fa){
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=fa){
			dfs1(e[i].to,p);
			if(a[e[i].to]>0)a[p]+=a[e[i].to];
		}
}
void dfs2(int p,int fa){
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=fa){
			if(a[e[i].to]>0)ckmax(a[e[i].to],a[p]);
			else ckmax(a[e[i].to],a[p]+a[e[i].to]);
			dfs2(e[i].to,p);
		}
}
signed main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		if(!a[i])a[i]=-1;
	}
	for(ri i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	dfs1(1,0);
	dfs2(1,0);
	for(ri i=1;i<=n;++i)printf("%d ",a[i]);
	return 0;
}
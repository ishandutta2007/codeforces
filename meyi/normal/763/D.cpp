#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef unsigned long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
struct edge{
	int v,to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to,int v=1){
	e[++len]={v,to,hd[fr]};
	hd[fr]=len;
}
unordered_map<ll,int>p;
ll hsh[maxn],hsh_fa[maxn],sum[maxn];
int ans1,ans2=-1,cnt,n,siz[maxn];
inline void insert(ll k){cnt+=!p[k]++;}
inline void erase(ll k){cnt-=!--p[k];}
void dfs1(int p,int f){
	siz[p]=1;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			dfs1(e[i].to,p);
			siz[p]+=siz[e[i].to];
			sum[p]+=hsh[e[i].to];
		}
	hsh[p]=(sum[p]+siz[p])*siz[p];
	insert(hsh[p]);
}
void dfs2(int p,int f){
	erase(hsh[p]);
	insert(hsh_fa[p]);
	if(cnt>ans2)ans1=p,ans2=cnt;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			hsh_fa[e[i].to]=(sum[p]-hsh[e[i].to]+n-siz[e[i].to])*(n-siz[e[i].to]);
			sum[e[i].to]+=hsh_fa[e[i].to];
			dfs2(e[i].to,p);
		}
	insert(hsh[p]);
	erase(hsh_fa[p]);
}
int main(){
	scanf("%d",&n);
	for(ri i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	dfs1(1,0);
	dfs2(1,0);
	printf("%d",ans1);
	return 0;
}
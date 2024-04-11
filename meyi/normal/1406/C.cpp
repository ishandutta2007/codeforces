#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int mx[maxn],n,siz[maxn],t_case;
vector<int>g;
void dfs(int p,int f){
	mx[p]=0;
	siz[p]=1;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			dfs(e[i].to,p);
			ckmax(mx[p],siz[e[i].to]);
			siz[p]+=siz[e[i].to];
		}
	ckmax(mx[p],n-siz[p]);
	if(mx[p]<mx[g.front()])g={p};
	else if(mx[p]==mx[g.front()])g.push_back(p);
}
int leaf(int p,int f){
	bool flag=true;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			flag=false;
			if(e[i].to==g.front())continue;
			ri tmp=leaf(e[i].to,p);
			if(tmp)return tmp;
		}
	if(flag)printf("%d %d\n",p,f);
	return flag?p:0;
}
signed main(){
	mx[0]=INT_MAX;
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)hd[i]=0;
		len=0;
		for(ri i=1,x,y;i<n;++i){
			scanf("%d%d",&x,&y);
			addedge(x,y),addedge(y,x);
		}
		g={0};
		dfs(1,0);
		if(g.size()&1)printf("%d %d\n%d %d\n",1,e[hd[1]].to,1,e[hd[1]].to);
		else{
			ri tmp=leaf(g.back(),0);
			printf("%d %d\n",g.front(),tmp);
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=1e5+10;
struct edge{
	int to,nxt;
}e[maxn<<1];
int deg[maxn],hd[maxn],len;
inline void addedge(int fr,int to){
	++deg[fr];
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int n,t_case;
void dfs(int p,int f,bool t){
	if(t)deg[p]=-deg[p];
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f)
			dfs(e[i].to,p,t^1);
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		clear(deg,n),clear(hd,n),len=0;
		for(ri i=1,x,y;i<n;++i){
			scanf("%d%d",&x,&y);
			addedge(x,y),addedge(y,x);
		}
		dfs(1,0,0);
		for(ri i=1;i<=n;++i)printf("%d%c",deg[i]," \n"[i==n]);
	}
	return 0;
}
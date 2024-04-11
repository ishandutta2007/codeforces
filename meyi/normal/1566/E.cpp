#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
struct edge{
	int v,to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to,int v=1){
	e[++len]={v,to,hd[fr]};
	hd[fr]=len;
}
int ans,n,t_case;
bool dfs(int p,int f){
	bool flag=false;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f)
			flag|=dfs(e[i].to,p);
	if(flag){
		if(p!=1)--ans;
		return 0;
	}
	else{
		++ans;
		return 1;
	}
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		len=0;
		for(ri i=1;i<=n;++i)hd[i]=0;
		for(ri i=1,x,y;i<n;++i){
			scanf("%d%d",&x,&y);
			addedge(x,y),addedge(y,x);
		}
		ans=0;
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
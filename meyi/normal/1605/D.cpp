#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
vector<int>b,w;
void dfs(int p,int f,bool t){
	(t?b:w).push_back(p);
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f)
			dfs(e[i].to,p,t^1);
}
int ans[maxn],m,n,t_case;
signed main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		len=0;
		for(ri i=1;i<=n;++i)hd[i]=0;
		for(ri i=1,x,y;i<n;++i){
			scanf("%d%d",&x,&y);
			addedge(x,y),addedge(y,x);
		}
		b=w={};
		dfs(1,0,1);
		if(b.size()<w.size())swap(b,w);
		ri bl=0,wl=0;
		for(ri i=1;i<=n;i<<=1)
			if(w.size()&i){
				for(ri j=0;wl<w.size()&&j<i;++wl,++j)ans[w[wl]]=i+j;
			}
			else{
				for(ri j=0;bl<b.size()&&j<i;++bl,++j)ans[b[bl]]=i+j;
			}
		for(ri i=1;i<=n;++i)printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}
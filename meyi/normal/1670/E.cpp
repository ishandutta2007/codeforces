#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
struct edge{
	int v,to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to,int v=0){
	e[++len]={v,to,hd[fr]};
	hd[fr]=len;
}
int a[maxn],cnt,m,n,t_case;
void dfs(int p,int f,bool t){
	if(f){
		++cnt;
		if(t)e[f].v=cnt+n,a[p]=cnt;
		else e[f].v=cnt,a[p]=cnt+n;
	}
	else a[p]=n;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(i!=(f^1))
			dfs(e[i].to,i,t^1);
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&m);
		n=1<<m;
		clear(hd,n),len=1;
		for(ri i=1,x,y;i<n;++i){
			scanf("%d%d",&x,&y);
			addedge(x,y),addedge(y,x);
		}
		cnt=0;
		dfs(1,0,0);
		puts("1");
		for(ri i=1;i<=n;++i)printf("%d ",a[i]);
		printf("\n");
		for(ri i=2;i<=len;i+=2)printf("%d ",e[i].v+e[i^1].v);
		printf("\n");
	}
	return 0;
}
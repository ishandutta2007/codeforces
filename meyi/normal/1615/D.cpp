#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e6+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct edge{
	int v,to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to,int v){
	e[++len]={v,to,hd[fr]};
	hd[fr]=len;
}
int ans[maxn],m,n,t_case,x[maxn],y[maxn],z[maxn];
bool flag;
void dfs(int p,int f){
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			if(ans[e[i].to]==-1){
				ans[e[i].to]=ans[p]^e[i].v;
				dfs(e[i].to,p);
			}
			else{
				if(ans[p]^ans[e[i].to]!=e[i].v)flag=true;
			}
		}
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		for(ri i=1;i<=n;++i)ans[i]=-1,hd[i]=0;
		len=0;
		for(ri i=1;i<n;++i){
			scanf("%d%d%d",x+i,y+i,z+i);
			if(z[i]!=-1)addedge(x[i],y[i],__builtin_parity(z[i])),addedge(y[i],x[i],__builtin_parity(z[i]));
		}
		for(ri i=1;i<=m;++i){
			ri a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			addedge(a,b,c),addedge(b,a,c);
		}
		flag=false;
		for(ri i=1;i<=n;++i)
			if(ans[i]==-1){
				ans[i]=0;
				dfs(i,0);
			}
		if(flag)puts("NO");
		else{
			puts("YES");
			for(ri i=1;i<n;++i)printf("%d %d %d\n",x[i],y[i],z[i]==-1?(ans[x[i]]^ans[y[i]]):z[i]);
		}
	}
	return 0;
}
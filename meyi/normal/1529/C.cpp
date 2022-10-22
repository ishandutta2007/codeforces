#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int a[2][maxn],m,n,t_case;
ll f[2][maxn];
void dfs(int p,int fa){
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=fa){
			dfs(e[i].to,p);
			f[0][p]+=max(f[0][e[i].to]+abs(a[0][p]-a[0][e[i].to]),f[1][e[i].to]+abs(a[0][p]-a[1][e[i].to]));
			f[1][p]+=max(f[0][e[i].to]+abs(a[1][p]-a[0][e[i].to]),f[1][e[i].to]+abs(a[1][p]-a[1][e[i].to]));
		}
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		len=0;
		for(ri i=1;i<=n;++i)hd[i]=0,scanf("%d%d",&a[0][i],&a[1][i]),f[0][i]=f[1][i]=0;
		for(ri i=1,x,y;i<n;++i){
			scanf("%d%d",&x,&y);
			addedge(x,y),addedge(y,x);
		}
		dfs(1,0);
		printf("%lld\n",max(f[0][1],f[1][1]));
	}
	return 0;
}
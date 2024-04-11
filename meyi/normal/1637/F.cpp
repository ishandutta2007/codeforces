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
int a[maxn],m,mx[maxn],n,t_case;
ll ans;
void dfs(int p,int f){
	ri mxx=0;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			dfs(e[i].to,p);
			if(mx[e[i].to]>mx[p])mxx=mx[p],mx[p]=mx[e[i].to];
			else ckmax(mxx,mx[e[i].to]);
		}
	if(mx[p]<a[p])ans+=a[p]-mx[p],mx[p]=a[p];
	if(!f)ans+=max(a[p]-mxx,0);
}
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	for(ri i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	dfs(max_element(a+1,a+n+1)-a,0);
	printf("%lld\n",ans);
	return 0;
}
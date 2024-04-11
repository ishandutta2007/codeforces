#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002;
struct edg{
	int a,b,c;
	bool operator<(const edg &k)const{
		return k.c>c;
	}
}e[N];
struct EI{
	int w,id;
	bool operator<(const EI &k)const{
		return k.w>w;
	}
}q[N];
int n,m,fa[N],sz[N],i,j,u,v;
long long ans,Ans[N];
int p(int x){
	return x==fa[x]?x:fa[x]=p(fa[x]);
}
void init(){
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++)
		scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
	for(i=1;i<=m;i++)
		scanf("%d",&q[i].w),q[i].id=i;
	sort(e+1,e+n);
	sort(q+1,q+m+1);
}
void work(){
	for(i=1;i<=n;i++)
		fa[i]=i,sz[i]=1;
	for(i=1;i<=m;i++){
		while(j<n&&e[j+1].c<=q[i].w){
			j++;
			u=e[j].a;v=e[j].b;
			u=p(u);v=p(v);
			ans+=1ll*sz[u]*sz[v];
			fa[u]=v;
			sz[v]+=sz[u];
		}
		Ans[q[i].id]=ans;
	}
	for(i=1;i<=m;i++)
		printf("%lld ",Ans[i]);
}
int main(){
	init();
	work();
	return 0;
}
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002;
int fa[N],sz[N],n,i,a[N],d[N],k,u,v,Ans[N];
bool cmp(int x,int y){
	return a[x]>a[y];
}
int p(int x){
	return x==fa[x]?x:fa[x]=p(fa[x]);
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),d[i]=fa[i]=i,sz[i]=1;
	sort(d+1,d+n+1,cmp);
	for(i=1;i<=n;i++){
		k=d[i];
		if(a[k]<=a[k+1]){
			u=p(k);v=p(k+1);
			if(u!=v){
				sz[u]+=sz[v];
				fa[v]=u;
			}
		}
		if(a[k]<=a[k-1]){
			u=p(k);v=p(k-1);
			if(u!=v){
				sz[u]+=sz[v];
				fa[v]=u;
			}
		}
		u=p(k);
		Ans[sz[u]]=max(Ans[sz[u]],a[k]);
	}
	for(i=n;i;i--)
		Ans[i]=max(Ans[i],Ans[i+1]);
	for(i=1;i<=n;i++){
		printf("%d ",Ans[i]);
	}
	//while(1);
}
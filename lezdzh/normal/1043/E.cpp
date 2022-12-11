#include<cstdio>
#include<algorithm>
using namespace std;

int x[300001],y[300001],a[300001];
bool cmp(int u,int v){
	return x[u]-y[u]<x[v]-y[v];
}
long long ans[300001];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]),a[i]=i;
	sort(a+1,a+n+1,cmp);
	long long s=0;
	for(int i=1;i<=n;i++)
		ans[a[i]]+=s+1ll*(i-1)*y[a[i]],s+=x[a[i]];
	s=0;
	for(int i=n;i;i--)
		ans[a[i]]+=s+1ll*(n-i)*x[a[i]],s+=y[a[i]];
	for(int i=1;i<=m;i++){
		int p,q;
		scanf("%d%d",&p,&q);
		int w=min(x[p]+y[q],x[q]+y[p]);
		ans[p]-=w;
		ans[q]-=w;
	}
	for(int i=1;i<=n;i++)
		printf("%I64d%c",ans[i],i==n?'\n':' ');
}
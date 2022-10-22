#include <bits/stdc++.h>
using namespace std;
#define N 100005
int T,n,a[N],ps[N],col[N];bool vs[N],vs1[N];
void dfs(int u)
{
	printf("%d ",u);vs[u]=vs1[col[u]]=1;
	if(u>1 && !vs[ps[u-1]] && !vs1[col[u-1]]) dfs(ps[u-1]);
	if(u<n && !vs[ps[u+1]] && !vs1[col[u+1]]) dfs(ps[u+1]);
	if(!vs[ps[u]]) dfs(ps[u]);
}
void slv()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]),vs[i]=vs1[i]=col[i]=0,ps[a[i]]=i;
	for(int i=1;i<=n;++i) if(!col[i])
	{col[i]=i;for(int j=ps[i];j!=i;j=ps[j]) col[j]=i;}
	dfs(1);putchar('\n');
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}
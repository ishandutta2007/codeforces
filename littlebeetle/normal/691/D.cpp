#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1000002;
int n,m,i,u,v,a[N],f[N];
int p(int x){
	return x==f[x]?x:f[x]=p(f[x]);
}
vector<int>e[N];
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),f[i]=i;
	for(i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		u=p(u);v=p(v);
		if(u!=v)
			f[u]=v;
	}
	for(i=1;i<=n;i++)	
		e[p(i)].push_back(a[i]);
	for(i=1;i<=n;i++)
		sort(e[i].begin(),e[i].end());
	for(i=1;i<=n;i++){
		printf("%d ",e[p(i)].back());
		e[p(i)].pop_back();
	}
}
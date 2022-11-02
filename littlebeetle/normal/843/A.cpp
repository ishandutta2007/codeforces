#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100002;
struct T{
	int a,id;
	bool operator<(T const &k)const{
		return k.a>a;
	}
}x[N];
int n,i,j,fa[N],u,v,val[N],cnt,sz[N];
int p(int x){
	return x==fa[x]?x:fa[x]=p(fa[x]);
}
vector<int>g[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x[i].a);
		x[i].id=i;
		fa[i]=i;
	}
	sort(x+1,x+n+1);
	for(i=1;i<=n;i++){
		u=i;
		v=x[i].id;
		if(p(u)!=p(v))
			fa[u]=v;
	}
	for(i=1;i<=n;i++){
		if(!val[p(i)])
			val[p(i)]=++cnt;
		sz[val[p(i)]]++;
		g[val[p(i)]].push_back(i);
	}
	printf("%d\n",cnt);
	for(i=1;i<=cnt;i++){
		printf("%d ",sz[i]);
		for(j=0;j<g[i].size();j++)
			printf("%d ",g[i][j]);
		printf("\n");
	}
}
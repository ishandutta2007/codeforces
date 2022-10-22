#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,m,pre[MAXN],siz[MAXN];
int fnd(int x){
	if(x!=pre[x]) pre[x]=fnd(pre[x]);
	return pre[x];
}
bool vis[MAXN],vp[MAXN];
vector<int> to[MAXN];
int main(){
	//freopen("offices.in","r",stdin);
	//freopen("offices.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		to[u].push_back(v);
		to[v].push_back(u);
	}
	for(int i=1; i<=n; i++)
		pre[i]=i;
	int p=1;
	for(int i=2; i<=n; i++)
		if(to[i].size()<to[p].size()) p=i;
	for(int i:to[p]) vp[i]=1;
	for(int i=1; i<=n; i++)
		if(!vp[i]) pre[fnd(i)]=fnd(p);
	for(int i=0; i<to[p].size(); i++){
		int u=to[p][i];
		for(int j:to[u]) vis[j]=1;
		for(int j:to[p])
			if(!vis[j]) pre[fnd(u)]=fnd(j);
		for(int j=1; j<=n; j++)
			if(!vp[j]&&!vis[j]){
				pre[fnd(u)]=fnd(p);
				break;
			}
		for(int j:to[u]) vis[j]=0;
	}
	for(int i=1; i<=n; i++)
		siz[fnd(i)]++;
	sort(siz+1,siz+n+1);
	int w=1;
	while(!siz[w]) w++;
	printf("%d\n",n-w+1);
	for(int i=w; i<=n; i++)
		printf("%d ",siz[i]);
	puts("");
	return 0;
}
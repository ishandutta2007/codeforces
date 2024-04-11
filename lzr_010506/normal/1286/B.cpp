#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=2005;
vector<int> G[Maxn];
int n,c[Maxn],siz[Maxn];
vector<int> ord[Maxn];
void dfs1(int x){
	siz[x]=1;
	for (int i=0;i<G[x].size();i++){
		dfs1(G[x][i]);siz[x]+=siz[G[x][i]];
		
	}
	if (siz[x]-1<c[x]){
			printf("NO\n");
			exit(0);
		}
}
void dfs2(int x){
	for (int i=0;i<G[x].size();i++){
		dfs2(G[x][i]);
		for (int j=0;j<ord[G[x][i]].size();j++){
			ord[x].pb(ord[G[x][i]][j]);
		} 
	}
	vector<int> tmp;
	for (int i=0;i<c[x];i++) tmp.pb(ord[x][i]);
	tmp.pb(x);
	for (int i=c[x];i<ord[x].size();i++) tmp.pb(ord[x][i]);
	ord[x]=tmp;
	//cout<<x<<' '<<ord[x].size()<<endl;
}
int ans[Maxn];
int main(){
	scanf("%d",&n);
	int rt;
	for (int i=1;i<=n;i++){
		int p;
		scanf("%d %d",&p,&c[i]);
		if (p) G[p].pb(i);
		else rt=i;
	}
	//cerr<<rt<<endl;
	dfs1(rt);
	dfs2(rt);
	for (int i=0;i<ord[rt].size();i++){
		ans[ord[rt][i]]=i+1;
	}
	printf("YES\n");
	for (int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}
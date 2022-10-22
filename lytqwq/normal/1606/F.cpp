#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,q,Head[N],Next[N<<1],V[N<<1],cnt;
void add(int u,int v){
	V[cnt]=v;
	Next[cnt]=Head[u];
	Head[u]=cnt++;
}
vector<int> f[N];
void dfs(int u,int fa){
	vector<int> res;
	res.clear();
	for(int i=Head[u];i!=-1;i=Next[i]){
		if(V[i]!=fa){
			dfs(V[i],u);
			for(int k=0;;k++){
				if(k==f[u].size())f[u].push_back(0);
				int p=k<f[V[i]].size()?f[V[i]][k]-k:f[V[i]].back()-k;
				if(p<=0){
					res.push_back(k);
					break;
				}
				f[u][k]+=p;
			}
		}
	}
	if(f[u].empty())f[u].push_back(0);
	vector<int> c(f[u].size()+1);
	for(int i=0;i<res.size();i++){
		c[res[i]]++;
	}
	for(int i=0;i<f[u].size();i++){
		if(i!=0)c[i]+=c[i-1];
		f[u][i]+=c[i];
	}
}
int main(){
	memset(Head,-1,sizeof(Head));
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	dfs(1,0);
	scanf("%d",&q);
	while(q--){
		int u,k;
		scanf("%d%d",&u,&k);
		if(k<f[u].size())printf("%d\n",f[u][k]);
		else printf("%d\n",f[u].back());
	}
}
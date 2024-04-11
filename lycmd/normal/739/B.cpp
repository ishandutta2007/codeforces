#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333,M=23;
int n,a[N],d[N],cnt[N],fa[N][M];
vector<int>e[N],w[N];
void dfs(int x){
	for(int i=1;i<M;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	int p=x;
	for(int i=19;~i;i--)
		if(fa[p][i]&&d[x]-d[fa[p][i]]<=a[x])
			p=fa[p][i];
	cnt[fa[p][0]]--,cnt[fa[x][0]]++;
	for(int i=0;i<e[x].size();i++){
		int y=e[x][i];
		d[y]=d[x]+w[x][i],dfs(y),cnt[x]+=cnt[y];
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2;i<=n;i++){
		int x,k;
		cin>>x>>k,fa[i][0]=x;
		e[x].push_back(i);
		w[x].push_back(k);
	}
	dfs(1);
	for(int i=1;i<=n;i++)
		cout<<cnt[i]<<" ";
	cout<<"\n";
}
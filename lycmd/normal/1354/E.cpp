#include<bits/stdc++.h>
using namespace std;
int const N=5010;
int n,m,a1,a2,a3,tot,p[N],res[N],cnt[N*2],f[N][N];
vector<int>e[N];
void dfs(int x,int c){
	cnt[p[x]=c]++;
	for(int y:e[x])
		if(!p[y])
			dfs(y,c^1);
		else if(~(p[x]-p[y])&1)
			cout<<"NO\n",exit(0);
}
int main(){
	ios::sync_with_stdio(0);
	for(cin>>n>>m>>a1>>a2>>a3;m--;){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x); 
	}
	for(int i=1;i<=n;i++)
		if(!p[i])
			dfs(i,(++tot)<<1);
	f[0][0]=1;
	for(int i=1;i<=tot;i++)
		for(int t=0;t<2;t++)
			for(int w=cnt[i<<1|t],j=w;j<=n;j++)
				f[i][j]|=f[i-1][j-w];
	if(!f[tot][a2])
		cout<<"NO\n",exit(0);
	cout<<"YES\n";
	for(int i=tot,j=a2;i;i--)
		if(j>=cnt[i<<1]&&f[i-1][j-cnt[i<<1]])
			res[i]=0,j-=cnt[i<<1];
		else
			res[i]=1,j-=cnt[i<<1|1];
	for(int i=1;i<=n;i++)
		cout<<(~(res[p[i]>>1]-p[i])&1?'2':a1?(a1--,'1'):'3');
	cout<<"\n";
}
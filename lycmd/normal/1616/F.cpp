#include<bits/stdc++.h>
using namespace std;
int const N=305,M=5010;
int t,n,m,tot,ans[N],e[N][N],f[M][N];
void add(const vector<pair<int,int> >&v){
	tot++,memset(f[tot],0,sizeof f[tot]);
	for(auto i:v)f[tot][i.first]=i.second;
}
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		memset(e,0,sizeof e);
		cin>>n>>m,tot=0;
		for(int i=1;i<=m;i++){
			int a,b,c;cin>>a>>b>>c;
			e[a][b]=e[b][a]=i;
			if(~c)add({{i,1},{m+1,c-1}});
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					if(e[i][j]&&e[i][k]&&e[j][k])
						add({{e[i][j],1},{e[i][k],1},{e[j][k],1}});
		int cur=0;
		for(int i=1;i<=m;i++){
			int p=0;
			for(int j=cur+1;j<=tot;j++)
				p=f[j][i]?j:p;
			if(!p){
				ans[i]=0;
				continue;
			}
			swap(f[++cur],f[p]);
			if(f[cur][i]!=1)
				for(int j=i;j<=m+1;j++)
					f[cur][j]=(3-f[cur][j])%3;
			for(int j=1;j<=tot;j++)
				if(f[j][i]&&j!=cur)
					for(int v=f[j][i],k=i;k<=m+1;k++)
						f[j][k]=(f[j][k]-v*f[cur][k]+9)%3;
		}
		int flg=0;
		for(int i=cur+1;i<=tot;i++)
			flg|=f[i][m+1];
		if(flg){
			cout<<"-1\n";
			continue;
		}
		for(int i=1;i<=cur;i++){
			int j=i;
			while(!f[i][j])j++;
			ans[j]=f[i][m+1];
		}
		for(int i=1;i<=m;i++)
			cout<<ans[i]+1<<" ";
		cout<<"\n"; 
	}
}
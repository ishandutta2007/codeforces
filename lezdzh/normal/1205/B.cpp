#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

long long a[100001];
vector<int>gg[64],g[100001];
int d[100001];
int f[1001][1001];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==0){
			i--,n--;
			continue;
		}
		for(int j=60;j>=0;j--)
			if(a[i]>>j&1)gg[j].push_back(i);
	}
	for(int i=0;i<=60;i++)
		if(gg[i].size()>=3){
			printf("3\n");
			return 0;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=1e9;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[i]&a[j]){
				f[i][j]=f[j][i]=1;
//				g[i].push_back(j);
//				g[j].push_back(i);
			}
	int ans=1e9;/*
	for(int o=1;o<=n;o++){
		for(int i=1;i<=n;i++)
			d[i]=2e9;
		queue<int>q;
		q.push(o);
		d[o]=1;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=0;i<g[u].size();i++){
				if(d[g[u][i]]&&d[g[u][i]]+d[u]-1>=3)
					ans=min(ans,d[u]+d[g[u][i]]-1);
				if(d[g[u][i]]==2e9){
					d[g[u][i]]=d[u]+1;
					q.push(g[u][i]);
				}
			}
		}
	}*/
	for(int k=1;k<=n;k++){
		for(int i=1;i<=k-1;i++)
			for(int j=i+1;j<=k-1;j++)
				if((a[i]&a[k])&&(a[j]&a[k]))
					ans=min(ans,f[i][j]+2);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	}
	printf("%d\n",ans==1e9?-1:ans);
}
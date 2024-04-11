#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int f[4000001],d[4000001];
char a[2000][2001];
vector<int>g[4000001];
int main(){
	int n,m,r,c,x,y;
	scanf("%d%d%d%d%d%d",&n,&m,&r,&c,&x,&y);
	for(int i=0;i<n;i++)
		scanf("%s",a[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(!f[i*m+j])
				for(int k=i;k<n&&a[k][j]!='*';k++)
					f[k*m+j]=i*m+j+1;
//	for(int i=0;i<n;i++,printf("\n"))
//		for(int j=0;j<m;j++)
//			printf("%d",f[i*m+j]);
	for(int i=0;i<n;i++)
		for(int j=0;j+1<m;j++)
			if(a[i][j]=='.'&&a[i][j+1]=='.')
				g[f[i*m+j]].push_back(f[i*m+j+1]),
				g[f[i*m+j+1]].push_back(f[i*m+j]);
	queue<int>q;
	q.push(f[(r-1)*m+c-1]);
	d[f[(r-1)*m+c-1]]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++)
			if(!d[g[u][i]])q.push(g[u][i]),d[g[u][i]]=d[u]+1;
	}
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)if(a[i][j]=='.'&&d[f[i*m+j]]){
			int z=j-c+1;
			int xx=(d[f[i*m+j]]-z)/2,yy=(d[f[i*m+j]]+z)/2;
//			printf("%d %d\n",xx,yy);
			if(xx<=x&&yy<=y)ans++;
		}
	printf("%d\n",ans);
}
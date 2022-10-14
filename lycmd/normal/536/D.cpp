#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=2010,INF=0x3f3f3f3f3f3f3f3fll;
int n,m,q,t,a[N],vis[N],d1[N],d2[N],e[N][N],
	f[2][N][N],c[N][N],s[N][N];
vector<int>b;
int dijkstra(int s,int*d){
	for(int i=0;i<=n;i++)
		d[i]=INF,vis[i]=0; 
	d[s]=0;
	for(int i=1;i<=n;i++){
		int t=0;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&d[j]<d[t])
				t=j;
		vis[t]=1;
		for(int j=1;j<=n;j++)
			if(!vis[j])
				d[j]=min(d[j],d[t]+e[j][t]);
	}
	b.clear();
	for(int i=1;i<=n;i++)
		b.push_back(d[i]);
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	for(int i=1;i<=n;i++)
		d[i]=lower_bound(b.begin(),b.end(),d[i])-b.begin()+1;
	return b.size();
}
int sum(int ax,int ay,int bx,int by,int(*s)[N]){
	return s[bx][by]-s[ax-1][by]-s[bx][ay-1]+s[ax-1][ay-1];
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>q>>t;
	memset(e,0x3f,sizeof e);
	for(int i=1;i<=n;i++)
		cin>>a[i],e[i][i]=0;
	while(m--){
		int x,y,k;cin>>x>>y>>k;
		e[x][y]=e[y][x]=min(e[x][y],k);
	}
	int m1=dijkstra(q,d1),m2=dijkstra(t,d2);
	for(int i=1;i<=n;i++)
		c[d1[i]][d2[i]]++,s[d1[i]][d2[i]]+=a[i];
	for(int i=1;i<=m1;i++)
		for(int j=1;j<=m2;j++)
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1],
			c[i][j]+=c[i-1][j]+c[i][j-1]-c[i-1][j-1];
	for(int i=m1;i;i--)
		for(int j=m2;j;j--){
			f[0][i][j]=sum(i,j,i,m2,c)?
				max(f[0][i+1][j],f[1][i+1][j])+
				sum(i,j,i,m2,s):f[0][i+1][j];
			f[1][i][j]=sum(i,j,m1,j,c)?
				min(f[0][i][j+1],f[1][i][j+1])-
				sum(i,j,m1,j,s):f[1][i][j+1];
		}
	cout<<(!f[0][1][1]?"Flowers\n":f[0][1][1]<0?"Cry\n":
		"Break a heart\n");
}
#include<bits/stdc++.h>
const int N=405,mod=998244353;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S;
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}

int n,m;
int dis[N][N],fa[N][N];
int R[N][N];
int w[N],v[N];

int calc(int x,int y){
	if(x>y)return R[y][x];
	if(fa[x][y]!=1)return 0;
	int res=1;
	for(int k=1;k<=n;k++){
		if(dis[k][x]+dis[k][y]==dis[x][y])continue;
		int c=0;
		fore(k)
			c+=dis[k][x]==dis[_to][x]+1&&dis[k][y]==dis[_to][y]+1;
		res=1ll*res*c%mod;
	}
	return R[x][y]=res;
}

void solve(){
	cin>>n>>m;
	memset(dis,1,sizeof(dis));
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		dis[x][y]=dis[y][x]=1;
		fa[x][y]=fa[y][x]=1;
		add(x,y),add(y,x); 
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(dis[i][k]+dis[k][j]<dis[i][j])
					dis[i][j]=dis[k][j]+dis[i][k],fa[i][j]=fa[i][k]*fa[k][j];
				else if(dis[i][k]+dis[k][j]==dis[i][j])	
					fa[i][j]+=fa[i][k]*fa[k][j]; 
				fa[i][j]=min(fa[i][j],2);
			}
	for(int i=1;i<=n;i++)
		dis[i][i]=0,fa[i][i]=1; 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cout<<calc(i,j)<<" \n"[j==n];
	
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;//cin>>_T;
	while(_T--)solve();
	
}
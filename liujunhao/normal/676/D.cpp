#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define MAXN 1000
#define INF 0x7fffffff
using namespace std;
typedef pair<int,int>pii;
queue<int>q;
int n,m,sx,sy,ex,ey,dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}},dist[MAXN*MAXN*4+10];
bool vis[MAXN*MAXN*4+10];
bool ok[MAXN+1][MAXN+1][4];
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
char s[MAXN+10][MAXN+10];
void read(){
	Read(n),Read(m);
	int i;
	for(i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	Read(sx),Read(sy),Read(ex),Read(ey);
}
inline int Get_point(int i,int j,int r){
	return r*n*m+((i-1)*m+j);
}
void solve(){
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(s[i][j]=='+')
				ok[i][j][0]=ok[i][j][1]=ok[i][j][2]=ok[i][j][3]=1;
			else if(s[i][j]=='-')
				ok[i][j][1]=ok[i][j][3]=1;
			else if(s[i][j]=='|')
				ok[i][j][0]=ok[i][j][2]=1;
			else if(s[i][j]=='^')
				ok[i][j][0]=1;
			else if(s[i][j]=='>')
				ok[i][j][1]=1;
			else if(s[i][j]=='v')
				ok[i][j][2]=1;
			else if(s[i][j]=='<')
				ok[i][j][3]=1;
			else if(s[i][j]=='L')
				ok[i][j][0]=ok[i][j][1]=ok[i][j][2]=1;
			else if(s[i][j]=='R')
				ok[i][j][0]=ok[i][j][3]=ok[i][j][2]=1;
			else if(s[i][j]=='U')
				ok[i][j][3]=ok[i][j][1]=ok[i][j][2]=1;
			else if(s[i][j]=='D')
				ok[i][j][0]=ok[i][j][1]=ok[i][j][3]=1;
}
void Dijkstra(){
	int u,i,j,k,v,nd,d;
	for(i=Get_point(n,m,3);i;i--)
		dist[i]=INF;
	dist[Get_point(sx,sy,0)]=0;
	q.push(Get_point(sx,sy,0));
	while(!q.empty()){
		u=q.front();
		q.pop();
		if(vis[u])
			continue;
		vis[u]=1;
		k=(u-1)/(n*m);
		i=(u-k*m*n-1)/m+1;
		j=(u-1)%m+1;
		if(i==ex&&j==ey){
			printf("%d\n",dist[u]);
			return;
		}
		if(dist[v=Get_point(i,j,(k+1)&3)]>dist[u]+1){
			dist[v]=dist[u]+1;
			q.push(v);
		}
		for(d=0;d<4;d++)
			if(ok[i][j][d]){
				nd=(d+k)&3;
				if(i+dir[nd][0]&&i+dir[nd][0]<=n&&j+dir[nd][1]&&j+dir[nd][1]<=m)
					if(ok[i+dir[nd][0]][j+dir[nd][1]][(((nd^2)-k)+4)&3]){
						if(dist[v=Get_point(i+dir[nd][0],j+dir[nd][1],k)]>dist[u]+1)
							dist[v]=dist[u]+1;
							q.push(v);
					}
			}
	}
	puts("-1");
}
int main()
{
	read();
	solve();
	Dijkstra();
}
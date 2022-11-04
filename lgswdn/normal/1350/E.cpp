#include<bits/stdc++.h>
using namespace std;
const int N=1e3+9;
int n,m,t,a[N][N],f[N][N]; bool vst[N][N];
bool ok(int x,int y){return x>0&&x<=n&&y>0&&y<=m;}
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
struct node{int x,y;};
void bfs(){
	queue<node>q;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			bool move=0;
			for(int k=0,nx,ny;k<4;k++)
				move|=(ok(nx=i+dx[k],ny=j+dy[k])&&a[i][j]==a[nx][ny]);
			if(move) q.push((node){i,j}),f[i][j]=1,vst[i][j]=1;
		}
	while(!q.empty()){
		int x=q.front().x,y=q.front().y; q.pop();
		for(int k=0,nx,ny;k<4;k++)
			if(ok(nx=x+dx[k],ny=y+dy[k])&&!vst[nx][ny]){
				f[nx][ny]=f[x][y]+1;
				q.push((node){nx,ny});
				vst[nx][ny]=1;
			} 
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=n;i++){
		string s; cin>>s;
		for(int j=1;j<=m;j++) a[i][j]=s[j-1]-'0';
	}
	bfs();
	for(int i=1,x,y;i<=t;i++){
		long long p; scanf("%d%d%lld",&x,&y,&p);
		if(f[x][y]==0) printf("%d\n",a[x][y]);
		else printf("%d\n",a[x][y]^(max(p-f[x][y]+1,0ll)%2));
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int const N=1605,dx[]={-1,0,0,1,-1,-1,1,1},dy[]={0,-1,1,0,-1,1,-1,1};
int n,m,tot,a[N][N],b[N][N],c[N][N],id[N][N],ans[N];
void dfs(int x,int y,int k){
	if(!a[x][y]||id[x][y])
		return;
	id[x][y]=k;
	for(int i=0;i<4;i++)
		dfs(x+dx[i],y+dy[i],k);
}
void clr(int x,int y){
	if(!c[x][y]||a[x][y]||!id[x][y])
		return;
	id[x][y]=0;
	for(int i=0;i<4;i++)
		clr(x+dx[i],y+dy[i]);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int x=1;x<=n;x++)
		for(int y=1;y<=m;y++)
			if(a[x][y]&&!id[x][y])
				dfs(x,y,++tot);
	memcpy(c,a,sizeof a);
	for(int i=1;i<=3;i++){
		for(int x=1;x<=n;x++)
			for(int y=1;y<=m;y++)
				b[x][y]=1;
		for(int x=1;x<=n;x++)
			for(int y=1;y<=m;y++)
				for(int p=0;p<8;p++)
					b[x][y]&=a[x+dx[p]][y+dy[p]];
		memcpy(a,b,sizeof a);
	}
	for(int i=1;i<=6;i++){
		memset(b,0,sizeof b);
		for(int x=1;x<=n;x++)
			for(int y=1;y<=m;y++)
				for(int p=0;p<8;p++)
					b[x][y]|=a[x+dx[p]][y+dy[p]];
		memcpy(a,b,sizeof a);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(c[i][j]&&!a[i][j]&&id[i][j])
				ans[id[i][j]]++,clr(i,j);
	sort(ans+1,ans+1+tot);
	cout<<tot<<"\n";
	for(int i=1;i<=tot;i++)
		cout<<ans[i]<<" ";
	cout<<"\n";
}
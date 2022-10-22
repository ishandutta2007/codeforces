#include<bits/stdc++.h>
using namespace std;
#define ri register int
const int d[3][2]={{0,1},{0,-1},{-1,0}};
char s[510][510];
int ans,cnt,f[510][510],m,n,t;
struct node{
	int x,y;
};
queue<node>q[2];
inline bool check(int x,int y){
	for(ri i=0;i<3;++i){
		int mx=x+d[i][0],my=y+d[i][1];
		if(mx>0&&mx<=n&&my>0&&my<=m&&f[x][y]<=f[mx][my]);
		else return false;
	}
	return true;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(ri i=1;i<=n;++i)scanf("%s",s[i]+1);
		memset(f,0,sizeof f);
		for(ri i=1;i<=n;++i)
			for(ri j=1;j<=m;++j)
				if(s[i][j]=='*')
					++cnt,f[i][j]=1,q[1].push({i,j});
		ans=cnt;
		for(ri i=2;cnt;++i){
			cnt=0;
			int now=!(i&1),nxt=i&1;
			while(q[now].size()){
				int nx=q[now].front().x,ny=q[now].front().y;
				q[now].pop();
				if(check(nx,ny))++cnt,f[nx][ny]=i,q[nxt].push({nx,ny});
			}
			ans+=cnt;
		}
		printf("%d\n",ans);
	}
}
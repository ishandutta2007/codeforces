#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}},maxn=2010;
int ans,lx,ly,m,n,rx[maxn][maxn],ry[maxn][maxn],sx,sy;
char s[maxn][maxn];
bool vis[maxn][maxn];
struct node{int x,y,xx,yy;};
queue<node>q;
int main(){
	scanf("%d%d%d%d%d%d",&n,&m,&sx,&sy,&lx,&ly);
	for(ri i=1;i<=n;++i)scanf("%s",s[i]+1);
	++ans,vis[sx][sy]=true;
	q.push({sx,sy,0,0});
	while(q.size()){
		ri nx=q.front().x,ny=q.front().y,ux=q.front().xx,uy=q.front().yy;q.pop();
		for(ri i=0;i<4;++i){
			ri mx=nx+d[i][0],my=ny+d[i][1];
			if(mx>0&&mx<=n&&my>0&&my<=m&&s[mx][my]=='.'){
				if(ux==lx&&i==2)continue;
				if(uy==ly&&i==3)continue;
				if(!vis[mx][my]){
					++ans,vis[mx][my]=true;
					q.push({mx,my,rx[mx][my]=ux+(i==2),ry[mx][my]=uy+(i==3)});
				}
				else if(ux+(i==2)<rx[mx][my]||uy+(i==3)<ry[mx][my])q.push({mx,my,rx[mx][my]=ux+(i==2),ry[mx][my]=uy+(i==3)});
			}
		}
	}
	printf("%d",ans);
	return 0;
}
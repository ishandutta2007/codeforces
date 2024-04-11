#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}},maxn=1e3+10;
int a[maxn],ans[maxn][maxn],m,n,ql,tim[maxn][maxn];
char s[maxn][maxn];
typedef pair<int,int> pii;
#define fi first
#define se second
queue<pii>q;
int main(){
	scanf("%d%d%d",&n,&m,&ql);
	memset(ans,-1,sizeof ans);
	for(ri i=1;i<=n;++i){
		scanf("%s",s[i]+1);
		for(ri j=1;j<=m;++j){
			if(s[i][j]==s[i-1][j]){
				if(ans[i][j]==-1)q.emplace(i,j);
				if(ans[i-1][j]==-1)q.emplace(i-1,j);
				ans[i][j]=ans[i-1][j]=s[i][j]^48;
			}
			if(s[i][j]==s[i][j-1]){
				if(ans[i][j]==-1)q.emplace(i,j);
				if(ans[i][j-1]==-1)q.emplace(i,j-1);
				ans[i][j]=ans[i][j-1]=s[i][j]^48;
			}
		}
	}
	while(q.size()){
		ri nx=q.front().fi,ny=q.front().se;q.pop();
		for(ri i=0;i<4;++i){
			ri mx=nx+d[i][0],my=ny+d[i][1];
			if(mx>0&&mx<=n&&my>0&&my<=m&&ans[mx][my]==-1)ans[mx][my]=ans[nx][ny],q.emplace(mx,my),tim[mx][my]=tim[nx][ny]+1;
		}
	}
	while(ql--){
		ri x,y;
		ll z;
		scanf("%d%d%lld",&x,&y,&z);
		if(ans[x][y]==-1||z<=tim[x][y])putchar(s[x][y]);
		else putchar((ans[x][y]^(z&1))|48);
		putchar(10);
	}
	return 0;
}
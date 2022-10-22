#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e3+10;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
const int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const ll inf=0x3f3f3f3f3f3f3f3fll;
int a[maxn][maxn],m,n,w;
ll ans,f[maxn][maxn];
inline ll bfs(int sx,int sy){
	queue<pii>q;
	q.push(pii(sx,sy));
	f[sx][sy]=0;
	ll ret=inf;
	while(q.size()){
		pii now=q.front();q.pop();
		if(a[now.x][now.y]>0)ret=min(ret,a[now.x][now.y]+f[now.x][now.y]);
		for(ri i=0;i<4;++i){
			ri mx=now.x+d[i][0],my=now.y+d[i][1];
			if(mx>0&&mx<=n&&my>0&&my<=m&&a[mx][my]!=-1&&f[now.x][now.y]+w<f[mx][my]){
				f[mx][my]=f[now.x][now.y]+w;
				q.push(pii(mx,my));
			}
		}
	}
	return ret;
}
signed main(){
	memset(f,0x3f,sizeof f);
	scanf("%d%d%d",&n,&m,&w);
	for(ri i=1;i<=n;++i)
		for(ri j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	ans=bfs(1,1);
	if(f[n][m]!=inf){
		ll tmp=f[n][m];
		ans=min(tmp,ans+bfs(n,m));
	}
	else ans+=bfs(n,m);
	printf("%lld",ans>=inf?-1ll:ans);
	return 0;
}
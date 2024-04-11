#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
#define MAXN 50
typedef pair<int,int>pii;
queue<pii>q;
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
int n,m,k,cnt,dir[4][2]={1,0,0,1,-1,0,0,-1},ans;
pair<int,pii>a[MAXN*MAXN+10];
char s[MAXN+10][MAXN+10];
bool vis[MAXN+10][MAXN+10];
void read(){
	Read(n),Read(m),Read(k);
	int i;
	for(i=1;i<=n;i++)
		scanf("%s",s[i]+1);
}
void bfs(int sx,int sy){
	q.push(pii(sx,sy));
	vis[sx][sy]=1;
	bool flag=0;
	int sz=0;
	while(!q.empty()){
		sz++;
		pii u=q.front();
		q.pop();
		int x=u.first,y=u.second;
		if(x==1||y==1||x==n||y==m)
			flag=1;
		for(int d=0;d<4;d++){
			int tx=x+dir[d][0],ty=y+dir[d][1];
			if(tx&&ty&&tx<=n&&ty<=m&&!vis[tx][ty]&&s[tx][ty]=='.')
				vis[tx][ty]=1,q.push(pii(tx,ty));
		}
	}
	if(!flag)
		a[++cnt]=make_pair(sz,pii(sx,sy));
}
void bfs2(int sx,int sy){
	q.push(pii(sx,sy));
	vis[sx][sy]=1;
	while(!q.empty()){
		pii u=q.front();
		q.pop();
		int x=u.first,y=u.second;
		s[x][y]='*';
		for(int d=0;d<4;d++){
			int tx=x+dir[d][0],ty=y+dir[d][1];
			if(tx&&ty&&tx<=n&&ty<=m&&!vis[tx][ty]&&s[tx][ty]=='.')
				vis[tx][ty]=1,q.push(pii(tx,ty));
		}
	}
}
void solve(){
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(s[i][j]=='.'&&!vis[i][j])
				bfs(i,j);
	memset(vis,0,sizeof vis);
	sort(a+1,a+cnt+1,greater<pair<int,pii> >());
	for(i=k+1;i<=cnt;i++){
		ans+=a[i].first;
		bfs2(a[i].second.first,a[i].second.second);
	}
}
int main()
{
	read();
	solve();
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
		puts(s[i]+1);
}
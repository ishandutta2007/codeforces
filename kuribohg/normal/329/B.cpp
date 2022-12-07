#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
#include<queue>
using namespace std;
const int MAXN=1010;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int n,m,d[MAXN][MAXN],sx,sy,ans;
char str[MAXN][MAXN];
queue<pair<int,int> > q;
inline bool valid(int x,int y)
{
	if(x<=0||x>n) return false;
	if(y<=0||y>m) return false;
	if(str[x][y]=='T') return false;
	if(d[x][y]!=n*m) return false;
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",str[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			d[i][j]=n*m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(str[i][j]=='E') q.push(make_pair(i,j)),d[i][j]=0;
	while(!q.empty())
	{
		pair<int,int> o=q.front();q.pop();
		for(int k=0;k<4;k++)
			if(valid(o.first+dx[k],o.second+dy[k]))
			{
				d[o.first+dx[k]][o.second+dy[k]]=d[o.first][o.second]+1;
				q.push(make_pair(o.first+dx[k],o.second+dy[k]));
			}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(str[i][j]=='S') sx=i,sy=j;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(str[i][j]<'0'||str[i][j]>'9') continue;
			if(d[i][j]<=d[sx][sy]) ans+=str[i][j]-'0';
		}
	printf("%d\n",ans);
	return 0;
}
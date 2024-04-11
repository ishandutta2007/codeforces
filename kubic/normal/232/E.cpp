#include <bits/stdc++.h>
using namespace std;
#define N 505
#define M 600005
#define LIM 1000005
#define pb push_back
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
char *P1,*P2,buf[LIM];
int n,m,c,L[N][N],R[N][N];bool ans[M],vs[N][N];char a[N][N];
struct Node {int x,y,id;};vector<Node> vc[N][N];
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return res;
}
void rd1(char a[])
{
	int len=0;char c=0;while(c!='.' && c!='#') c=gc();
	while(c=='.' || c=='#') a[++len]=c,c=gc();
}
void dfs(int x,int y)
{
	if(!vs[x][y] || vs[x-1][y] || vs[x][y-1]) return;
	vs[x][y]=0;dfs(x+1,y);dfs(x,y+1);
}
int main()
{
	n=rd();m=rd();for(int i=1;i<=n;++i) rd1(a[i]);c=rd();
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) vs[i][j]=a[i][j]=='.';
	for(int i=1,x1,y1,x2,y2;i<=c;++i)
		x1=rd(),y1=rd(),x2=rd(),y2=rd(),vc[x1][y1].pb((Node) {x2,y2,i});
	for(int i=n;i;--i) for(int j=m;j;--j) if(vs[i][j])
	{
		L[j][i]=R[j][i]=j;
		for(int k=i;k<=n;++k)
		{
			if(j<m) L[j][k]=min(L[j][k],L[j+1][k]);
			if(j<m) R[j][k]=max(R[j][k],R[j+1][k]);
		}
		for(auto k:vc[i][j])
			ans[k.id]=vs[k.x][k.y] && k.y>=L[j][k.x] && k.y<=R[j][k.x];dfs(i,j);
	}else for(int k=i;k<=n;++k) L[j][k]=m+1,R[j][k]=0;
	for(int i=1;i<=c;++i) puts(ans[i]?"Yes":"No");return 0;
}
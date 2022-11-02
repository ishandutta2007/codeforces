#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
#define lowbit (x&-x)
const int maxn=2e3+5,M=34005;
//#define int long long
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x)
{
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,vis[maxn][maxn],dx[8]={0,0,1,1,1,-1,-1,-1},dy[8]={1,-1,0,1,-1,0,1,-1};
char a[maxn][maxn];
bool check(int x,int y)
{
	if(a[x][y]!='*')return false;
	if(x<=0||x>n||y<=0||y>m)return false;
	if(a[x][y-1]=='.'&&a[x-1][y]=='.'&&a[x-1][y-1]=='.')return true;
	if(a[x][y+1]=='.'&&a[x+1][y]=='.'&&a[x+1][y+1]=='.')return true;
	if(a[x][y-1]=='.'&&a[x+1][y]=='.'&&a[x+1][y-1]=='.')return true;
	if(a[x][y+1]=='.'&&a[x-1][y]=='.'&&a[x-1][y+1]=='.')return true;
	return false;
}
void dfs(int x,int y)
{
	if(x<=0||x>n||y<=0||y>m)return;
	for(int i=0;i<8;i++)
	{
		int tx=dx[i]+x,ty=dy[i]+y;
		if(check(tx,ty))a[tx][ty]='.',dfs(tx,ty);
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	  for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]== '*')
                if(check(i,j))a[i][j] = '.',dfs(i,j);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			putchar(a[i][j]);puts("");
	}
 	return 0;
}
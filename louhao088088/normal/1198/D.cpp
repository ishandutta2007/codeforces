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
const int maxn=55,M=34005;
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
int n,m,f[55][55][55][55];
char a[55][55];
int dfs(int lx,int rx,int ly,int ry)
{
	if(f[lx][rx][ly][ry]!=-1)return f[lx][rx][ly][ry];
	if(lx==rx&&ly==ry){f[lx][rx][ly][ry]=(a[lx][ly]=='#');return f[lx][rx][ly][ry];}
	int res=max(rx-lx+1,ry-ly+1);
	for(int i=lx;i<rx;i++)
		res=min(res,dfs(lx,i,ly,ry)+dfs(i+1,rx,ly,ry));
	for(int i=ly;i<ry;i++)
		res=min(res,dfs(lx,rx,ly,i)+dfs(lx,rx,i+1,ry));
	return f[lx][rx][ly][ry]=res;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	memset(f,-1,sizeof f);
	cout<<dfs(1,n,1,n)<<endl;
 	return 0;
}


/*********************************************************************
    :louhao088
    : 2022-01-26 13:50
*********************************************************************/
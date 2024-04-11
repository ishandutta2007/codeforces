#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define mp make_pair
#define fi first
#define se second
#define pb push_back
const int maxn=1e5+5,M=34005;
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
int m,n,a[maxn],T,F;
void dfs(int x,int y,int num)
{
	if(F)return;
	if(x==n+1)
	{
		if(a[y]==num)F=1;return;
	}
	if(x==y)dfs(x+1,y,num);
	else dfs(x+1,y,num),dfs(x+1,y,num-a[x]),dfs(x+1,y,num+a[x]);
}
void solve()
{
	n=read();F=0;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)dfs(1,i,0);
	if(F)puts("YES");else puts("NO");
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--)solve();
 	return 0;
}
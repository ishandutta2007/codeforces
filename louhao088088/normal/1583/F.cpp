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
int n,col[1005][1005],ans=0,m;
void dfs(int l,int r,int dep)
{
	if(l==r)return;
	ans=max(ans,dep);
	if(r-l+1<m)
	{
		for(int i=l;i<=r;i++)
			for(int j=i+1;j<=r;j++)
				col[i][j]=dep;
		return;
	}
	int y=r-l;y=y/m;y++;
//	cout<<y<<" "<<l<<" "<<r<<" "<<m<<endl;
	for(int i=l;i<=r;i+=y)
	{
		dfs(i,min(i+y-1,r),dep+1);
		for(int j=i;j<=i+y-1;j++)
		{
			for(int k=i+y;k<=r;k++)
				col[j][k]=dep;
		}
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	dfs(1,n,1);
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			printf("%d ",col[i][j]);
 	return 0;
}
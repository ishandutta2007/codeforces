#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define mp make_pair
#define fi first
#define se second
#define pb push_back
const int maxn=1e5+5,M=34005,inf=1e9;
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
int n,m,a[maxn],ans;
int f[maxn][515];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=0;i<=515;i++)f[0][i]=inf;f[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=511;j++)
		{
			f[i][j]=f[i-1][j];
			if(f[i-1][j^a[i]]<=a[i])f[i][j]=min(f[i-1][j],a[i]);
		}
	}
	for(int i=0;i<=511;i++)if(f[n][i]!=inf)ans++;
	cout<<ans<<endl;
	for(int i=0;i<=511;i++)
		if(f[n][i]!=inf)cout<<i<<" ";
 	return 0;
}
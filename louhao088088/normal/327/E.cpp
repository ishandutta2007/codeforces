#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define int long long
#define lowbit(i) (i&(-i))
const int maxn=1e5+5,mod=1e9+7;
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
int n,m,f[1<<24],s[1<<24],a[25],M,ans,k,b[5];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();ans=1;M=1<<n;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();s[1<<(i-1)]=a[i];
	}
	k=read();f[0]=1;
	for(int i=1;i<=k;i++)b[i]=read();
	for(int i=1;i<M;i++)
	{
		s[i]=s[i^lowbit(i)]+s[lowbit(i)];
		if(s[i]==b[1]||s[i]==b[2])continue;
		for(int j=i;j;j-=lowbit(j))
		{
			f[i]+=f[i^lowbit(j)];if(f[i]>=mod)f[i]-=mod;
		}
	}
	cout<<f[M-1];
 	return 0;
}
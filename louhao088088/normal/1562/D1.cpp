#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
const int maxn=3e5+5;
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
int n,m,b,T,sum[maxn],sum2[maxn];
char a[maxn];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--)
	{
		n=read(),m=read();
		scanf("%s",a+1);int g=-1;
		for(int i=1;i<=n;i++)
		{
			g*=-1;
			if(a[i]=='+')
				sum[i]=sum[i-1]+g,sum2[i]=sum2[i-1]-g;
			else
				sum[i]=sum[i-1]-g,sum2[i]=sum2[i-1]+g;
		}
		for(int i=1;i<=m;i++)
		{
			int l=read(),r=read();
			if((r-l+1)%2==1)puts("1");
			else if(l%2==1)
			{
				if(sum[r]-sum[l-1]==0)puts("0");
				else puts("2");
			}
			else
			{
				if(sum2[r]-sum2[l-1]==0)puts("0");
				else puts("2");
			}
		}
	}
 	return 0;
}
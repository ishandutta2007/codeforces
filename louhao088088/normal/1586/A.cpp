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
int n,m,T,sum,a[maxn];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();sum=0;//f[0]=0;memset(f,0z80,sizeof f);
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			sum+=a[i];
		}
		int F=0;
		for(int i=2;i<=sqrt(sum);i++)
		{
			if(sum%i==0)F=1;
		}
		if(F==1)
		{
			printf("%d\n",n);
			for(int i=1;i<=n;i++)printf("%d ",i);puts("");
		}
		else
		{
			cout<<n-1<<endl;
			for(int i=1;i<=n;i++)
			{
				int F=0;int x=sum-a[i];
				for(int j=2;j<=sqrt(x);j++)
					if(x%j==0)F=1;
				if(F==1)
				{
					for(int j=1;j<=n;j++)
						if(j!=i)printf("%d ",j);puts("");
					break;
				}
			}
		}
		
			
	}
 	return 0;
}
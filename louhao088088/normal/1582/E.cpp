#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define int long long 
const int maxn=1e5+5,M=455;
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
int n,T,a[maxn],f[maxn][455],x,sum[maxn],ans;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();sum[i]=sum[i-1]+a[i];
		}
		int t=sqrt(2*n);t++;
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=t;j++)
				f[i][j]=-1e18;
		f[n+1][0]=1e18;
		for(int i=n;i>0;i--)
		{
			for(int j=0;j<=t;j++)f[i][j]=f[i+1][j];
			for(int j=1;j<=t;j++)
			{
				//int l=j,r=i+j-1;
				if(i+j<=n+1)
				{
					if(sum[i+j-1]-sum[i-1]<f[i+j][j-1])
						f[i][j]=max(f[i][j],sum[i+j-1]-sum[i-1]);
				}
			}
				
					
		}
		for(int j=t;j>=0;j--)if(f[1][j]!=-1e18){cout<<j<<endl;break;}
	}
 	return 0;
}
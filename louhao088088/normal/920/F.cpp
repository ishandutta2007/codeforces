#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define mp make_pair
#define fi first
#define se second
#define pb push_back
const int maxn=1e6+5,M=34005;
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
int n,m,b[maxn],a[maxn],L[maxn],R[maxn],x,y,id[maxn],f[maxn],sum[maxn],op;
long long ans;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<=1000000;++i)
	{
		for(int j=i;j<=1000000;j+=i)
			b[j]++;
	}
	int t=sqrt(n);//cout<<t<<endl;
	for(int i=1;i<=n;i++)
	{
		id[i]=(i-1)/t+1;//cout<<id[i]<<endl;
		if(a[i]==1||a[i]==2)f[id[i]]++;sum[id[i]]+=a[i];
	}
	for(int i=1;i<=id[n];i++)L[i]=R[i-1]+1,R[i]=min(n,L[i]+t-1);
	for(int i=1;i<=m;i++)
	{
		op=read();x=read(),y=read();
		if(op==1)
		{
			if(id[x]==id[y])
			{
				for(int j=x;j<=y;j++)
				{
					if(a[j]!=1&&a[j]!=2)
					{sum[id[j]]-=a[j];
						a[j]=b[a[j]];sum[id[j]]+=a[j];
						if(a[j]==1||a[j]==2)f[id[j]]++;
					}
				}
			}
			else
			{
				for(int j=x;j<=R[id[x]];j++)
				{
					if(a[j]!=1&&a[j]!=2)
					{
						sum[id[j]]-=a[j];
						a[j]=b[a[j]];sum[id[j]]+=a[j];
						if(a[j]==1||a[j]==2)f[id[j]]++;
					}
				}
				for(int j=L[id[y]];j<=y;j++)
				{
					if(a[j]!=1&&a[j]!=2)
					{
						sum[id[j]]-=a[j];
						a[j]=b[a[j]];sum[id[j]]+=a[j];
						if(a[j]==1||a[j]==2)f[id[j]]++;
					}
				}
				for(int j=id[x]+1;j<id[y];j++)
				{
					if(f[j]!=R[j]-L[j]+1)
					{
						for(int k=L[j];k<=R[j];k++)
						{
							if(a[k]!=1&&a[k]!=2)
							{
								
								sum[id[k]]-=a[k];
								a[k]=b[a[k]];sum[id[k]]+=a[k];
								if(a[k]==1||a[k]==2)f[id[k]]++;
							}
						}
					}
				}
			}
		}
		else
		{
			ans=0;
			if(id[x]==id[y])
			{
				for(int j=x;j<=y;j++)
				{
					ans+=a[j];
				}
			}
			else
			{
			//	cout<<id[x]<<" "<<id[y]<<endl;
				for(int j=x;j<=R[id[x]];j++)
					ans+=a[j];//cout<<ans<<endl;
				for(int j=L[id[y]];j<=y;j++)
					ans+=a[j];
				
				for(int j=id[x]+1;j<id[y];j++)
				{
					ans+=sum[j];
					//cout<<ans<<endl;
				}
			}printf("%lld\n",ans);
		}	
	}
		
 	return 0;
}
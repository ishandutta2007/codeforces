#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define mp make_pair
#define fi first
#define se second
#define pb push_back
const int maxn=2e5+5,M=34005;
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
int T,a[maxn],sum[35],ans,tot,n,st[maxn];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();int F=0;ans=0;
		memset(sum,0,sizeof sum);
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(a[i]!=0)F=1;
			for(int j=0;j<=30;j++)
				if(a[i]&(1<<j))
					sum[j]++;
		}
		if(!F)
		{
			for(int i=1;i<=n;i++)
				printf("%d ",i);puts("");continue;
		}
		for(int i=0;i<=30;i++)
		{
			if(ans==0)ans=sum[i];
			else if(sum[i]!=0)ans=__gcd(sum[i],ans);
		}tot=0;
		//cout<<endl;
		for(int i=1;i<=sqrt(ans);i++)
		{
			if(ans%i==0)
			{
				st[++tot]=i;
				if(ans/i!=i)st[++tot]=ans/i;
			}
		}
		sort(st+1,st+tot+1);
		for(int i=1;i<=tot;i++)
			printf("%d ",st[i]);puts("");
	}
 	return 0;
}
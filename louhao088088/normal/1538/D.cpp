#include<bits/stdc++.h>
using namespace std;
const int maxn=100007;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int n,m,T,k,s,p[maxn],g[maxn],cnt=0;
signed main()
{
	T=read();
	for(int i=2;i<=100000;i++)
	{
		if(!g[i])p[++cnt]=i;	
		for(int j=1;j<=cnt&&p[j]*i<=100000;j++)
			g[i*p[j]]=g[i]+1;
	}
	while(T--)
	{
		n=read(),m=read();k=read();s=0;
		if(k==0)
		{
			if(n==m)puts("YES");
			else puts("NO");continue;
		}
		else if(k==1)
		{
			if((n%m==0||m%n==0)&&n!=m)puts("YES");
			else puts("NO");continue;
		}
		else
		{
			for(int i=1;i<=cnt;i++)
			{
				while(n%p[i]==0)n=n/p[i],s++;
				while(m%p[i]==0)m=m/p[i],s++;
			}
			if(n>1)s++;if(m>1)s++;
			if(s>=k)puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
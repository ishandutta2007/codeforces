#include <cmath>
#include <queue>
#include <bitset>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define S 110
#define MAXS 10010
#define MAXN 1000000
#define N 2000010
#define ll long long
using namespace std;
inline int read() 
{ 
    int x=0,f=1;char ch=getchar(); 
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();} 
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();} 
    return x*f; 
}
int T;
int n;
bool g[N];
int a[S],b[S],top;
int c[MAXS],topc;
int main()
{
	T=read();
	while(T--)
	{
		memset(g,0,sizeof(g));
		top=0,topc=0;
		n=read();
		for(int i=1;i<=n;i++)
		a[i]=read();
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		c[++topc]=a[j]-a[i];
		bool pd=1;
		for(int i=1;i<=MAXN;i++)
		{
			if(!g[i])
			{
				b[++top]=i;
				for(int j=1;j<=topc;j++)
				{
					if(i+c[j]>MAXN)break ;
					g[i+c[j]]=1;
				}
				if(top==n)
				{
					puts("YES");
					for(int j=1;j<=top;j++)
					printf("%d ",b[j]);
					pd=0;
					break ;
				}
			}
		}
		if(pd==1)
		puts("NO");
	}
}
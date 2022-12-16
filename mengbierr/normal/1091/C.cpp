#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
ll ans[1000005],tot;
int main()
{
	int n=read();
	int x=sqrt(n);
	for(int i=1;i<=x;i++)
	{
		if(n%i==0)
		{
			if(i*i!=n)
			{
				ans[++tot]=1LL*(2+(n/i-1)*i)*(n/i)/2;
			}
			ans[++tot]=1LL*(2+(i-1)*(n/i))*i/2;
		}
	}
	sort(ans+1,ans+tot+1);
	for(int i=1;i<=tot;i++)
	{
		printf("%lld ",ans[i]);
	}
}
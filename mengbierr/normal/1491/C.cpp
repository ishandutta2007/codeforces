#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
int num[5005],a[5005];
int main()
{
	int t=read();
	while(t--)
	{
		int n=read();ll ans=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();num[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			ans+=max(0,a[i]-num[i]-1);
			for(int j=2;j<=a[i];j++)
			{
				if(i+j>n) break;
				num[i+j]++;
			}
			if(num[i]>=a[i]-1)
			{
				num[i+1]+=num[i]-a[i]+1;
			}
		}
		cout<<ans<<endl;
	}
}
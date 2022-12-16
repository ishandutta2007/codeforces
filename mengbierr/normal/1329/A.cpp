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
int a[100005],ans[100005];
int main()
{
	int m=read(),n=read();ll sum=0;
	for(int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
	if(sum<m)
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int pla=max(1LL*i,m-sum+1);
		if(pla+a[i]-1>m)
		{
			//cout<<i<<" "<<pla<<endl;
			puts("-1");
			return 0;
		}
		sum-=a[i];
		ans[i]=pla;
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}
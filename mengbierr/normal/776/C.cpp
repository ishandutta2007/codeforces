#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
map<long long,int> mp;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
long long now=1,a[100005],s[100005];
int main()
{
	int n=read();long long k=read();
	for(int i=1;i<=n;i++)
	a[i]=read();
	for(int i=1;i<=n;i++)
	s[i]=s[i-1]+a[i];
	long long sum=0,ans=0;
	while(now<=1000000000000000LL&&now>=-1000000000000000LL)
	{
		mp.clear();
		mp[0]++;
		sum=0;
		for(int i=1;i<=n;i++)
		{
			sum+=a[i];
			ans+=mp[sum-now];
			mp[sum]++;
		}
		now*=k;
		if(now==1) break;
	}
	cout<<ans;
}
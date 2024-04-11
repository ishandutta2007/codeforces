#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f;
}
long long a[105];long long sum,ans2,nxt;
int main()
{
	int n;long long k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	a[i]=read(),sum+=a[i];
	sum+=k;
	long long m=sqrt(sum)+1;
	for(long long i=1;i<=sum;i=nxt)
	{
		long long d=sum/(sum/(long long)i),ans=0;
		//cout<<d<<" ";
		nxt=d+1;
		for(int j=1;j<=n;j++)
		{
			ans+=(long long)a[j]/d;
			if(a[j]%d) ans++;
		}
		if(ans<=sum/d)
		{
			ans2=max(ans2,d);
			//printf("%lld",d);
			//return 0;
		}
	}
	cout<<ans2;
}
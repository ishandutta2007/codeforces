#include<iostream>
#include<algorithm>
#include<cstdio>
#include<set>
using namespace std;
int n;
long long b[150000],a[150000];
set<long long>s;
int c;
main()
{
	scanf("%d",&n);
	long long M=-1;int id;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&b[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(M==-1||M<=b[i]&&b[(i+n-1)%n]<b[i])M=b[i],id=i;
		s.insert(b[i]);
		c+=!!b[i];
	}
	if(s.size()==1)
	{
		if(M==0)
		{
			printf("YES\n");
			for(int i=0;i<n;i++)
			{
				printf("1%c",i==n-1?'\n':' ');
			}
		}
		else printf("NO\n");
		return 0;
	}
	a[id]=b[id];
	if(b[(id+n-1)%n]==0)a[(id+n-1)%n]=a[id]*2;
	else a[(id+n-1)%n]=a[id]+b[(id+n-1)%n];
	int pre=(id+n-1)%n;
	for(int i=1;++i<n;)
	{
		int now=(id-i+n)%n;
		a[now]=a[pre]+b[now];
		pre=now;
	}
	printf("YES\n");
	for(int i=0;i<n;i++)
	{
		printf("%lld%c",a[i],i==n-1?'\n':' ');
	}
}
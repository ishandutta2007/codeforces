#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,a[5];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n==0)
	{
		puts("YES");
		puts("1");
		puts("1");
		puts("3");
		puts("3");
		return 0;
	}
	if(n==1)
	{
		puts("YES");
		printf("%d\n",a[1]);
		printf("%d\n",a[1]*3);
		printf("%d\n",a[1]*3);
		return 0;
	}
	if(n==2)
	{
		sort(a+1,a+3);
		a[4]=3*a[1];
		if(a[4]>=a[2])
		{
			a[3]=a[1]+a[4]-a[2];
			puts("YES");
			for(int i=3;i<=4;i++) printf("%d\n",a[i]);
			return 0;
		}
		puts("NO");
		return 0;
	}
	if(n==3)
	{
		sort(a+1,a+4);
		if((a[2]+a[3])%2==0)
		{
			a[4]=a[2]+a[3]-a[1];
			if(a[4]-a[1]==(a[2]+a[3])/2&&a[4]>=a[3])
			{
				puts("YES");
				printf("%d\n",a[4]);
				return 0;
			}
		}
		if((a[1]+a[2])%2==0)
		{
			a[4]=a[1]+a[2]-a[3];
			if(a[3]-a[4]==(a[1]+a[2])/2&&a[4]<=a[1])
			{
				puts("YES");
				printf("%d\n",a[4]);
				return 0;
			}
		}
		if((a[1]+a[3])%2==0)
		{
			a[4]=a[1]+a[3]-a[2];
			if(a[4]>=a[1]&&a[4]<=a[3]&&a[3]-a[1]==(a[1]+a[3])/2)
			{
				puts("YES");
				printf("%d\n",a[4]);
				return 0;
			}
		}
		puts("NO");
		return 0;
	}
	if(n==4)
	{
		sort(a+1,a+5);
		if((a[2]+a[3])&1) {puts("NO");return 0;}
		if((a[1]+a[2]+a[3]+a[4])&3) {puts("NO");return 0;}
		if(((a[1]+a[2]+a[3]+a[4])>>2)==((a[2]+a[3])>>1)&&((a[2]+a[3])>>1)==(a[4]-a[1])) puts("YES");
		else puts("NO");
	}
	return 0;
}
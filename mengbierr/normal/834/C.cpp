#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int prime[30002],tot=0,a,b;bool check[35002];
int main()
{int n;
cin>>n;
	for(int i=2;i<=35000;i++)
	{if(!check[i])
	prime[tot++]=i;
	for(int j=0;j<tot;j++)
		{if(i*prime[j]>35000)
		break;
		check[i*prime[j]]=1;
		if(i%prime[j]==0)
		break;
		}
	}
	//cout<<prime[167];
	while(n--)
	{
		bool ac=1;
		scanf("%d%d",&a,&b);
		for(int i=0;i<=170;i++)
		{
			int suma=0,sumb=0;
			while(a%prime[i]==0)
			{
				suma++;
				a/=prime[i];
			}
			while(b%prime[i]==0)
			{
				sumb++;
				b/=prime[i];
			}
			if((sumb<<1)-suma<0||(suma<<1)-sumb<0||((sumb<<1)-suma)%3!=0||((suma<<1)-sumb)%3!=0)
			{
				ac=0;
				break;
			}
		}
		if(ac&&(a!=1||b!=1))
		{
			if(a>35000&&b>35000)
			ac=0;
			else if(a<=35000)
			{
				if(b!=a*a)
				ac=0;
			}
			else if(b<=35000)
			{
				if(a!=b*b)
				ac=0;
			}
		}
		if(!ac)
		puts("No");
		else puts("Yes");
	}
}
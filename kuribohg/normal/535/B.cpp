#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,ans,d[100010],tot,pow[100010];
int main()
{
	scanf("%d",&n);
	while(n)
	{
		d[++tot]=n%10;
		n/=10;
	}
	pow[0]=1;
	for(int i=1;i<=20;i++) pow[i]=pow[i-1]*2;
	for(int i=tot;i>=1;i--)
	{
		if(d[i]==7) ans+=pow[i-1];
		ans+=pow[i-1];
	}
	printf("%d\n",ans);
	return 0;
}
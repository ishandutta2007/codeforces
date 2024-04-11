#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
int a[111111],n,cnt,ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int p=abs(a[1]);
	for (int i=2;i<=n;i++)
	{
		p=gcd(p,abs(a[i]));
	}
	if (p>1)
	{
		printf("YES\n0\n");
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		if (a[i]%2) cnt++;
		else
		{
			if (cnt%2) ans=ans+cnt/2+2;
			else ans=ans+cnt/2;
			cnt=0;
		}
	}
	if (cnt%2) ans=ans+cnt/2+2;
	else ans=ans+cnt/2;
	printf("YES\n%d\n",ans);
	return 0;
}
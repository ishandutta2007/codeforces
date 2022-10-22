#include<bits/stdc++.h>
using namespace std;
int n,d,e;
int main()
{
	scanf("%d%d%d",&n,&d,&e);
	e*=5;
	int g=__gcd(d,e);
	int lcm=d*e/g;
	int ans=n;
	for(int i=0;i<lcm/d;i++)
	{
		for(int j=0;j<=lcm/e;j++)
		{
			if(n<i*d+j*e) continue;
			int sum=n-i*d-j*e;
			sum%=lcm;
			ans=min(ans,sum);
		}
	}
	printf("%d\n",ans);
	return 0;
}
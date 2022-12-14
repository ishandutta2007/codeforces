#include<bits/stdc++.h>
using namespace std;
char opt[11];
int n,h;
long double ans,pw,cr,iv;
int main()
{
	scanf("%s",opt);
	scanf("%d%d",&n,&h);
	if (opt[0]=='B')
	{
		printf("%d\n",n);
		return 0;
	}
	ans=(long double)n;pw=1.00;
	for (int i=1;i<=h;i++)
	{
		pw*=2.00;cr=1.00;iv=1.00/pw;
		for (int j=1;j<n;j++)
		{
			ans=(ans+(long double)(n-j)*cr*iv*iv*(pw-pw/2.00*(1.00+(long double)(j-1)/(pw-1.00))));
			cr*=(1.00-iv);
		}
	}
	printf("%.9Lf\n",ans);
	return 0;
}
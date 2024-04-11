#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int d,mod;
		scanf("%d%d",&d,&mod);
		long long ans=1;
		for (int i=0;(1<<i)<=d;i++)
		ans=(ans*(min(d+1,(1<<(i+1)))-(1<<i)+1))%mod;
		printf("%I64d\n",(ans-1+mod)%mod);
	}
}
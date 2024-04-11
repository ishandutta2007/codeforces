#include<iostream>
#include<cstdio>
using namespace std;
long long del[66],q,tp,x,k,ind,pw[66],pos;
long long Log(long long x)
{
	for (long long i=1;i<=61;i++)
	{
		if (pw[i]>x) return i-1;
	}
}
int main()
{
	scanf("%I64d",&q);
	pw[0]=1;
	for (long long i=1;i<=61;i++) pw[i]=pw[i-1]*2;
	while(q--)
	{
		scanf("%I64d",&tp);
		if (tp==1)
		{
			scanf("%I64d%I64d",&x,&k);
			ind=Log(x);
			del[ind]=(del[ind]+k)%pw[ind];
		}
		else if (tp==2)
		{
			scanf("%I64d%I64d",&x,&k);
			ind=Log(x);
			k%=pw[ind];
			for (long long i=ind;i<=60;i++)
			{
				del[i]=(del[i]+k)%pw[i];
				k*=2;
			}
		}
		else
		{
			scanf("%I64d",&x);
			ind=Log(x);
			pos=(x+del[ind])%pw[ind]+pw[ind];
			for (long long i=ind;i>=1;i--)
			{
				printf("%I64d ",x);
				pos/=2;
				x=(pos-del[i-1])%pw[i-1]+pw[i-1];
			}
			printf("1\n");
		}
	}
	return 0;
}
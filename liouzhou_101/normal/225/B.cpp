#include<cstdio>
#include<iostream>

using namespace std;

int s,k,n;

long long F[110];

int top,Q[1010];

int main()
{
	cin>>s>>k;
	F[0]=F[1]=1;
	for (int i=2;i<=100;++i)
	{
		for (int j=max(i-k,0);j<i;++j)
			F[i]+=F[j];
		if (F[i]>1e9)
		{
			n=i-1;
			break;
		}
	}
	for (int i=n;i>=1;--i)
		if (F[i]==s)
		{
			printf("2\n0 %d\n",s);
			return 0;
		}
	for (int i=n;i>=1;--i)
	{
		if (F[i]<=s)
		{
			Q[++top]=F[i];
			s-=F[i];
			if (!s) break;
		}
	}
	printf("%d\n%d",top,Q[1]);
	for (int i=2;i<=top;++i)
		printf(" %d",Q[i]);
	puts("");
	return 0;
}
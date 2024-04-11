#include<bits/stdc++.h>
using namespace std;
int a[22],pos,mn;
long long k,prod;
string s;
int main()
{
	scanf("%lld",&k);
	for (int i=1;i<=10;i++) a[i]=1;
	prod=1;
	while(prod<k)
	{
		mn=1e9;
		for (int i=1;i<=10;i++)
		{
			if (a[i]<mn)
			{
				mn=a[i];
				pos=i;
			}
		}
		prod/=a[pos];
		a[pos]++;
		prod*=a[pos];
	}
	s="codeforces";
	for (int i=1;i<=10;i++)
	{
		for (int j=1;j<=a[i];j++)
		{
			putchar(s[i-1]);
		}
	}
	printf("\n");
	return 0;
}
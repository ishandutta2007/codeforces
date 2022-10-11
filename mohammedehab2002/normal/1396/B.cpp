#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n,sum=0,mx=0;
		scanf("%d",&n);
		while (n--)
		{
			int a;
			scanf("%d",&a);
			sum+=a;
			mx=max(mx,a);
		}
		if (sum%2==0 && 2*mx<=sum)
		puts("HL");
		else
		puts("T");
	}
}
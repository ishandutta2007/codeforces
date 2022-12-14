#include<bits/stdc++.h>
using namespace std;
int t;
long long n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if (n<=14)
		{
			printf("NO\n");
			continue;
		} 
		if (n%14>=1 && n%14<=6) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
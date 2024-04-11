#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=200000;
int n,m;
int a[maxn+5];
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	int cost=m;
	for(int i=1;i<=n;i++)
	{
		int paper=0;
		if(a[i]<cost) 
		{
			cost-=a[i];
			printf("0 ");
		}
		else
		{
			a[i]-=cost;
			paper++;
			paper+=a[i]/m;
			a[i]%=m;
			cost=m-a[i];
			printf("%lld ",paper);
		}
	}
	printf("\n");
	

	return 0;
}
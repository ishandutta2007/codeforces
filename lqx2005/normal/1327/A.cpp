#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
int t;
LL n,k;
int main()
{
	scanf("%d",&t);
	for(int am=1;am<=t;am++)
	{
		scanf("%lld%lld",&n,&k);
		if(n<k*k) printf("NO\n");
		else if(n%2!=k%2) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
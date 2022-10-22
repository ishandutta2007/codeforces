#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,q;
signed main()
{
	scanf("%lld%lld",&n,&q);
	int x,y;
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld",&x,&y);
		if((x+y)%2==0) printf("%lld\n",((x-1)*n+y+1)/2);
		else  printf("%lld\n",((n*n+1)/2)+((x-1)*n+y+1)/2);
	}
	return 0;
}
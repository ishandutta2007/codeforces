#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll t,s,i,e;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&s,&i,&e);
		ll l=s,r;
		if(s+e<=i) 
		{
			printf("0\n");
			continue;
		}
		if((s+e+i)%2==0) l=max(l,(s+e+i)/2+1);
		else l=max(l,(s+e+i)/2+1);
		r=s+e;
		printf("%lld\n",r-l+1);
	}
	return 0;
}
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll M=30;
ll t,a,b,n;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&a,&b,&n);
		n%=3;
		if(n==0) printf("%lld\n",(a));
		if(n==1) printf("%lld\n",(b));
		if(n==2) printf("%lld\n",(a^b));
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long n,p;
signed main()
{
	for(scanf("%lld",&n),p=1;!(n%p);p*=3);
	return printf("%lld\n",n/p+1),0;
}
#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
long long n,k,x;
int main()
{
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&x);
		printf("%lld\n",9ll*(k-1)+x);
	}
	return Accepted;
}
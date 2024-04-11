#include<bits/stdc++.h>
using namespace std;
int n;long long a[105],sum=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	for(int i=1;i<=n;i++) sum+=(a[i]-1)*i+1;
	return printf("%lld\n",sum),0;
}
#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
long long n,k,num,x[111111];
int m,pre,pos,ans;
int main()
{
	scanf("%lld%d%lld",&n,&m,&k);
	for (int i=1;i<=m;i++)
	{
		scanf("%lld",&x[i]);
	}
	pos=1;
	while(pos<=m)
	{
		pre=pos;num=x[pos]-(pos-1);
		num=(num+k-1)/k*k;
		while(pos<=m && x[pos]-(pre-1)<=num) pos++;
		ans++;
	}
	printf("%d\n",ans);
	return Accepted;
}
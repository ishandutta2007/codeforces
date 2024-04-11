#include<bits/stdc++.h>
using namespace std;

const int maxn=5010;
typedef long long ll;
int a[maxn];
int n,k;
ll p;
set<ll> S;
int main()
{
	scanf("%lld%d",&p,&k);
	n=0;
	while (p>=k || p<0)
	{
		if (S.count(p))
		{
			printf("-1\n");
			return 0;
		}
		S.insert(p);
		ll q=(p%k+k)%k;
		a[++n]=q;
		p=(q-p)/k;
	}
	if (p)	a[++n]=p;
	printf("%d\n",n);
	for (int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}
#include<bits/stdc++.h>
#define int long long
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=100000+5;
int a[MaxN],Rec[MaxN];
signed main()
{
	register int T;
	scanf("%lld",&T);
	register int n;
	while(T--)
	{
		register int Sum=0;
		scanf("%lld",&n);
		rep(i,1,n)
			scanf("%lld",&a[i]),Rec[i]=0;
		rep(i,1,n)
		{
			if(a[i]-Rec[i]>=2)
				Sum+=(a[i]-Rec[i]-1),Rec[i]=(a[i]-1);
			dow(j,min(i+a[i],n),max(i+a[i]-Rec[i],i)+1)
				++Rec[j];
			Rec[i+1]+=max(0LL,Rec[i]-a[i]);
		}
		printf("%lld\n",Sum);
	}
	return 0;
}
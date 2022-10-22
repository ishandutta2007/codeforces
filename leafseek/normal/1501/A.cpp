#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=100000+5;
int a[MaxN],b[MaxN],t[MaxN];
int main()
{
	register int T;
	scanf("%d",&T);
	register int n;
	while(T--)
	{
		scanf("%d",&n);
		rep(i,1,n)
			scanf("%d%d",&a[i],&b[i]);
		rep(i,1,n)
			scanf("%d",&t[i]);
		register int cur=0;
		rep(i,1,n)
		{
			cur=(cur+(a[i]-b[i-1]+t[i]));
			if(i!=n)
				cur=max(cur+((b[i]-a[i]+1)>>1),b[i]);
		}
		printf("%d\n",cur);
	}
	return 0;
}
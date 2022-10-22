#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=100000+5;
int a[MaxN],cnt[MaxN];
int main()
{
	register int T;
	scanf("%d",&T);
	while(T--)
	{
		register int n,m;
		scanf("%d%d",&n,&m);
		rep(i,0,m)
			cnt[i]=0;
		rep(i,1,n)
			scanf("%d",&a[i]),++cnt[a[i]%m];
		register int Sum=0;
		rep(i,0,(m>>1))
		{
			if(cnt[i]==0&&cnt[m-i]==0)
				continue;
			if(i==0||i+i==m)
				++Sum;
			else
				Sum+=max(1,max(cnt[i],cnt[m-i])-min(cnt[i],cnt[m-i]));
		}
		printf("%d\n",Sum);
	}
	return 0;
}
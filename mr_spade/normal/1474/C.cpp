#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n;
int a[N];
multiset<int> S;
inline bool run(int x,bool t)
{
	int a,b;
	register int i;
	S.clear();
	for(i=1;i<=n;i++)
		S.insert(::a[i]);
	while(!S.empty())
	{
		a=*S.rbegin();S.erase(S.find(a));
		if(S.find(x-a)==S.end())
			return 0;
		S.erase(S.find(x-a));
		if(t)
			printf("%d %d\n",a,x-a);
		x=a;
	}
	return 1;
}
inline void solve()
{
	register int i;
	scanf("%d",&n);n*=2;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<=n-1;i++)
		if(run(a[i]+a[n],0))
			return printf("YES\n%d\n",a[i]+a[n]),run(a[i]+a[n],1),void();
	puts("NO");
	return;
}
signed main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
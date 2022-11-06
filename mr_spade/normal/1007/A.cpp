#pragma GCC optimize(2)
#include<cstdio>
#include<algorithm>
#include<set>
using std::sort;
using std::multiset;
const int N=1e5+5;
int n,ans;
int a[N];
multiset<int> S;
inline bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		S.insert(a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++)
		if(S.upper_bound(a[i])!=S.end())
		{
			ans++;
			S.erase(S.find(*S.upper_bound(a[i])));
		}
		else
			S.erase(S.begin());
	printf("%d\n",ans);
	return 0;
}
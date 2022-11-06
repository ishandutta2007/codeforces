#include<cstdio>
#include<algorithm>
#include<set>
using std::sort;
using std::set;
const int N=1e5+5;
int n,best,cest,Max;
int a[N],p[N];
int tot,sum;
int cnt[N];
set<int> S;
inline bool cmp(int x,int y)
{
	return a[x]>a[y];
}
inline void add(int x)
{
	sum++;
	if(!cnt[x]++)
		tot++;
	return;
}
inline void sub(int x)
{
	sum--;
	if(!--cnt[x])
		tot--;
	return;
}
signed main()
{
	int pre,suc;
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>Max)
			Max=a[i];
	}
	for(i=1;i<=n;i++)
		p[i]=i;
	sort(p+1,p+n+1,cmp);
	S.insert(0);S.insert(n+1);
	add(n);best=Max+1;cest=-1;
	for(i=1;i<=n;i++)
	{
		pre=*(--S.lower_bound(p[i]));
		suc=*S.upper_bound(p[i]);
		sub(suc-pre-1);
		if(p[i]-pre-1)
			add(p[i]-pre-1);
		if(suc-p[i]-1)
			add(suc-p[i]-1);
		S.insert(p[i]);
		if(tot==1&&sum>=cest)
			best=a[p[i+1]]+1,cest=sum;
	}
	printf("%d\n",best);
	return 0;
}
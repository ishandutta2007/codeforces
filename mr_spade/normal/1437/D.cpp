#include<cstdio>
#include<vector>
using std::vector;
const int N=2e5+5;
int n;
int a[N],lst[N];
vector<int> V[N];
inline void solve()
{
	int ci=-1,cj=0;
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	V[0].push_back(1);
	for(i=2;i<=n;i++)
	{
		if(ci<0)
			ci=0;
		if(a[i]>lst[V[ci][cj]])
			lst[V[ci][cj]]=a[i],V[ci+1].push_back(a[i]);
		else if(cj+1<(int)V[ci].size())
			cj++,lst[V[ci][cj]]=a[i],V[ci+1].push_back(a[i]);
		else
			ci++,cj=0,lst[V[ci][cj]]=a[i],V[ci+1].push_back(a[i]);
	}
	printf("%d\n",ci+1);
	for(i=0;i<=n;i++)
		lst[i]=0,V[i].clear();
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
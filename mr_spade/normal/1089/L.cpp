#pragma GCC optimize("Ofast","inline")
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using std::sort;
using std::vector;
const int N=1e5+5;
int n,k,kk;
int a[N],b[N];
vector<int> v[N],V;
signed main()
{
	register int i,j;
	scanf("%lld%lld",&n,&k);kk=k;
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	for(i=1;i<=n;i++)
		v[a[i]].push_back(b[i]);
	for(i=1;i<=k;i++)
	{
		sort(v[i].begin(),v[i].end());
		if(!v[i].empty())
			v[i].pop_back(),kk--;
		for(j=0;j<(int)v[i].size();j++)
			V.push_back(v[i][j]);
	}
	sort(V.begin(),V.end());
	int ans=0;
	for(i=0;i<kk;i++)
		ans+=V[i];
	printf("%lld\n",ans);
	return 0;
}
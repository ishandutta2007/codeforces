#include<cstdio>
#include<cstring>
#include<unordered_set>
using std::unordered_set;
const int N=3e5+5;
int n;
int a[N],ans[N];
unordered_set<int> pos[N];
inline void solve()
{
	int fl=1,l,r;
	register int i;
	scanf("%d",&n);l=1;r=n;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]),pos[a[i]].insert(i);
	for(i=1;i<=n;i++)
		fl&=(!pos[i].empty());
	memset(ans+1,0,sizeof(int)*n);
	if(fl)
		ans[1]=1;
	for(i=1;i<=n;i++)
		if(pos[i].size()==1&&(pos[i].find(l)!=pos[i].end()||pos[i].find(r)!=pos[i].end()))
		{
			if(pos[i].find(l)!=pos[i].end())
				l++;
			else
				r--;
			ans[n-i+1]=1;
		}
		else
		{
			if(!pos[i].empty())
				ans[n-i+1]=1;
			break;
		}
	for(i=1;i<=n;i++)
		printf("%d",ans[i]);
	putchar('\n');
	for(i=1;i<=n;i++)
		pos[i].clear();
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
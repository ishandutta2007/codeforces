#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
#include<set>
#include<queue>
#define int long long
using std::sort;
using std::greater;
using std::vector;
using std::set;
using std::queue;
using std::priority_queue;
const int N=1e5+5;
int n,k,idx;
int t[N],ans[N];
int p[N];
queue<int> wt,slp;
priority_queue<int,vector<int>,greater<int>> obs;
set<int> wS;
signed main()
{
	register int i;
	scanf("%lld%lld",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%lld",&t[i]),p[i]=i;
	sort(p+1,p+n+1,[](int x,int y)->bool
	{
		if(t[x]!=t[y])
			return t[x]<t[y];
		return x<y;
	});
	wS.insert(n+1);
	for(i=1;i<=n;i++)
		slp.push(p[i]);
	while(!wt.empty()||!obs.empty()||!slp.empty())
	{
		if(wt.empty())
			idx=t[slp.front()],wt.push(slp.front()),wS.insert(slp.front()),slp.pop();
		while(!slp.empty()&&idx+k>=t[slp.front()])
		{
			obs.push(slp.front());slp.pop();
			while(!obs.empty()&&*wS.begin()>obs.top())
				wt.push(obs.top()),wS.insert(obs.top()),obs.pop();
		}
		idx=ans[wt.front()]=idx+k;wS.erase(wt.front());wt.pop();
		while(!obs.empty()&&*wS.begin()>obs.top())
			wt.push(obs.top()),wS.insert(obs.top()),obs.pop();
	}
	for(i=1;i<=n;i++)
		printf("%lld ",ans[i]);
	putchar('\n');
	return 0;
}
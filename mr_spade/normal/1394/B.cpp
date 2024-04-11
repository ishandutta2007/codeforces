#include<bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;
const int N=2e5+5;
int n,m,k,ans;
ull cc;
vector<pair<int,int> > e[N];
ull val[N];
ull epc[10][10];
void dfs(int t,ull c)
{
	if(t==k+1)
	{
		ans+=(c==cc);
		return;
	}
	for(int i=1;i<=t;i++)
		dfs(t+1,c+epc[t][i]);
}
signed main()
{
	int x,y,w;
	srand(time(0));
	register int i,j;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)
		val[i]=(ull)rand()<<49|(ull)rand()<<34|(ull)rand()<<19|(ull)rand()<<4|(ull)rand()>>11,cc+=val[i];
	for(i=1;i<=m;i++)
		scanf("%d%d%d",&x,&y,&w),e[x].push_back(make_pair(w,y));
	for(i=1;i<=n;i++)
	{
		sort(e[i].begin(),e[i].end());
		for(j=0;j<(int)e[i].size();j++)
			epc[(int)e[i].size()][j+1]+=val[e[i][j].second];
	}
	dfs(1,0ull);
	printf("%d\n",ans);
	return 0;
}
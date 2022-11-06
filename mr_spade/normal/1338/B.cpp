#include<cstdio>
#include<vector>
#include<set>
using std::set;
using std::vector;
const int N=1e5+5;
int n,r,f0,f1,cnt;
int deg[N];
vector<int> e[N];
set<int> S;
void dfs(int x,int father=0,int w=0)
{
	if(deg[x]==1)
	{
		S.insert(father);cnt++;
		if(w)
			f1=1;
		else
			f0=1;
	}
	for(int y:e[x])
		if(y!=father)
			dfs(y,x,w^1);
	return;
}
signed main()
{
	int x,y;
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n-1;i++)
		scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x),deg[x]++,deg[y]++;
	for(i=1;i<=n;i++)
		if(deg[i]>1)
		{
			r=i;
			break;
		}
	dfs(r);
	printf("%d %d\n",(f0&&f1)?3:1,n-1-(cnt-(int)S.size()));
	return 0;
}
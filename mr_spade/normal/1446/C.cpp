#include<cstdio>
#include<algorithm>
using std::min;
using std::max;
const int N=1e7+5;
int n,tot;
int sum[N],ch[N][2];
int dfs(int x)
{
	if(!x)
		return 0;
	return min(max(sum[ch[x][0]]-1,0)+dfs(ch[x][1]),max(sum[ch[x][1]]-1,0)+dfs(ch[x][0]));
}
signed main()
{
	int x,p;
	register int i,j;
	scanf("%d",&n);
	tot=1;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		for(p=1,j=30;j>=0;j--)
		{
			if(!ch[p][x>>j&1])
				ch[p][x>>j&1]=++tot;
			sum[p]++;p=ch[p][x>>j&1];
		}
		sum[p]++;
	}
	printf("%d\n",dfs(1));
	return 0;
}
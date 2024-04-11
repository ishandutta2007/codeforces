#include<cstdio>
#include<algorithm>
#include<vector>
using std::max;
using std::lower_bound;
using std::sort;
using std::unique;
using std::vector;
const int N=1005;
int n,m;
int a[N][N];
vector<int> V[N],V2[N];
signed main()
{
	int _,rx,ry;
	register int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]),V[i].push_back(a[i][j]),V2[j].push_back(a[i][j]);
	for(i=1;i<=n;i++)
	{
		sort(V[i].begin(),V[i].end());
		_=unique(V[i].begin(),V[i].end())-V[i].begin();
		while((int)V[i].size()>_)
			V[i].pop_back();
	}
	for(i=1;i<=m;i++)
	{
		sort(V2[i].begin(),V2[i].end());
		_=unique(V2[i].begin(),V2[i].end())-V2[i].begin();
		while((int)V2[i].size()>_)
			V2[i].pop_back();
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			rx=lower_bound(V[i].begin(),V[i].end(),a[i][j])-V[i].begin()+1;
			ry=lower_bound(V2[j].begin(),V2[j].end(),a[i][j])-V2[j].begin()+1;
			if(rx>=ry)
				printf("%d ",max((int)V[i].size(),(int)V2[j].size()+(rx-ry)));
			else
				printf("%d ",max((int)V2[j].size(),(int)V[i].size()+(ry-rx)));
		}
		putchar('\n');
	}
	return 0;
}
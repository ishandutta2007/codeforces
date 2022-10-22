/* **********************************************
Created Time: 2020/3/25 17:28:29
File Name: SegmentTree
*********************************************** */
#include<bits/stdc++.h>
using namespace std;
#define sit set<int>::iterator 
#define Deg fprintf(stderr,"Passing [%s] line %d\n",__FUNCTION__,__LINE__)
typedef long long LL;
const int maxn=110000;
int t,n;
set<int> g[maxn];
int ua[maxn],ub[maxn];
int main()
{
	scanf("%d",&t);
	for(int am=1;am<=t;am++)
	{
		scanf("%d",&n);
		for(int i=0;i<=n;i++) g[i].clear(),ua[i]=0,ub[i]=0;
		int k,to;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k);
			for(int j=1;j<=k;j++)
			{
				scanf("%d",&to);
				g[i].insert(to);
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(sit it=g[i].begin();it!=g[i].end();it++)
			{
				if(ua[*it]) continue;
				ua[*it]=1;
				ub[i]=1;
				break;
			}
		}
		int pa=-1,pb=-1;
		for(int i=1;i<=n;i++) if(!ua[i]) pa=i;
		for(int i=1;i<=n;i++) if(!ub[i]) pb=i;
		if(pa==-1&&pb==-1) printf("OPTIMAL\n");
		else printf("IMPROVE\n%d %d\n",pb,pa);
	}
	return 0;
}
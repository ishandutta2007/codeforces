#include<bits/stdc++.h>
using namespace std;
int tot;
vector<pair<pair<int,int>,int> > E;
inline void add_edge(int x,int y,int z)
{
	E.push_back(make_pair(make_pair(x,y),z));
	return;
}
int run(int l,int r)
{
	if(l==r)
	{
		tot++;
		add_edge(1,tot,l);
		return tot;
	}
	int mid=(l+r+1)/2-1,val,t,size;
	register int i;
	if((r-l+1)&1)
		val=++tot;
	t=run(l,mid);
	tot++;size=(int)E.size();
	for(i=0;i<size;i++)
		if(E[i].first.second==t)
			add_edge(E[i].first.first,tot,E[i].second);
	add_edge(t,tot,mid+1-l);
	if((r-l+1)&1)
		add_edge(1,val,r-1),add_edge(val,tot,1);
	return tot;
}
const int N=55;
int n,t;
int p[N];
signed main()
{
	int l,r;
	register int i;
	scanf("%d%d",&l,&r);tot=1;
	puts("YES");
	t=run(l,r);
	printf("%d %d\n",tot,(int)E.size());
	for(auto e:E)
		printf("%d %d %d\n",e.first.first,e.first.second,e.second);
	return 0;
}
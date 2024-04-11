#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#include<utility>
using namespace std;
const int MAXN=1000010;
multiset<pair<int,int> > G[MAXN];
int n,m,X[MAXN],Y[MAXN];
int e[MAXN],ord[MAXN],tot;
void Euler(int x)
{
	while(!G[x].empty())
	{
		pair<int,int> Edge=(*G[x].begin());
		int t=Edge.first,id=Edge.second;
		G[x].erase(G[x].find(make_pair(t,id)));
		G[t].erase(G[t].find(make_pair(x,id)));
		Euler(t);
		e[++tot]=id;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&X[i],&Y[i]);
		Y[i]+=200001;
		G[X[i]].insert(make_pair(Y[i],i));
		G[Y[i]].insert(make_pair(X[i],i));
	}
	m=n;
	for(int i=1;i<=200001;i++)
		if(G[i].size()%2==1)
			m++,G[i].insert(make_pair(400002,m)),G[400002].insert(make_pair(i,m));
	for(int i=200002;i<=400002;i++)
		if(G[i].size()%2==1)
			m++,G[i].insert(make_pair(200001,m)),G[200001].insert(make_pair(i,m));
	for(int i=1;i<=400002;i++) Euler(i);
	for(int i=1;i<=m;i++) ord[e[i]]=i;
	for(int i=1;i<=n;i++)
		if(ord[i]%2) putchar('r');
		else putchar('b');
	puts("");
	return 0;
}
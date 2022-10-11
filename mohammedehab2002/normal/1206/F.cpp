#include <bits/stdc++.h>
using namespace std;
int n,sz[1005],lab[1005],cur=1,cur2,f=1;
vector<int> v[1005];
int getsz(int node,int p)
{
	sz[node]=1;
	for (int u:v[node])
	{
		if (u!=p)
		sz[node]+=getsz(u,node);
	}
	return sz[node];
}
int find(int node,int p)
{
	for (int u:v[node])
	{
		if (u!=p && sz[u]>n/2)
		return find(u,node);
	}
	return node;
}
void assign(int node,int p)
{
	if (f)
	lab[node]=cur++;
	else
	lab[node]=(++cur2)*cur;
	printf("%d %d %d\n",node,p,lab[node]-lab[p]);
	for (int u:v[node])
	{
		if (u!=p)
		assign(u,node);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	getsz(1,0);
	int c=find(1,0);
	getsz(c,0);
	vector<pair<int,int> > ch;
	for (int u:v[c])
	ch.push_back({sz[u],u});
	sort(ch.begin(),ch.end());
	reverse(ch.begin(),ch.end());
	for (auto p:ch)
	{
		assign(p.second,c);
		if (f && n<=3*cur && 3*cur<=2*n)
		f=0;
	}
}
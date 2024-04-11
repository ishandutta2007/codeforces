#include <iostream>
#include <vector>
#include <set>
using namespace std;
char s[200005];
int tree[800005];
void update(int node,int st,int en,int idx)
{
	if (st==en)
	tree[node]=1;
	else
	{
		int mid=(st+en)/2;
		if (st<=idx && idx<=mid)
		update(2*node,st,mid,idx);
		else
		update(2*node+1,mid+1,en,idx);
		tree[node]=tree[2*node]+tree[2*node+1];
	}
}
int query(int node,int st,int en,int l,int r)
{
	if (en<l || st>r || r<l)
	return 0;
	if (l<=st && en<=r)
	return tree[node];
	int mid=(st+en)/2;
	return query(2*node,st,mid,l,r)+query(2*node+1,mid+1,en,l,r);
}
int n;
int idx(int i)
{
	return i-query(1,0,n-1,0,i-1);
}
struct cmp
{
	bool operator()(const int &x,const int &y) const
	{
		return idx(x)<y;
	}
};
set<int,cmp> pos[200];
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	getchar();
	gets(s);
	for (int i=0;i<n;i++)
	pos[s[i]].insert(i);
	while (m--)
	{
		int l,r;
		char c;
		scanf("%d%d %c",&l,&r,&c);
		l--;
		r--;
		vector<int> v;
		auto it=pos[c].lower_bound(l);
		for (;it!=pos[c].end() && idx(*it)<=r;)
		{
			auto it2=it;
			v.push_back(*it);
			it++;
			pos[c].erase(it2);
		}
		for (int i:v)
		update(1,0,n-1,i);
	}
	set<int> ans;
	for (int i=0;i<200;i++)
	{
		for (int x:pos[i])
		ans.insert(x);
	}
	for (int i:ans)
	printf("%c",s[i]);
}
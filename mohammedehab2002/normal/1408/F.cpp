#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > ans;
void solve(int l,int r)
{
	if (l==r)
	return;
	int mid=(l+r)/2;
	for (int i=l;i<=mid;i++)
	ans.push_back({i,mid+i-l+1});
	solve(l,mid);
	solve(mid+1,r);
}
int main()
{
	int n;
	scanf("%d",&n);
	int p=31-__builtin_clz(n);
	solve(1,(1<<p));
	solve(n-(1<<p)+1,n);
	printf("%d\n",ans.size());
	for (auto p:ans)
	printf("%d %d\n",p.first,p.second);
}
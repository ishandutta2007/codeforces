#include<bits/stdc++.h>
using namespace std;
int n;pair<int,int>a[10005];set<pair<int,int> >s;
inline void solve(int l,int r)
{
	int mid=(l+r)>>1;if(l>=r) return;
	for(int i=l;i<=r;i++) s.insert(make_pair(a[mid].first,a[i].second));
	solve(l,mid-1),solve(mid+1,r);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].first,&a[i].second),s.insert(a[i]);
	sort(a+1,a+n+1),solve(1,n),printf("%d\n",s.size());
	for(set<pair<int,int> >::iterator i=s.begin();i!=s.end();i++) printf("%d %d\n",(*i).first,(*i).second);
	return 0;
}
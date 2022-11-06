#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m,X;
int a[N],dis[N];
set<pair<int,int> > e[N];
set<pair<int,int> > S;
vector<int> ans;
inline int find(int x)
{
	return dis[x]==x?x:(dis[x]=find(dis[x]));
}
inline void merge(int x,int y,int t)
{
	ans.push_back(t);
	if((int)e[x].size()>(int)e[y].size())
		swap(x,y);
	S.erase(S.find(make_pair(a[x],x)));
	S.erase(S.find(make_pair(a[y],y)));
	dis[x]=y;a[y]+=a[x]-X;
	S.insert(make_pair(a[y],y));
	for(auto a:e[x])
		e[y].insert(a);
}
//inline void merge2(int x,int y)
//{
//	if((int)e[x].size()>(int)e[y].size())
//		swap(x,y);
//	dis[x]=y;a[y]+=a[x]-X;
//	for(auto a:e[x])
//		e[y].insert(a);
//	while(!e[y].empty())
//	{
//		int z=*e[y].begin();
//		e[y].erase(e[y].begin());
//		z=find(z);
//		if(z==y)
//			continue;
//		if(a[y]+a[z]>=X)
//			return merge2(y,z);
//	}
//	puts("NO");
//	exit(0);
//}
signed main()
{
	int x,y;
	register int i;
	scanf("%lld%lld%lld",&n,&m,&X);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]),dis[i]=i,S.insert(make_pair(a[i],i));
	for(i=1;i<=m;i++)
		scanf("%lld%lld",&x,&y),e[x].insert(make_pair(y,i)),e[y].insert(make_pair(x,i));
	while((int)S.size()>1)
	{
		x=(*S.rbegin()).second;
		while(!e[x].empty())
		{
			auto p=*e[x].begin();
			int z=p.first;
			e[x].erase(e[x].begin());
			z=find(z);
			if(z==x)
				continue;
			else if(a[x]+a[z]>=X)
			{
				merge(z,x,p.second);
				goto end;
			}
		}
		puts("NO");
		return 0;
		end:;
	}
	puts("YES");
	for(int a:ans)
		printf("%lld\n",a);
	return 0;
}
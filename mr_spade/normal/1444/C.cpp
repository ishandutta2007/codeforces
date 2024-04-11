#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int dis[N],fw[N],size[N];
stack<int> st;
inline int find(int x,int &d)
{
	d=0;
	while(dis[x]!=x)
		d^=fw[x],x=dis[x];
	return x;
}
inline bool merge(int x,int y)
{
	int dx,dy;
	if((x=find(x,dx))==(y=find(y,dy)))
	{
		if(dx==dy)
			return 1;
		return 0;
	}
	if(size[x]<size[y])
		swap(x,y);
	dis[y]=x;fw[y]=1^dx^dy;size[x]+=size[y];
	st.push(y);
	return 0;
}
inline void undo(int t)
{
	while((int)st.size()!=t)
	{
		size[dis[st.top()]]-=size[st.top()];
		fw[st.top()]=0;dis[st.top()]=st.top();
		st.pop();
	}
	return;
}
int n,m,k,k2;
long long ans;
int c[N],bk[N];
struct cell
{
	int x,y;
	inline bool operator<(cell th) const
	{
		if(x!=th.x)
			return x<th.x;
		return y<th.y;
	}
};
vector<cell> E;
set<cell> S;
inline bool cmp(cell a,cell b)
{
	if(c[a.x]!=c[b.x])
		return c[a.x]<c[b.x];
	return c[a.y]<c[b.y];
}
signed main()
{
	int x,y;
	register int i;
	scanf("%d%d%d",&n,&m,&k);k2=k;
	for(i=1;i<=n;i++)
		dis[i]=i,size[i]=1,scanf("%d",&c[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		if(c[x]==c[y])
		{
			if(merge(x,y))
			{
				if(!bk[c[x]])
					k2--;
				bk[c[x]]=1;
			}
		}
		else
		{
			if(c[x]>c[y])
				swap(x,y);
			E.push_back(cell{x,y});
		}
	}
	sort(E.begin(),E.end(),cmp);
	int _=(int)st.size();
	cell el=cell{0,0};
	for(cell e:E)
	{
		if(bk[c[e.x]]||bk[c[e.y]])
			continue;
		if(cmp(el,e))
			undo(_);
		if(merge(e.x,e.y))
			S.insert(cell{c[e.x],c[e.y]});
		el=e;
	}
	printf("%lld\n",(long long)k2*(k2-1)/2-(int)S.size());
	return 0;
}
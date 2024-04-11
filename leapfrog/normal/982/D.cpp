#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,a[100005],fa[100005],cn[100005],ccn[100005],cnt,mx,rs;pair<int,int>p[100005];
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void mrg(int x,int y)
{
	x=getf(x),y=getf(y);if(x==y) return;
	ccn[cn[x]]--,ccn[cn[y]]--,ccn[cn[x]+=cn[y]]++,fa[y]=x,cnt--;
}
inline void add(int id)
{
	fa[id]=id,ccn[cn[id]=1]++,cnt++;
	if(id!=1&&fa[id-1]) mrg(id-1,id);
	if(id!=n&&fa[id+1]) mrg(id+1,id);
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(p[i].first),p[i].second=i;
	sort(p+1,p+n+1);for(int i=1;i<=n;i++)
	{
		add(p[i].second);while(i<n&&p[i+1].first==p[i].first) add(p[++i].second);
		if(cnt==ccn[cn[getf(p[i].second)]]&&cnt>mx) mx=cnt,rs=p[i].first+1;
		/*printf("cnt = %d\n",cnt);
		for(int j=1;j<=n;j++) printf("%d%c",getf(j),j==n?'\n':' ');
		for(int j=1;j<=n;j++) printf("%d%c",cn[getf(j)],j==n?'\n':' ');
		for(int j=1;j<=n;j++) printf("%d%c",ccn[j],j==n?'\n':' ');*/
	}
	return printf("%d\n",rs),0;
}
#include<bits/stdc++.h>
#define int long long
using namespace std;
int l[200005*35],r[200005*35],ch[200005*35][2],tot,n,a[200005],rt;
inline void add(int &rt,int x,int dep)
{
	if(!rt) rt=++tot;l[rt]=min(l[rt],x),r[rt]=max(r[rt],x);
	if(dep>=0) add(ch[rt][a[x]>>dep&1],x,dep-1);
}
inline int que(int rt,int x,int dep)
{
	if(dep<0) return 0;
	if(ch[rt][x>>dep&1]) return que(ch[rt][x>>dep&1],x,dep-1);
	return que(ch[rt][(x>>dep&1)^1],x,dep-1)+(1<<dep);
}
inline int dfs(int rt,int dep)
{
	if(dep<0) return 0;
	if(r[ch[rt][0]]&&r[ch[rt][1]])
	{
		int mn=(int)0x3f3f3f3f3f3f3f3f;
		for(int i=l[ch[rt][0]];i<=r[ch[rt][0]];i++) mn=min(mn,que(ch[rt][1],a[i],dep-1));
		return dfs(ch[rt][0],dep-1)+dfs(ch[rt][1],dep-1)+mn+(1<<dep);
	}
	if(r[ch[rt][0]]) return dfs(ch[rt][0],dep-1);else if(r[ch[rt][1]]) return dfs(ch[rt][1],dep-1);else return 0;
}
signed main()
{
	scanf("%lld",&n),tot=0;
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+n+1),memset(l,0x3f,sizeof(l)),memset(r,0,sizeof(r));
	for(int i=1;i<=n;i++) add(rt,i,30);
	return printf("%lld\n",dfs(rt,30)),0;
}
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int P=1e9+7;int n,m,fa[500005],sz[500005];vector<int>v[500005],ans;
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
int main()
{
	read(n),read(m);for(int i=1;i<=m;i++) sz[i]=0,fa[i]=i;
	for(int i=1,x;i<=n;i++) {read(x);for(int j=1,w;j<=x;j++) read(w),v[i].push_back(w);}
	for(int i=1;i<=n;i++)
		if(v[i].size()==2)
		{
			int x=getf(v[i][0]),y=getf(v[i][1]);
			if(x!=y&&!(sz[x]&sz[y])) fa[x]=y,sz[y]|=sz[x],ans.push_back(i);
		}
		else
		{
			int x=getf(v[i][0]);if(!sz[x]) sz[x]=1,ans.push_back(i);
		}
	int res=1;for(int i=0;i<(int)ans.size();i++) res=2ll*res%P;
	printf("%d %d\n",res,(int)ans.size());
	for(int i=0;i<(int)ans.size();i++) printf("%d ",ans[i]);
	return putchar('\n'),0;
}
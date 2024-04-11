//
//
#include<bits/stdc++.h>
using namespace std;const int P=1e9+7;
map<string,int>mp;int n,m,q,fa[200005];string s,t;
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void mrg(int x,int y) {int u=getf(x),v=getf(y);if(u^v) fa[u]=v;}
int main()
{
	cin>>n>>m>>q;int tot=0;
	for(int i=1;i<=n;i++) fa[i]=i,fa[i+n]=i+n,cin>>s,mp[s]=++tot;
	for(int i=1,f;i<=m;i++)
	{
		cin>>f>>s>>t;int i1=mp[s],i2=mp[t];
		if((f==1&&getf(i1)==getf(i2+n))||(f==2&&getf(i1)==getf(i2))) {puts("NO");continue;}
		puts("YES");if(f^1) mrg(i1+n,i2),mrg(i1,i2+n);else mrg(i1,i2),mrg(i1+n,i2+n);
	}
	for(int i=1;i<=q;i++)
	{
		cin>>s>>t;
		if(getf(mp[s])==getf(mp[t]+n)) puts("2");
		else if(getf(mp[s])==getf(mp[t])) puts("1");
		else puts("3");
	}
	return 0;
}
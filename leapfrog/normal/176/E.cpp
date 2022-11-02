//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}//}}}
typedef set<pair<int,int> >::iterator IT;
struct edge{int to,w,nxt;}e[200005];int n,et,head[100005];
int Q,f[100005][18],dep[100005],dfn[100005],dt;ll ds[100005];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void dfs0(int x,int fa,int ls)
{
	f[x][0]=fa,dep[x]=dep[fa]+1,ds[x]=ds[fa]+ls,dfn[x]=++dt;
	for(int i=1;i<18;i++) f[x][i]=f[f[x][i-1]][i-1];
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs0(e[i].to,x,e[i].w);
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=17;~i;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=17;~i;i--) if(f[x][i]^f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
inline ll dis(int x,int y) {int lc=LCA(x,y);return ds[x]+ds[y]-ds[lc]*2;}
int main()
{
	read(n);for(int i=1,x,y,w;i<n;i++) read(x),read(y),read(w),adde(x,y,w),adde(y,x,w);
	set<pair<int,int> >st;ll nw=0;for(dfs0(1,0,0),read(Q);Q--;)
	{
		char ch;int x;scanf("%s",&ch);if(ch^'?') read(x);
		if(ch=='?') {printf("%lld\n",nw>>1);continue;}
		if(ch=='-')
		{
			IT it=st.lower_bound(make_pair(dfn[x],x));
			if((int)st.size()<=2) {st.erase(it),nw=0;continue;}
			IT ls=it;if(ls==st.begin()) ls=--st.end();else --ls;
			IT rs=it;++rs;if(rs==st.end()) rs=st.begin();
			int a=ls->second,b=rs->second;nw-=dis(a,x)+dis(b,x)-dis(a,b);
			st.erase(it);continue;
		}
		if((int)st.size()==0) {st.insert(make_pair(dfn[x],x));continue;}
		if((int)st.size()==1)
		{
			int y=st.begin()->second;nw+=dis(x,y)<<1;
			st.insert(make_pair(dfn[x],x));continue;
		}
		IT it=st.lower_bound(make_pair(dfn[x],x));
		IT ls=it;if(ls==st.begin()) ls=--st.end();else ls--;
		IT rs=it;if(rs==st.end()) rs=st.begin();
		int a=ls->second,b=rs->second;nw+=dis(a,x)+dis(b,x)-dis(a,b);
		st.insert(make_pair(dfn[x],x));
	}
	return 0;
}
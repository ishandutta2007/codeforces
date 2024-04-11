//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,m,rs[200005];ll L[200005],R[200005];
struct node{ll fs,sc;int id;char operator<(node b) const {return sc^b.sc?sc<b.sc:fs<b.fs;}}p[200005];
int main()
{
	read(n),read(m);set<pair<ll,int> >st;
	for(int i=1;i<=n;i++) read(L[i]),read(R[i]);
	for(int i=1;i<=m;i++) {ll x;read(x),st.insert(make_pair(x,i));}
	for(int i=1;i<n;i++) p[i]=(node){L[i+1]-R[i],R[i+1]-L[i],i};
	sort(p+1,p+n);for(int i=1;i<n;i++)
	{
		auto it=st.lower_bound(make_pair(p[i].fs,-114514));
		if(it==st.end()||it->first>p[i].sc) return puts("No"),0;
		rs[p[i].id]=it->second,st.erase(it);
	}
	puts("Yes");for(int i=1;i<n;i++) printf("%d%c",rs[i],i==n-1?'\n':' ');
	return 0;
}
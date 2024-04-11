//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int n,Q,a[150005],fa[1000005];vector<int>v[1000005];
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void mrg(int x,int y) {x=getf(x),y=getf(y);if(x^y) fa[x]=y;}
int main()
{
	read(n),read(Q);for(int i=1;i<=n;i++) read(a[i]);
	int mx=0;for(int i=1;i<=n;i++) mx=max(mx,a[i]);
	for(int i=2;i<=mx+1;i++) if(v[i].empty()) for(int j=i;j<=mx+1;j+=i) v[j].push_back(i);
	for(int i=1;i<=mx+1;i++) fa[i]=i;
	for(int i=1;i<=n;i++) for(auto j:v[a[i]]) mrg(a[i],j);
	set<pair<int,int> >st;for(int i=1;i<=n;i++)
	{
		vector<int>b=v[a[i]+1];b.push_back(a[i]);int sz=b.size();
		for(int j=0;j<sz;j++) b[j]=getf(b[j]);
		for(int j=0,x,y;j<sz;j++) for(int k=j+1;k<sz;k++)
			{x=b[j],y=b[k];if(x^y) st.insert(make_pair(min(x,y),max(x,y)));}
	}
	for(int l,r;Q--;)
	{
		read(l),read(r),l=getf(a[l]),r=getf(a[r]);
		if(l==r) {puts("0");continue;}
		puts(st.count(make_pair(min(l,r),max(l,r)))?"1":"2");
	}
	return 0;
}
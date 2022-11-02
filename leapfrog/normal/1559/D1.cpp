//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int n,m1,m2,fr[1000005],tw[1000005],cn;
struct dsu
{
	int fa[100005];
	inline void init() {for(int i=1;i<=n;i++) fa[i]=i;}
	inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
	inline void mrg(int x,int y) {x=getf(x),y=getf(y);if(x^y) fa[x]=y;}
}A,B;
vector<pair<int,int> >rs;
inline void add(int x,int y) {rs.push_back(make_pair(x,y));}
int main()
{
	read(n),read(m1),read(m2),A.init(),B.init();
	for(int i=1,x,y;i<=m1;i++) read(x),read(y),A.mrg(x,y);
	for(int i=1,x,y;i<=m2;i++) read(x),read(y),B.mrg(x,y);
	if(m1<m2) swap(A,B),swap(m1,m2);
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
		if(A.getf(i)!=A.getf(j)) ++cn,fr[cn]=i,tw[cn]=j;
	for(int i=1;i<=cn;i++) if(B.getf(fr[i])!=B.getf(tw[i])&&A.getf(fr[i])!=A.getf(tw[i]))
		add(fr[i],tw[i]),B.mrg(fr[i],tw[i]),A.mrg(fr[i],tw[i]);
	printf("%d\n",(int)rs.size());
	for(auto x:rs) printf("%d %d\n",x.first,x.second);
	return 0;
}
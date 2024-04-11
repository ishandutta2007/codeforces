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
int n,m1,m2,a[100005],ta,b[100005],tb;vector<pair<int,int> >rs;
struct dsu
{
	int fa[100005];
	inline void init(int n) {for(int i=1;i<=n;i++) fa[i]=i;}
	inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
	inline void mrg(int x,int y) {x=getf(x),y=getf(y);if(x^y) fa[x]=y;}
	inline char chk(int x,int y) {return getf(x)!=getf(y);}
}A,B;
inline void ad(int x,int y) {rs.push_back(make_pair(x,y));}
inline void flush()
{
	printf("%d\n",(int)rs.size());
	for(auto x:rs) printf("%d %d\n",x.first,x.second);
}
int main()
{
	read(n),read(m1),read(m2),A.init(n),B.init(n);
	for(int i=1,x,y;i<=m1;i++) read(x),read(y),A.mrg(x,y);
	for(int i=1,x,y;i<=m2;i++) read(x),read(y),B.mrg(x,y);
	for(int i=2;i<=n;i++) if(A.chk(1,i)&&B.chk(1,i)) A.mrg(1,i),B.mrg(1,i),ad(1,i);
	for(int i=2;i<=n;i++) if(A.chk(1,i)) a[++ta]=i,A.mrg(1,i);
	for(int i=2;i<=n;i++) if(B.chk(1,i)) b[++tb]=i,B.mrg(1,i);
	for(int i=1;i<=ta&&i<=tb;i++) ad(a[i],b[i]);
	return flush(),0;
}
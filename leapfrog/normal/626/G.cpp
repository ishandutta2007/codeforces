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
typedef long double ld;int n,t,q,p[200005],l[200005],c[200005];ld res;
inline ld F(int x,int w) {return w<0?1e18L:w>=l[x]?0.0L:1.0L*p[x]*l[x]/(w+1+l[x])/(w+l[x]);}
inline ld G(int x) {return 1.0L*p[x]*min(c[x],l[x])/(min(c[x],l[x])+l[x]);}
struct node
{
	ld w;int id,nw;node(int x=0,int wh=-1):id(x),nw(wh) {w=F(x,wh);}
	inline char operator<(node b) const {return fabs(w-b.w)<1e-12?id<b.id:w<b.w;}
};multiset<node>s,e;
inline void add()
{
	multiset<node>::iterator it=--s.end();
	int id=it->id;res+=it->w;
	e.erase(node(id,c[id]-1)),e.insert(*it);
	s.erase(it),s.insert(node(id,++c[id]));
}
inline void del()
{
	multiset<node>::iterator it=e.begin();
	int id=it->id;res-=it->w;
	s.erase(node(id,c[id])),s.insert(*it);
	e.erase(it),e.insert(node(id,--c[id]-1));
}
int main()
{
	read(n),read(t),read(q);for(int i=1;i<=n;i++) read(p[i]);
	for(int i=1;i<=n;i++) read(l[i]),s.insert(node(i,0)),e.insert(node(i,-1));
	{while(t--) add();}for(int i=1,x,ch;i<=q;i++)
	{
		read(ch),read(x),s.erase(node(x,c[x])),e.erase(node(x,c[x]-1)),res-=G(x);
		l[x]+=ch==1?1:-1,s.insert(node(x,c[x])),e.insert(node(x,c[x]-1)),res+=G(x);
		while((--s.end())->w>(e.begin())->w+1e-12) del(),add();
		printf("%.10Lf\n",res);
	}
	return 0;
}
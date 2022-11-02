//
//
#include<bits/stdc++.h>
using namespace std;const int INF=1e9+9;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct node{int w,v;bool operator<(node b) const {return v<b.v;}}a[200005];
struct seg{mutable int l,r;bool operator<(seg b) const {return l<b.l;}};
int n,rs[200005];typedef set<seg>::iterator IT;set<seg>s;
inline void split(int w,int vl)
{
	// for(IT i=s.begin();i!=s.end();i++) printf("[ %d , %d ]\n",i->l,i->r);
	IT i=s.lower_bound((seg){w,0});
	// putchar('\n');cerr<<"split : "<<w<<" ( "<<i->l<<" , "<<i->r<<endl;
	if(i!=s.end()&&i->l==w)
	{
		rs[i->r-i->l+1]=max(rs[i->r-i->l+1],vl);
		if(i->l==i->r) return(void)(s.erase(i));else return (void)(i->l++);
	}else --i;
	rs[i->r-i->l+1]=max(rs[i->r-i->l+1],vl);
	// cerr<<i->l<<" ~ "<<i->r<<" -> "<<vl<<endl;
	int l=i->l,r=i->r;s.erase(i),s.insert((seg){l,w-1});
	if(w!=r) s.insert((seg){w+1,r}).first;
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i].v),a[i].w=i;
	sort(a+1,a+n+1),memset(rs,0,sizeof(rs)),s.insert((seg){1,n});
	for(int i=1;i<=n;i++) split(a[i].w,a[i].v);
	for(int i=n;i>=1;i--) rs[i]=max(rs[i],rs[i+1]);
	for(int i=1;i<=n;i++) printf("%d%c",rs[i],i==n?'\n':' ');
	return 0;
}
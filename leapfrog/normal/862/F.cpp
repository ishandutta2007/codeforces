//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=100005,B=80;
char *a[N],buf[N<<1],*bf;int n,q,lc[N],g[N],gt,ln[N],st[N],tp,lv[N],rv[N];
struct Seg1/*{{{*/
{
	int T[N<<2];
	inline void pushup(int x) {T[x]=max(T[x<<1],T[x<<1|1]);}
	inline void build(int x,int l,int r,int *a)
	{
		if(l==r) return T[x]=a[l],void();
		build(x<<1,l,(l+r)>>1,a),build(x<<1|1,((l+r)>>1)+1,r,a),pushup(x);
	}
	inline void modif(int x,int l,int r,int dw,int dc)
	{
		if(l==r) return T[x]=dc,void();
		if(dw<=((l+r)>>1)) modif(x<<1,l,(l+r)>>1,dw,dc),pushup(x);
		else modif(x<<1|1,((l+r)>>1)+1,r,dw,dc),pushup(x);
	}
	inline int query(int x,int l,int r,int dl,int dr)
	{
		if(l>dr||dl>r) return 0;else if(dl<=l&&r<=dr) return T[x];
		return max(query(x<<1,l,(l+r)>>1,dl,dr),query(x<<1|1,((l+r)>>1)+1,r,dl,dr));
	}
}s1;/*}}}*/
struct ${int mx,lv,rv;char fg;};/*{{{*/
inline $ operator+($ a,$ b) {return($){max(max(a.mx,b.mx),a.rv+b.lv),a.lv+a.fg*b.lv,b.rv+b.fg*a.rv,a.fg&&b.fg};}
struct Seg2
{
	$ T[N<<2];
	inline void build(int x,int l,int r,int *a,int lim)
	{
		if(l==r) return T[x]=($){a[l]>=lim,a[l]>=lim,a[l]>=lim,a[l]>=lim},void();
		build(x<<1,l,(l+r)>>1,a,lim),build(x<<1|1,((l+r)>>1)+1,r,a,lim),T[x]=T[x<<1]+T[x<<1|1];
	}
	inline void modif(int x,int l,int r,int dw,char dc)
	{
		if(l==r) return T[x]=($){dc,dc,dc,dc},void();
		if(dw<=((l+r)>>1)) modif(x<<1,l,(l+r)>>1,dw,dc),T[x]=T[x<<1]+T[x<<1|1];
		else modif(x<<1|1,((l+r)>>1)+1,r,dw,dc),T[x]=T[x<<1]+T[x<<1|1];
	}
	inline $ query(int x,int l,int r,int dl,int dr)
	{
		if(l>dr||dl>r) return($){0,0,0,1};else if(dl<=l&&r<=dr) return T[x];
		return query(x<<1,l,(l+r)>>1,dl,dr)+query(x<<1|1,((l+r)>>1)+1,r,dl,dr);
	}
	inline void debug(int x,int l,int r)
	{
		if(l==r) return printf("%d%c",T[x].fg,l==n-1?'\n':' '),void();
		debug(x<<1,l,(l+r)>>1),debug(x<<1|1,((l+r)>>1)+1,r);
	}
}s2[B+1];/*}}}*/
inline int LCP(int x,int y)
{
	int n=min(ln[x],ln[y]);for(int i=1;i<=n;i++)
		if(a[x][i]!=a[y][i]) return i-1;
	return n;
}
inline void chang(int x,int y)
{
	int od=lc[x],nw=y;lc[x]=y;
	if(od>B&&nw<=B)
	{
		int wh=lower_bound(g+1,g+gt+1,x)-g;gt--;
		for(int j=wh;j<=gt;j++) g[j]=g[j+1];
	}
	if(od<=B&&nw>B)
	{
		int wh=lower_bound(g+1,g+gt+1,x)-g;
		for(int j=gt;j>=wh;j--) g[j+1]=g[j];
		gt++,g[wh]=x;
	}
	for(int i=1;i<=B;i++) s2[i].modif(1,1,n-1,x,i<=y);
}
inline void update(int x)
{
	s1.modif(1,1,n,x,ln[x]);
	if(x^1) chang(x-1,LCP(x-1,x));
	if(x^n) chang(x,LCP(x,x+1));
}
inline int work(int l,int r)
{
	for(int i=l;i<=r;i++) rv[i]=r+1,lv[i]=l-1;
	tp=0;for(int i=l;i<=r;i++) {for(;tp&&lc[st[tp]]>lc[i];tp--) rv[st[tp]]=i;st[++tp]=i;}
	tp=0;for(int i=r;i>=l;i--) {for(;tp&&lc[st[tp]]>lc[i];tp--) lv[st[tp]]=i;st[++tp]=i;}
	int rs=0;for(int i=l;i<=r;i++) rs=max(rs,lc[i]*(rv[i]-lv[i]));
	return rs;
}
inline int solve(int l,int r)
{
	//for(int i=1;i<n;i++) printf("%d%c",lc[i],i==n-1?'\n':' ');
	//for(int i=1;i<=gt;i++) printf("%d%c",g[i],i==gt?'\n':' ');
	int rs=0;for(int i=1,v;i<=B;i++) v=s2[i].query(1,1,n-1,l,r-1).mx,v?rs=max(rs,(v+1)*i):0;
	for(int L=lower_bound(g+1,g+gt+1,l)-g,R;L<=gt&&g[L]<r;L=R+1)
		{for(R=L;R<gt&&g[R+1]<r&&g[R+1]==g[R]+1;R++);rs=max(rs,work(g[L],g[R]));}
	rs=max(rs,s1.query(1,1,n,l,r));return rs;
}
int main()
{
	bf=buf,read(n,q);for(int i=1;i<=n;i++)
		scanf("%s",bf+1),a[i]=bf,bf+=(ln[i]=strlen(bf+1));
	if(n==1)
	{
		for(int i=1,f,x,y;i<=q;i++)
		{
			read(f,x);if(f&1) read(y),printf("%d\n",ln[x]);
			else scanf("%s",bf+1),a[x]=bf,bf+=(ln[x]=strlen(bf+1));
		}
		return 0;
	}
	for(int i=1;i<n;i++) lc[i]=LCP(i,i+1);
	s1.build(1,1,n,ln);for(int i=1;i<=B;i++) s2[i].build(1,1,n-1,lc,i);
	for(int i=1;i<=n;i++) if(lc[i]>B) g[++gt]=i;
	//for(int i=1;i<=B;i++) s2[i].debug(1,1,n-1);
	for(int i=1,f,x,y;i<=q;i++)
	{
		read(f,x);if(f&1) read(y),printf("%d\n",solve(x,y));
		else scanf("%s",bf+1),a[x]=bf,bf+=(ln[x]=strlen(bf+1)),update(x);
	}return 0;
}
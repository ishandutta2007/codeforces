#include<bits/stdc++.h>
#define SZ 254
#define L(a) ((a)*SZ-SZ+1)
#define R(a) ((a)*SZ)
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
template<typename T>inline void print(T x)
{
	if(x<0) putchar('-'),x=-x;
	{if(x>9) print(x/10);}putchar(x%10+48);
}
struct node{int rt,nm;}g[405][110005];
int n,Q,bl[110005],fa[110005],v[110005],a[110005],mx[110005],lz[110005];
inline int getf(int x) {return x==fa[x]?x:fa[x]=getf(fa[x]);}
inline void push(int x)
{
	for(int i=L(x),e=R(x);i<=e;++i) a[i]=v[getf(i)],g[x][a[i]].rt=g[x][a[i]].nm=0,a[i]-=lz[x];
	lz[x]=0;for(int i=L(x),e=R(x);i<=e;++i) fa[i]=0;
}
inline void init(int x)
{
	mx[x]=0;
	for(int i=L(x),e=R(x);i<=e;++i)
	{
		mx[x]=max(mx[x],a[i]),++g[x][a[i]].nm;
		if(g[x][a[i]].rt) fa[i]=g[x][a[i]].rt;else v[i]=a[i],g[x][a[i]].rt=fa[i]=i;
	}
}
inline void chng(int x,int a,int b)
{
	node &s=g[x][a],&t=g[x][b];
	if(t.rt) fa[s.rt]=t.rt;else t.rt=s.rt,v[s.rt]=b;
	t.nm+=s.nm,s.nm=s.rt=0;
}
inline void atag(int x,int ad)
{
	if(ad<=mx[x]-lz[x]-ad) {for(int i=lz[x]+1;i<=lz[x]+ad;++i) if(g[x][i].rt) chng(x,i,i+ad);lz[x]+=ad;}
	else {for(int i=mx[x];i>lz[x]+ad;i--) if(g[x][i].rt) chng(x,i,i-ad);mx[x]=min(mx[x],lz[x]+ad);}
}
inline void chang(int l,int r,int x)
{
	int p=bl[l],q=bl[r];push(p);if(p^q) push(q);
	if(p^q)
	{
		for(int i=l,e=R(p);i<=e;++i) if(a[i]>x) a[i]-=x;
		for(int i=L(q);i<=r;++i) if(a[i]>x) a[i]-=x;
		for(int i=p+1;i<=q-1;++i) atag(i,x);
		init(p),init(q);
	}
	else {for(int i=l;i<=r;++i) if(a[i]>x) a[i]-=x;init(p);}
}
inline int query(int l,int r,int x)
{
	int p=bl[l],q=bl[r],res=0;
	if(p^q)
	{
		for(int i=l,e=R(p);i<=e;++i) if(v[getf(i)]-lz[p]==x) ++res;
		for(int i=L(q);i<=r;++i) if(v[getf(i)]-lz[q]==x) ++res;
		for(int i=p+1;i<=q-1;i++) if(x+lz[i]<=100000) res+=g[i][x+lz[i]].nm;
	}
	else for(int i=l;i<=r;++i) if(v[getf(i)]-lz[p]==x) ++res;
	return res;
}
int main()
{
	read(n),read(Q);for(int i=1;i<=n;i++) read(a[i]),bl[i]=(i-1)/SZ+1;
	for(int i=bl[1];i<=bl[n];i++) init(i),lz[i]=0;
	for(int f,l,r,x;Q--;)
	{
		read(f),read(l),read(r),read(x);
		if(f==1) chang(l,r,x);else print(query(l,r,x)),putchar('\n');
	}
	return 0;
}
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
int n,Q,a[500005];
struct segm{char fg;int lv,rv;ll rs;}T[800005];
inline ll S(int x) {return 1ll*x*(x+1)/2;}
inline segm operator+(segm a,segm b)
{
	segm r;r.fg=a.fg&b.fg;r.rs=a.rs+b.rs;
	if(r.fg) return r.lv=r.rv=a.lv+b.lv,r.rs=0,r;
	if(a.fg) r.lv=a.lv+b.lv;else r.lv=a.lv;
	if(b.fg) r.rv=b.rv+a.rv;else r.rv=b.rv;
	if(!a.fg&&!b.fg) r.rs+=S(a.rv+b.lv);
	return r;
}
inline segm init(int x) {return(segm){(char)x,x,x,0};}
inline ll get(segm r) {if(r.fg) return S(r.lv);else return r.rs+S(r.lv)+S(r.rv);}
inline void modif(int x,int l,int r,int dw,int dc)
{
	if(l==r) return T[x]=init(dc),void();
	if(dw<=((l+r)>>1)) modif(x<<1,l,(l+r)>>1,dw,dc),T[x]=T[x<<1]+T[x<<1|1];
	else modif(x<<1|1,((l+r)>>1)+1,r,dw,dc),T[x]=T[x<<1]+T[x<<1|1];
}
inline segm query(int x,int l,int r,int dl,int dr)
{
	int md;if(dl<=l&&r<=dr) return T[x];else md=(l+r)>>1;
	if(dl>md) return query(x<<1|1,((l+r)>>1)+1,r,dl,dr);
	else if(md>=dr) return query(x<<1,l,(l+r)>>1,dl,dr);
	else return query(x<<1,l,(l+r)>>1,dl,dr)+query(x<<1|1,((l+r)>>1)+1,r,dl,dr);
}
int main()
{
	read(n,Q);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<n;i++) modif(1,1,n-1,i,a[i]<=a[i+1]);
	//for(int i=1;i<n;i++) printf("%d%c",a[i]<=a[i+1],i==n-1?'\n':' ');
	for(int i=1;i<=Q;i++)
	{
		int fg,l,r;read(fg,l,r);
		if(fg&1)
		{
			a[l]=r;if(l^n) modif(1,1,n-1,l,a[l]<=a[l+1]);
			if(l^1) modif(1,1,n-1,l-1,a[l-1]<=a[l]);
		}
		else
		{
			if(l==r) {puts("1");continue;}
			segm q=query(1,1,n-1,l,r-1);
			//printf("%d %d %d %lld\n",q.fg,q.lv,q.rv,q.rs);
			printf("%lld\n",get(q)+r-l+1);
		}
	}
}
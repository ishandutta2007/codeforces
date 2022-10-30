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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int N=200005;int n,K,D,a[N],s1[N],t1,s2[N],t2,vl[N];
struct segm{int mn,tg;}T[N<<2];
inline void pushup(int x) {T[x].mn=min(T[x<<1].mn,T[x<<1|1].mn);}
inline void allc(int x,int dc) {T[x].mn+=dc,T[x].tg+=dc;}
inline void pushdw(int x) {if(T[x].tg) allc(x<<1,T[x].tg),allc(x<<1|1,T[x].tg),T[x].tg=0;}
inline void build(int x,int l,int r)
{
	if(l==r) return T[x].mn=l,T[x].tg=0,void();
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),pushup(x);
}
inline void modif(int x,int l,int r,int dl,int dr,int dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x,dc);else pushdw(x);
	modif(x<<1,l,(l+r)>>1,dl,dr,dc),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),pushup(x);
}
inline int query(int x,int l,int r,int vl)
{
	if(T[x].mn>vl) return 0;else if(l==r) return l;else pushdw(x);
	int g;if((g=query(x<<1,l,(l+r)>>1,vl))) return g;
	if((g=query(x<<1|1,((l+r)>>1)+1,r,vl))) return g;
	return 0;
}
inline void ddmdf(int x,int l,int r,int dw)
{
	if(l==r) return T[x].mn=2e9+500000,T[x].tg=0,void();else pushdw(x);
	if(dw<=((l+r)>>1)) ddmdf(x<<1,l,(l+r)>>1,dw),pushup(x);
	else ddmdf(x<<1|1,((l+r)>>1)+1,r,dw),pushup(x);
}
inline void subtask()
{
	int rl=1,rr=0;for(int l=1,r;l<=n;l=r+1)
	{
		r=l;while(r<n&&a[r+1]==a[l]) r++;
		if(rr-rl<r-l) rl=l,rr=r;
	}
	printf("%d %d\n",rl,rr);
}
//#define DEB
inline void debug(int x,int l,int r)
{
	if(l==r) return printf("%d%c",T[x].mn,l==n?'\n':' '),void();
	pushdw(x),debug(x<<1,l,(l+r)>>1),debug(x<<1|1,((l+r)>>1)+1,r);
}
int main()
{
	read(n,K,D);for(int i=1;i<=n;i++) read(a[i]);
	if(!D) return subtask(),0;else build(1,1,n);
	int rl=1,rr=0;for(int l=1,r;l<=n;l=r+1)
	{
		r=l;while(r<n&&(a[r+1]%D+D)%D==(a[l]%D+D)%D) r++;
		int nw=l-1;for(int i=l;i<=r;i++) vl[i]=a[i]/D;
		map<int,int>ls;for(int i=l;i<=r;ls[a[i]]=i,i++)
		{
			for(int k=nw+1;k<=ls[a[i]];k++) nw=k,ddmdf(1,1,n,k);
			for(;t1&&vl[s1[t1]]<vl[i];t1--) modif(1,1,n,s1[t1-1]+1,s1[t1],vl[i]-vl[s1[t1]]);
			for(;t2&&vl[s2[t2]]>vl[i];t2--) modif(1,1,n,s2[t2-1]+1,s2[t2],vl[s2[t2]]-vl[i]);
			s1[++t1]=s2[++t2]=i;int wh=query(1,1,n,K+i);if(wh&&rr-rl<i-wh) rl=wh,rr=i;
#ifdef DEB
			printf("now : %d %d\n",wh,i);
			debug(1,1,n);
#endif
		}
		for(int i=nw+1;i<=r;i++) ddmdf(1,1,n,i);
	}
	return printf("%d %d\n",rl,rr),0;
}
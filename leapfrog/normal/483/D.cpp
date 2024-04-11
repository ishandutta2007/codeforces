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
const int N=100005;int n,m,L[N],R[N],vl[N],rs[N],cf[N],qz[N];
/*struct ${int vl,fg;}T[N<<2];
inline void pushup(int x) {T[x].vl=min(T[x<<1].vl,T[x<<1|1].vl);}
inline void allc(int x,char c) {T[x].vl=T[x].fg=c;}
inline void pushdw(int x) {if(~T[x].fg) allc(x<<1,T[x].fg),allc(x<<1|1,T[x].fg),T[x].fg=-1;}
inline void modif(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x,1);else pushdw(x);
	modif(x<<1,l,(l+r)>>1,dl,dr),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr),pushup(x);
}
inline int qry(int x,int l,int r,int dw)
{
	if(l==r) return T[x].vl;else pushdw(x);
	if(dw<=((l+r)>>1)) return qry(x<<1,l,(l+r)>>1,dw);
	else return qry(x<<1|1,((l+r)>>1)+1,r,dw);
}
inline int query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return 1;else if(dl<=l&&r<=dr) return T[x].vl;else pushdw(x);
	return min(query(x<<1,l,(l+r)>>1,dl,dr),query(x<<1|1,((l+r)>>1)+1,r,dl,dr));
}*/
int main()
{
	read(n,m);for(int i=1;i<=m;i++) read(L[i],R[i],vl[i]);
	for(int bt=30;bt>=0;bt--)
	{
		for(int i=0;i<=n+1;i++) cf[i]=0;
		for(int i=1;i<=m;i++) if((vl[i]>>bt)&1) cf[L[i]]++,cf[R[i]+1]--;
		for(int i=1;i<=n;i++) cf[i]+=cf[i-1];
		for(int i=1;i<=n;i++) cf[i]=!!cf[i],qz[i]=qz[i-1]+cf[i];
		for(int i=1;i<=m;i++) if(!((vl[i]>>bt)&1)&&qz[R[i]]-qz[L[i]-1]==R[i]-L[i]+1) return puts("NO"),0;
		for(int i=1;i<=n;i++) rs[i]|=cf[i]<<bt;
	}puts("YES");
	for(int i=1;i<=n;i++) printf("%d%c",rs[i],i==n?'\n':' ');
	return 0;
}
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct seg{int lz,len,ct[26];}t[400005];int n,m,v[26];char c[100005];
inline void allc(int x,int c) {memset(t[x].ct,0,sizeof(t[x].ct)),t[x].ct[c]=t[x].len,t[x].lz=c;}
inline void down(int x) {if(t[x].lz!=-1) allc(x<<1,t[x].lz),allc(x<<1|1,t[x].lz),t[x].lz=-1;}
inline void up(int x) {for(int i=0;i<26;i++) t[x].ct[i]=t[x<<1].ct[i]+t[x<<1|1].ct[i];}
inline void build(int x,int l,int r)
{
	if(l==r) return(void)(memset(t[x].ct,0,sizeof(t[x].ct)),t[x].len=t[x].ct[c[l]-97]=1,t[x].lz=-1);
	t[x].len=r-l+1,build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),t[x].lz=-1,up(x);
}
inline void chang(int x,int l,int r,int dl,int dr,int dv)
{
	if(l>dr||dl>r||dl>dr) return;else if(dl<=l&&r<=dr) return allc(x,dv);else down(x);
	chang(x<<1,l,(l+r)>>1,dl,dr,dv),chang(x<<1|1,((l+r)>>1)+1,r,dl,dr,dv),up(x);
}
inline void qry(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) {for(int i=0;i<26;i++) v[i]+=t[x].ct[i];return;}
	down(x),qry(x<<1,l,(l+r)>>1,dl,dr),qry(x<<1|1,((l+r)>>1)+1,r,dl,dr),up(x);
}
inline void paint(int x,int l,int r)
{
	if(l==r) for(int i=0;i<26;i++) {if(t[x].ct[i]) {putchar(i+97);break;}}
	else down(x),paint(x<<1,l,(l+r)>>1),paint(x<<1|1,((l+r)>>1)+1,r);
}
inline void srt(int l,int r,int fg)
{
	memset(v,0,sizeof(v)),qry(1,1,n,l,r);
	if(fg) {for(int i=0,id=l;i<26;i++) if(v[i]) chang(1,1,n,id,id+v[i]-1,i),id+=v[i];}
	else {for(int i=25,id=l;~i;i--) if(v[i]) chang(1,1,n,id,id+v[i]-1,i),id+=v[i];}
}
int main()
{
	read(n),read(m),scanf("%s",c+1),build(1,1,n);
	for(int i=1,l,r,fg;i<=m;i++) read(l),read(r),read(fg),srt(l,r,fg);
	return paint(1,1,n),putchar('\n'),0;
}
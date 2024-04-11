//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct seg{int tn[26],fg,ln;}T[400005],null;int n,m;char ch[100005];
inline seg operator+(seg a,seg b) {seg r;r.fg=-1,r.ln=a.ln+b.ln;for(int i=0;i<26;i++) r.tn[i]=a.tn[i]+b.tn[i];return r;}
inline void allc(int x,int c) {memset(T[x].tn,0,sizeof(T[x].tn)),T[x].tn[c]=T[x].ln,T[x].fg=c;}
inline void pushdw(int x) {if(~T[x].fg) allc(x<<1,T[x].fg),allc(x<<1|1,T[x].fg),T[x].fg=-1;}
inline void build(int x,int l,int r)
{
	T[x].ln=r-l+1,T[x].fg=-1;if(l==r) return T[x].tn[ch[l]-'a']++,void();
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),T[x]=T[x<<1]+T[x<<1|1];
}
inline void modif(int x,int l,int r,int dl,int dr,int dc)
{
	if(l>dr||dl>r||dl>dr) return;else if(dl<=l&&r<=dr) return allc(x,dc);else pushdw(x);
	modif(x<<1,l,(l+r)>>1,dl,dr,dc),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),T[x]=T[x<<1]+T[x<<1|1];
}
inline seg query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r||dl>dr) return null;else if(dl<=l&&r<=dr) return T[x];else pushdw(x);
	return query(x<<1,l,(l+r)>>1,dl,dr)+query(x<<1|1,((l+r)>>1)+1,r,dl,dr);
}
inline void srt(int l,int r)
{
	seg rs=query(1,1,n,l,r);int wh=-1;for(int i=0;i<26;i++) if(rs.tn[i]&1) {if(~wh) return;else wh=i;}
	if(~wh) modif(1,1,n,(l+r)>>1,(l+r)>>1,wh),rs.tn[wh]--;
	for(int i=0;i<26;i++) modif(1,1,n,l,l+(rs.tn[i]>>1)-1,i),l+=(rs.tn[i]>>1),modif(1,1,n,r-(rs.tn[i]>>1)+1,r,i),r-=(rs.tn[i]>>1);
}
inline void paint(int x,int l,int r)
{
	if(l^r) return pushdw(x),paint(x<<1,l,(l+r)>>1),paint(x<<1|1,((l+r)>>1)+1,r);
	else for(int i=0;i<26;i++) if(T[x].tn[i]) return putchar(i+'a'),void();
}
int main()
{
	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	read(n),read(m),scanf("%s",ch+1),build(1,1,n);
	for(int i=1,l,r;i<=m;i++) read(l),read(r),l<r?srt(l,r):void();
	return paint(1,1,n),putchar('\n'),0;
}
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
struct node{int ls,rs,vl;}T[10000005];int n,Q,rt[200005],tt;
int a[200005],nx[200005],lg[200005],wh[200005],p[455],pc,pw[88][19];
char pv[455],st[88][200005][18];const int P=1e9+7;
inline void initpr()
{
	pv[0]=pv[1]=1;for(int i=1;i<=450;i++)
	{
		if(!pv[i]) p[++pc]=i;
		for(int j=1;j<=pc&&i*p[j]<=450;j++) {pv[i*p[j]]=1;if(i%p[j]==0) break;}
	}
}
inline void initst()
{
	lg[0]=-1;for(int i=1;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(int k=1;k<=pc;k++) for(int j=1;j<=18;j++) for(int i=1;i+(1<<j)-1<=n;i++)
		st[k][i][j]=max(st[k][i][j-1],st[k][i+(1<<(j-1))][j-1]);
}
inline int stqry(int k,int l,int r) {int p=lg[r-l+1];return max(st[k][l][p],st[k][r-(1<<p)+1][p]);}
inline void pushup(int x) {T[x].vl=1ll*T[T[x].ls].vl*T[T[x].rs].vl%P;}
inline void build(int &x,int l,int r) {x=++tt,T[x].vl=1;if(l^r) build(T[x].ls,l,(l+r)>>1),build(T[x].rs,((l+r)>>1)+1,r);}
inline void mdfcg(int x,int l,int r,int dw,int dc)
{
	if(l==r) return T[x].vl=dc,void();
	if(dw<=((l+r)>>1)) mdfcg(T[x].ls,l,(l+r)>>1,dw,dc),pushup(x);
	else mdfcg(T[x].rs,((l+r)>>1)+1,r,dw,dc),pushup(x);
}
inline void mdfnw(int &x,int y,int l,int r,int dw,int dc)
{
	T[x=++tt]=T[y];if(l==r) return T[x].vl=dc,void();
	if(dw<=((l+r)>>1)) mdfnw(T[x].ls,T[y].ls,l,(l+r)>>1,dw,dc),pushup(x);
	else mdfnw(T[x].rs,T[y].rs,((l+r)>>1)+1,r,dw,dc),pushup(x);
}
inline int zxqry(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return 1;else if(dl<=l&&r<=dr) return T[x].vl;
	return 1ll*zxqry(T[x].ls,l,(l+r)>>1,dl,dr)*zxqry(T[x].rs,((l+r)>>1)+1,r,dl,dr)%P;
}
int main()
{
	initpr(),read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) for(int j=1;j<=pc;j++) while(a[i]%p[j]==0) a[i]/=p[j],st[j][i][0]++;
	initst(),build(rt[0],1,n),read(Q);
	for(int i=1;i<=n;wh[a[i]]=i,i++) if(!wh[a[i]]) mdfcg(rt[0],1,n,i,a[i]);else nx[wh[a[i]]]=i;
	for(int i=1;i<=n;i++) if(nx[i]) mdfnw(rt[i],rt[i-1],1,n,nx[i],a[nx[i]]);else rt[i]=rt[i-1];
	for(int i=1;i<=pc;i++) {pw[i][0]=1;for(int j=1;j<=18;j++) pw[i][j]=1ll*pw[i][j-1]*p[i]%P;}
	for(int l,r,ls=0,res;Q--;)
	{
		read(l),read(r),l=(l+ls)%n+1,r=(r+ls)%n+1;if(l>r) swap(l,r);
		res=1;for(int i=1;i<=pc;i++) res=1ll*res*pw[i][stqry(i,l,r)]%P;
		printf("%d\n",ls=1ll*res*zxqry(rt[l-1],1,n,l,r)%P);
	}
	return 0;
}
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
const int P=1e9+7,I=(P+1)>>1;int r[19];
int Q,mx,n,m,a[131075],b[131075],c[131075],F[131075],sz[131075],f[131075][18];
inline void Pl(int &a,int b) {(a+=b)>=P?a-=P:a;}
inline int pl(int a,int b) {return (a+=b)>=P?a-=P:a;}
inline void For(int *f)/*{{{*/
{
	for(int d=1;d<n;d<<=1) for(int l=0;l<n;l+=d+d)
		for(int k=l;k<((l|d));k++) Pl(f[k|d],f[k]);
}
inline void IFor(int *f)
{
	for(int d=1;d<n;d<<=1) for(int l=0;l<n;l+=d+d)
		for(int k=l;k<(l|d);k++) Pl(f[k|d],P-f[k]);
}
inline void Fand(int *f)
{
	for(int d=1;d<n;d<<=1) for(int l=0;l<n;l+=d+d)
		for(int k=l;k<(l|d);k++) Pl(f[k],f[k|d]);
}
inline void IFand(int *f)
{
	for(int d=1;d<n;d<<=1) for(int l=0;l<n;l+=d+d)
		for(int k=l;k<(l|d);k++) Pl(f[k],P-f[k|d]);
}
inline void Fxor(int *f)
{
	for(int d=1;d<n;d<<=1) for(int l=0;l<n;l+=d+d) for(int k=l;k<(l|d);k++)
		{int a=f[k],b=f[k|d];f[k]=pl(a,b),f[k|d]=pl(a,P-b);}
}
inline void IFxor(int *f)
{
	for(int d=1;d<n;d<<=1) for(int l=0;l<n;l+=d+d) for(int k=l;k<(l|d);k++)
		{int a=f[k],b=f[k|d];f[k]=1ll*(a+b)*I%P,f[k|d]=1ll*(a+P-b)*I%P;}
}
inline void Dwt()
{
	for(int d=1;d<n;d<<=1) for(int l=0;l<n;l+=d+d) for(int k=l;k<(l|d);k++)
		for(int i=0;i<=m;i++) Pl(f[k|d][i],f[k][i]);
}
inline void IDwt()
{
	for(int d=1;d<n;d<<=1) for(int l=0;l<n;l+=d+d) for(int k=l;k<(l|d);k++)
		for(int i=0;i<=m;i++) Pl(f[k|d][i],P-f[k][i]);
}
inline void juan(int *a,int *b,int *w)
{
	for(int i=0;i<=m;i++) r[i]=0;
	for(int i=0;i<=m;i++) for(int j=0;j+i<=m;j++) r[i+j]=(r[i+j]+1ll*a[i]*b[j])%P;
	for(int i=0;i<=m;i++) w[i]=r[i];
}/*}}}*/
int main()
{
	read(Q);for(int i=1,x;i<=Q;i++) read(x),a[x]++,mx=max(mx,x);
	n=1,m=0;while(n<=mx) n<<=1,m++;
	for(int i=1;i<n;i++) sz[i]=sz[i>>1]+(i&1);
	F[1]=1;for(int i=2;i<n;i++) F[i]=pl(F[i-1],F[i-2]);
	for(int i=0;i<n;i++) f[i][sz[i]]=a[i];
	Dwt();for(int i=0;i<n;i++) juan(f[i],f[i],f[i]);
	IDwt();for(int i=0;i<n;i++) b[i]=f[i][sz[i]],c[i]=a[i],a[i]=1ll*a[i]*F[i]%P;
	Fxor(c);for(int i=0;i<n;i++) c[i]=1ll*c[i]*c[i]%P;
	IFxor(c);for(int i=0;i<n;i++) b[i]=1ll*b[i]*F[i]%P,c[i]=1ll*c[i]*F[i]%P;
	Fand(a),Fand(b),Fand(c);for(int i=0;i<n;i++) a[i]=1ll*a[i]*b[i]%P*c[i]%P;
	IFand(a);int rs=0;for(int i=1;i<n;i<<=1) Pl(rs,a[i]);
	return printf("%d\n",rs),0;
}
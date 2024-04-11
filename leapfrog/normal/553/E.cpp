//
#include<bits/stdc++.h>
using namespace std;typedef long long typf;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
namespace poly
{
	const double pi=acos(-1);struct comp
	{
		double x,y;
		inline comp operator+(const comp &b) const {return(comp){x+b.x,y+b.y};}
		inline comp operator-(const comp &b) const {return(comp){x-b.x,y-b.y};}
		inline comp operator*(const comp &b) const {return(comp){x*b.x-y*b.y,x*b.y+y*b.x};}
		inline comp operator*(const double &b) const {return(comp){x*b,y*b};}
		inline comp operator/(const double &b) const {return(comp){x/b,y/b};}
	}A[800005],B[800005];int rv[800005];
	inline void init(int T) {rv[0]=0;for(int i=1;i<T;i++) rv[i]=(rv[i>>1]>>1)|((i&1)?(T>>1):0);}
	inline void FFT(int T,comp *a,int fg)
	{
		for(int i=0;i<T;i++) if(rv[i]>i) swap(a[i],a[rv[i]]);
		for(int d=1;d<T;d<<=1)
		{
			comp wn=(comp){cos(pi/d),sin(pi/d)*fg},w;
			for(int i=0,k;i<T;i+=d+d) for(k=0,w=(comp){1,0};k<d;k++,w=w*wn)
				{comp x=a[i+k],y=a[i+k+d]*w;a[i+k]=x+y,a[i+k+d]=x-y;}
		}
		if(fg==-1) for(int i=0;i<T;i++) a[i]=a[i]/T;
	}
	inline void solve(int n,double *a,double *b)
	{
		int T=1;while(T<=n+n) T<<=1;init(T);
		for(int i=0;i<T;i++) if(i<=n) A[i]=(comp){a[i],0},B[i]=(comp){b[i],0};else A[i]=B[i]=(comp){0,0};
		FFT(T,A,1),FFT(T,B,1);for(int i=0;i<T;i++) A[i]=A[i]*B[i];
		FFT(T,A,-1);for(int i=0;i<=n;i++) a[i]=A[i].x;
	}
}
int n,m,T,K,ds[55][55],fr[105],tw[105],we[105];
double p[105][20005],g[105][20005],f[105][20005],F[20005],G[20005];
inline void cdq(int l,int r)
{
	int md=(l+r)>>1;if(l==r) {for(int i=1;i<=m;i++) f[fr[i]][l]=min(f[fr[i]][l],g[i][l]);return;}else cdq(md+1,r);
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<r-md;j++) F[j]=f[tw[i]][j+md+1];
		for(int j=r-md;j<r-l;j++) F[j]=0;
		for(int j=0;j<r-l;j++) G[j]=p[i][T-(r-l-j)];
		/*puts("-----------------");
		for(int i=0;i<r-l;i++) printf("%.5lf%c",F[i],i==r-l-1?'\n':' ');
		for(int i=0;i<r-l;i++) printf("%.5lf%c",G[i],i==r-l-1?'\n':' ');*/
		poly::solve(r-l-1,F,G);for(int j=l;j<=md;j++) g[i][j]+=F[j+r-l-md-1];
		//for(int i=0;i<r-l;i++) printf("%.5lf%c",F[i],i==r-l-1?'\n':' ');
	}
	cdq(l,md);
}
int main()
{
	read(n),read(m),read(T),read(K);for(int i=1;i<n;i++) for(int j=0;j<=T;j++) f[i][j]=1e9;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ds[i][j]=(i!=j)*1e9;
	for(int i=1,x,y,w;i<=m;i++)
	{
		read(x),read(y),read(w),fr[i]=x,tw[i]=y,we[i]=w,ds[x][y]=min(ds[x][y],w);
		for(int j=1,x;j<=T;j++) read(x),p[i][j]=x/100000.0;
		reverse(p[i],p[i]+T+1);
		for(int j=1;j<=T;j++) g[i][j]=g[i][j-1]+p[i][j-1];
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ds[i][j]=min(ds[i][j],ds[i][k]+ds[k][j]);
	for(int i=1;i<=m;i++) for(int j=0;j<=T;j++) g[i][j]=g[i][j]*(ds[tw[i]][n]+K)+we[i];
	//for(int i=1;i<=m;i++) for(int j=0;j<=T;j++) printf("%.5lf%c",p[i][j],j==T?'\n':' ');
	return cdq(0,T),printf("%.10lf\n",min(f[1][0],ds[1][n]+K+0.0)),0;
}
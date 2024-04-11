//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int n,K,X[100005],Y[100005],bz[200005][20];const double eps=1e-8,pi=acos(-1)*2;
struct node{double l,r;char operator<(node b) const {return l<b.l;}}s[200005];
inline double dis(int x,int y) {return sqrt(1.0*x*x+1.0*y*y);}
inline char chk(double ds)
{
	for(int i=1;i<=n;i++)
	{
		double at=atan2(Y[i],X[i]),ax=acos(ds/dis(X[i],Y[i]));
		s[i].l=at-ax,s[i].r=at+ax;if(s[i].l<0) s[i].l+=pi,s[i].r+=pi;
		s[i+n]=s[i],s[i+n].l+=pi,s[i+n].r+=pi;
	}
	int m=n<<1;sort(s+1,s+m+1),bz[m+1][0]=m+1;
	for(int i=m,c=m;i>=1;i--) {while(s[c].l>s[i].r) c--;bz[i][0]=c+1;}
	for(int j=1;j<20;j++) for(int i=1;i<=m+1;i++) bz[i][j]=bz[bz[i][j-1]][j-1];
	for(int i=1;i<=n;i++)
	{
		int id=i;for(int j=19;~j;j--) if((K>>j)&1) id=bz[id][j];
		if(id>=i+n) return 1;
	}
	return 0;
}
int main()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(X[i]),read(Y[i]);
	for(int i=1;i<=n;i++) if(abs(X[i])+abs(Y[i])==0) return puts("0"),0;
	double l=0,r=8e5;for(int i=1;i<=n;i++) r=min(r,dis(X[i],Y[i]));
	for(int k=40;k;k--) {double md=(l+r)/2;if(chk(md)) l=md;else r=md;}
	return printf("%.10lf\n",l),0;
}
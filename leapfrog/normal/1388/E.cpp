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
int n,L[2005],R[2005],Y[2005],at,bt;double b[4000005];const double eps=1e-9;
struct node{double ps;int vl;char operator<(node b) const {return ps<b.ps;}}a[4000005];
inline double chk(double vl)
{
	double mn=1e13,mx=-1e13;
	for(int i=1;i<=n;i++) mn=min(mn,L[i]-vl*Y[i]),mx=max(mx,R[i]-vl*Y[i]);
	return mx-mn;
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(L[i]),read(R[i]),read(Y[i]);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(Y[i]<Y[j])
		a[++at]=(node){1.0*(L[j]-R[i])/(Y[j]-Y[i])+eps,1},a[++at]=(node){1.0*(R[j]-L[i])/(Y[j]-Y[i])-eps,-1};
	sort(a+1,a+at+1);if(!at) a[++at]=(node){0,0};
	//for(int i=1;i<=at;i++) printf("%.10lf %d\n",a[i].ps,a[i].vl);
	for(int i=1,v=0;i<=at;v+=a[i++].vl) if(!v||!(v+a[i].vl)) b[++bt]=a[i].ps;
	//for(int i=1;i<=bt;i++) printf("%lf%c",b[i],i==bt?'\n':' ');
	int l=1,r=bt;while(l+2<r) {int md1=(l+r)>>1,md2=md1+1;if(chk(b[md1])<chk(b[md2])) r=md2;else l=md1;}
	double rs=1e13;for(int i=max(1,l-1);i<=min(r+2,bt);i++) rs=min(rs,chk(b[i]));
	return printf("%.10lf\n",rs),0;
}
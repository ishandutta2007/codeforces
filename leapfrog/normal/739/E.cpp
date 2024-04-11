//
#include<bits/stdc++.h>
using namespace std;const double eps=1e-10;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,A,B,s1,s2;double a[100005],b[100005],f;
inline void solve(double dx1,double dx2)
{
	s1=s2=0,f=0;for(int i=1;i<=n;i++)
	{
		double tf=f;int ts1=s1,ts2=s2;
		if(f<tf+a[i]-dx1+eps) f=tf+a[i]-dx1,s1=ts1+1,s2=ts2;
		if(f<tf+b[i]-dx2+eps) f=tf+b[i]-dx2,s1=ts1,s2=ts2+1;
		if(f<tf+a[i]-dx1+b[i]-dx2-a[i]*b[i]+eps) f=tf+a[i]-dx1+b[i]-dx2-a[i]*b[i],s1=ts1+1,s2=ts2+1;
	}
}
inline double wqs2(double dx1)
{
	double le=0,ri=1;
	while(le+eps<ri)
	{
		double md=(le+ri)/2;solve(dx1,md);
		if(s2==B) return md;else if(s2<B) ri=md;else le=md;
	}
	return (le+ri)/2;
}
inline pair<double,double> wqs1()
{
	double le=0,ri=1;
	while(le+eps<ri)
	{
		double md=(le+ri)/2,md2=wqs2(md);solve(md,md2);
		if(s1==A) return make_pair(md,md2);else if(s1<A) ri=md;else le=md;
	}
	return make_pair((le+ri)/2,wqs2((le+ri)/2));
}
int main()
{
	read(n),read(A),read(B);
	for(int i=1;i<=n;i++) scanf("%lf",a+i);
	for(int i=1;i<=n;i++) scanf("%lf",b+i);
	pair<double,double>tmp=wqs1();solve(tmp.first,tmp.second);
	return printf("%.8lf\n",f+tmp.first*A+tmp.second*B),0;
}
#include <bits/stdc++.h>
#define for(i,l,r) for(int i=(l);i<=(r);i++)
#define rof(i,l,r) for(int i=(r);i>=(l);i--)
using namespace std;
const int maxn=200000;
const double inf=1000000000;
double sy,a,b;
int n,q;
double l[maxn+5],r[maxn+5],sum[maxn+5];
double find(double xa,double ya,int xb,int yb)// ya>yb
{
	double x=xa;
	x-=ya*(xa-xb)/(ya-yb);
	return x;
}
int main()
{
	scanf("%lf%lf%lf",&sy,&a,&b);
	scanf("%d",&n);
	for(i,1,n) scanf("%lf%lf",&l[i],&r[i]);
	l[0]=r[0]=-inf;
	for(i,1,n+1) sum[i]=sum[i-1]+(r[i]-l[i]);
	l[n+1]=r[n+1]=inf;
	scanf("%d",&q);
	double x,y;
	for(tot,1,q)
	{
		scanf("%lf%lf",&x,&y);
		double L=find(x,y,a,sy);
		double R=find(x,y,b,sy);
		double Time=0;
		int pos1=lower_bound(l+1,l+n+1,L)-l;
		pos1--;
		if(r[pos1]>=L) Time+=r[pos1]-L;
		pos1++;
		int pos2=upper_bound(r+1,r+n+1,R)-r;
		if(l[pos2]<=R) Time+=R-l[pos2];
		pos2--;
		Time+=sum[pos2]-sum[pos1-1];
		Time*=(y-sy);
		Time/=y;
		printf("%.10lf\n",Time);
	}
	return 0;
}
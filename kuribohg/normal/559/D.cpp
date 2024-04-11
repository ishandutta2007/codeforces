#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long LL;
const int MAXN=200010;
LL gcd(LL a,LL b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
struct Point
{
	LL x,y;
	Point(){}
	Point(LL _x,LL _y):x(_x),y(_y){}
}P[MAXN];
LL Cross(const Point &p,const Point &q){return p.x*q.y-p.y*q.x;}
int n;
LL S;
double c[MAXN],p[MAXN];
double ans,Pow[MAXN];
int main()
{
	scanf("%d",&n);
	Pow[0]=1;
	for(int i=1;i<=n+1;i++) Pow[i]=Pow[i-1]*0.5;
	for(int i=0;i<n;i++) scanf("%I64d%I64d",&P[i].x,&P[i].y);
	for(int i=0;i<n;i++) p[i]=Cross(P[i],P[(i+1)%n]),S+=Cross(P[i],P[(i+1)%n]);
	for(int i=n;i<n+n;i++) p[i]=p[i-n];
	S=abs(S)+2;
	for(int i=0;i<n;i++) c[i]=gcd(abs(P[(i+1)%n].x-P[i].x),abs(P[(i+1)%n].y-P[i].y)),S-=gcd(abs(P[(i+1)%n].x-P[i].x),abs(P[(i+1)%n].y-P[i].y));
	for(int i=n;i<n+n;i++) c[i]=c[i-n];
	for(int i=1;i<n+n;i++) p[i]+=p[i-1],c[i]+=c[i-1];
	S>>=1;
	ans=S;
	for(int Len=2;Len<=min(60,n-1);Len++)
		for(int i=0;i<n;i++)
		{
			int j=(i+Len)%n;
			LL m=0;
			m=p[i+Len-1]-(i==0?0:p[i-1]);
			m+=Cross(P[j],P[i]);
			m=abs(m)+2;
			m-=c[i+Len-1]-(i==0?0:c[i-1]);
			m-=gcd(abs(P[j].x-P[i].x),abs(P[j].y-P[i].y));
			m>>=1;
			m+=gcd(abs(P[j].x-P[i].x),abs(P[j].y-P[i].y))-1;
			ans-=m*((Pow[Len+1]-Pow[n])/(1.0-Pow[n]-1.0*n*Pow[n]-1.0*n*(n-1)*Pow[n+1]));
		}
	printf("%.010lf\n",ans);
	return 0;
}
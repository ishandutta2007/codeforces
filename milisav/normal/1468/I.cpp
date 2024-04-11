#include <bits/stdc++.h>
using namespace std;
struct point {long long x,y;}; 
long long gcd(long long x,long long y)
{
	if(x<0) return gcd(-x,y);
	if(y<0) return gcd(x,-y);
	if(y==0) return x;
	return gcd(y,x%y);
}
double inter(long long x,point a,point b)
{
	return a.y+(x-a.x)*(b.y-a.y)/((double)b.x-(double)a.x);
}
int main()
{
	int n; long long a,b,c,d;
	cin>>n>>a>>b>>c>>d;
	if(n!=abs(a*d-b*c)) {printf("NO"); return 0;}
	printf("YES\n");
	printf("0 0\n");
	point p[4];
	p[0].x=0; p[0].y=0;
	p[1].x=a; p[1].y=b;
	p[2].x=a+c; p[2].y=b+d;
	p[3].x=c; p[3].y=d;
	long long dab=gcd(a,b),dcd=gcd(c,d);
	long long sa=a/dab,sb=b/dab,sc=c/dcd,sd=d/dcd;
	for(int i=1;i<dab;i++) printf("%lld %lld\n",i*sa,i*sb);
	for(int i=1;i<dcd;i++) printf("%lld %lld\n",i*sc,i*sd);
	for(int i=-2000000;i<=2000000;i++)
	{
		bool br=false;
		for(int j=0;j<4;j++) 
		{
			int next=(j+1)&3;
			if(p[j].x==i && p[next].x==i) br=true;
			//if(i==0) printf("%d %d %lld %lld\n",j,next,p[j].x,p[next].x);
		}
		if(br) continue;
		vector<double> pr;
		for(int j=0;j<4;j++) 
		{
			int next=(j+1)&3;
			if(p[j].x==i) pr.push_back((double)p[j].y);
			if(p[j].x<i && p[next].x>i) pr.push_back(inter(i,p[j],p[next]));
			if(p[j].x>i && p[next].x<i) pr.push_back(inter(i,p[next],p[j]));
		}
		if(pr.size()<2) continue;
		sort(pr.begin(),pr.end());
		for(int j=floor(pr[0])+1;j<ceil(pr[1]);j++) printf("%d %d\n",i,j);
	}
}
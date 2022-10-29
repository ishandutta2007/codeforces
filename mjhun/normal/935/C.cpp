#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int main(){
	int r,x1,y1,x2,y2;
	scanf("%d%d%d%d%d",&r,&x1,&y1,&x2,&y2);
	double xr,yr,rr;
	if(x1==x2&&y1==y2)xr=x1+r/2.,yr=y1,rr=r/2.;
	else if(1LL*(x1-x2)*(x1-x2)+1LL*(y1-y2)*(y1-y2)<1LL*r*r){
		double d=hypot(x2-x1,y2-y1);rr=(r+d)/2;
		double dx=x1-x2,dy=y1-y2;double t=hypot(dx,dy);dx/=t;dy/=t;
		xr=x2+dx*rr;yr=y2+dy*rr;
	}
	else xr=x1,yr=y1,rr=r;
	printf("%.12lf %.12lf %.12lf\n",xr,yr,rr);
	return 0;
}
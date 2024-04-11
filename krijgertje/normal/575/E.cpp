#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int X=100000;
const int Y=100000;
const int MAXF=100000;
const int MAXP=8*MAXF;
const int MAXH=MAXP;

typedef struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} } P;
bool operator<(const P &a,const P &b) { if(a.x!=b.x) return a.x<b.x; return a.y<b.y; }
const P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
const ll operator^(const P &a,const P &b) { return (ll)a.x*b.y-(ll)a.y*b.x; }

int nf;
P f[MAXF]; int  fv[MAXF];

int np;
P p[MAXP];

int nh;
P h[MAXP+1];

int side(const P &a,const P &b,const P &c) { ll res=(b-a)^(c-a); return res<0?-1:res>0?+1:0; }
void calchull() {
	sort(p,p+np);
	nh=0;
	REP(i,np) {
		while(nh>=2&&side(h[nh-2],h[nh-1],p[i])<=0) --nh;
		h[nh++]=p[i];
	}
	int tmp=nh;
	for(int i=np-1;i>=0;--i) {
		while(nh-tmp+1>=2&&side(h[nh-2],h[nh-1],p[i])<=0) --nh;
		h[nh++]=p[i];
	}
	--nh;
}

double det(double aa,double ab,double ac,double ba,double bb,double bc,double ca,double cb,double cc) {
	return aa*bb*cc+ab*bc*ca+ac*ba*cb-ac*bb*ca-aa*bc*cb-ab*ba*cc;
}

void run() {
	scanf("%d",&nf);
	REP(i,nf) scanf("%d%d%d",&f[i].x,&f[i].y,&fv[i]);

	np=0;
	REP(i,nf) {
		if(fv[i]==0) { p[np++]=f[i]; continue; }

		if(f[i].x+f[i].y<=fv[i]) p[np++]=P(0,0);
		else if(f[i].y<fv[i]) p[np++]=P(f[i].x+f[i].y-fv[i],0);
		else p[np++]=P(f[i].x,f[i].y-fv[i]);
		if(X-f[i].x+f[i].y<=fv[i]) p[np++]=P(X,0);
		else if(f[i].y<fv[i]) p[np++]=P(f[i].x+fv[i]-f[i].y,0);

		if(f[i].x+Y-f[i].y<=fv[i]) p[np++]=P(0,Y);
		else if(Y-f[i].y<fv[i]) p[np++]=P(f[i].x+Y-f[i].y-fv[i],Y);
		else p[np++]=P(f[i].x,f[i].y+fv[i]);
		if(X-f[i].x+Y-f[i].y<=fv[i]) p[np++]=P(X,Y);
		else if(Y-f[i].y<fv[i]) p[np++]=P(f[i].x+fv[i]-Y+f[i].y,Y);

		if(0<f[i].x) {
			if(f[i].x+f[i].y<=fv[i]) /*skip*/;
			else if(f[i].x<fv[i]) p[np++]=P(0,f[i].y+f[i].x-fv[i]);
			else if(0<f[i].y&&f[i].y<Y) p[np++]=P(f[i].x-fv[i],f[i].y);
			if(f[i].x+Y-f[i].y<=fv[i]) /*skip*/;
			else if(f[i].x<fv[i]) p[np++]=P(0,f[i].y+fv[i]-f[i].x);
		}
		if(f[i].x<X) {
			if(X-f[i].x+f[i].y<=fv[i]) /*skip*/;
			else if(X-f[i].x<fv[i]) p[np++]=P(X,f[i].y+X-f[i].x-fv[i]);
			else if(0<f[i].y&&f[i].y<Y) p[np++]=P(f[i].x+fv[i],f[i].y);
			if(X-f[i].x+Y-f[i].y<=fv[i]) /*skip*/;
			else if(X-f[i].x<fv[i]) p[np++]=P(X,f[i].y+fv[i]-X+f[i].x);
		}
	}
	calchull();
	//printf("p\n"); REP(i,np) printf("(%d,%d)\n",p[i].x,p[i].y);
	//printf("h\n"); REP(i,nh) printf("(%d,%d)\n",h[i].x,h[i].y);

	double best=0; int ret[3];
	REP(p,nh) {
		int q=(p+1)%nh,r=(q+1)%nh;
		int xp=h[p].x,yp=h[p].y; ll xxp=(ll)xp*xp,yyp=(ll)yp*yp;
		int xq=h[q].x,yq=h[q].y; ll xxq=(ll)xq*xq,yyq=(ll)yq*yq;
		int xr=h[r].x,yr=h[r].y; ll xxr=(ll)xr*xr,yyr=(ll)yr*yr;
		double a=+det(xp,yp,1,xq,yq,1,xr,yr,1);
		double d=-det(xxp+yyp,yp,1,xxq+yyq,yq,1,xxr+yyr,yr,1);
		double e=+det(xxp+yyp,xp,1,xxq+yyq,xq,1,xxr+yyr,xr,1);
		double f=-det(xxp+yyp,xp,yp,xxq+yyq,xq,yq,xxr+yyr,xr,yr);
		double rr=(d*d+e*e)/(4*a*a)-f/a;
		//printf("(%d,%d)-(%d,%d)-(%d,%d) -> %lf [%lf,%lf]\n",xp,yp,xq,yq,xr,yr,rr,-d/(2*a),-e/(2*a));
		if(rr>best) best=rr,ret[0]=p,ret[1]=q,ret[2]=r;
	}
	REP(i,3) printf("%d %d\n",h[ret[i]].x,h[ret[i]].y);

}

int main() {
	run();
	return 0;
}
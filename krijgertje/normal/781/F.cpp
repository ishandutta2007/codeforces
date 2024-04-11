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

const int MAXN=100000;
const int MAXM=100000;
const double eps=1e-9;

typedef struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} } P;
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
int len2(const P &a) { return a.x*a.x+a.y*a.y; }
int sgn(int x) { return x<0?-1:x>0?+1:0; }
typedef struct Q { double a,b,c; double tmn,tmx; Q() {} Q(double a,double b,double c,double tmn,double tmx):a(a),b(b),c(c),tmn(tmn),tmx(tmx) {} } Q;


int n,m;
P p[MAXN+1];
P dir[MAXN];
vector<Q> q[MAXM];

double slen[MAXN],totlen;
int at[MAXM]; double dt[MAXM];

double t[4]; int nt;
pair<double,int> e[6*(MAXN+MAXM)]; int ne;

bool ok(double y) {
	//printf("testing %.9lf\n",y);
	ne=0;
	REP(i,m) REPSZ(j,q[i]) {
		double a=q[i][j].a,b=q[i][j].b,c=q[i][j].c-y,dd=b*b-4*a*c,tmn=q[i][j].tmn,tmx=q[i][j].tmx;
		nt=0; t[nt++]=tmn-tmn; t[nt++]=tmx-tmn;
		if(a==0) {
			if(b!=0) {
				double t1=-c/b;
				if(0<=t1&&t1<=tmx-tmn) t[nt++]=t1;
			}
		} else if(dd>=0) {
			double d=sqrt(dd),t1=(-b-d)/(2*a),t2=(-b+d)/(2*a);
			if(0<=t1&&t1<=tmx-tmn) t[nt++]=t1;
			if(0<=t2&&t2<=tmx-tmn) t[nt++]=t2;
		}
		sort(t,t+nt);
		REP(j,nt-1) { double tt=(t[j]+t[j+1])/2; bool ok=a*tt*tt+b*tt+c<=0; if(ok) e[ne++]=MP(tmn+t[j],+1),e[ne++]=MP(tmn+t[j+1],-1); }
	}
	sort(e,e+ne); int cur=0;
	//REP(i,ne) printf("%lf: %d\n",e[i].first,e[i].second);
	for(int at=0,to=at;at<ne;at=to) {
		while(e[to].first==e[at].first) cur+=e[to++].second;
		if(cur>=m) return true;
	}
	return false;
}


void run() {
	scanf("%d%d",&n,&m); REP(i,n) scanf("%d%d",&p[i].x,&p[i].y); p[n]=p[0];
	//srand(time(NULL)); 
	//n=MAXN,m=2; REP(i,n) p[i].x=rand()%2001-1000,p[i].y=rand()%2001-1000; REP(i,n) if(rand()%2==0) p[i].x=p[(i+n-1)%n].x; else p[i].y=p[(i+n-1)%n].y;
	//n=MAXN,m=2; REP(i,n) p[i].x=i%4==1||i%4==2?-1000:+1000,p[i].y=i%4==0||i%4==1?-1000:+1000; p[n]=p[0];
	//REP(i,n/2) p[i].x=rand()%2001-1000,p[i].y=rand()%2001-1000; REP(i,n) if(rand()%2==0) p[i].x=p[(i+n-1)%n].x; else p[i].y=p[(i+n-1)%n].y;

	REP(i,n) slen[i]=sqrt(1.0*len2(p[i+1]-p[i]));
	REP(i,n) dir[i].x=sgn(p[i+1].x-p[i].x),dir[i].y=sgn(p[i+1].y-p[i].y);
	totlen=0; REP(i,n) totlen+=slen[i];
	at[0]=0; dt[0]=0;
	FOR(i,1,m) {
		at[i]=at[i-1],dt[i]=dt[i-1]+totlen/m;
		while(dt[i]>=slen[at[i]]) { dt[i]-=slen[at[i]]; ++at[i]; if(at[i]==n) at[i]=0; }
	}
	//REP(i,n) printf("%d %d %lf\n",p[i].x,p[i].y,slen[i]);
	//REP(i,m) printf("%d: at=%d dt=%.9lf\n",i,at[i],dt[i]);

	REP(i,m) {
		int j=(i+1)%m;
		int ii=at[i],jj=at[j]; double dti=dt[i],dtj=dt[j],t=0,remi=slen[ii]-dti,remj=slen[jj]-dtj;
		while(t+eps<totlen/m) {
			double a=0,b=0,c=0;
			double xa=dir[ii].x-dir[jj].x,xb=p[ii].x+dti*dir[ii].x-p[jj].x-dtj*dir[jj].x;
			a+=xa*xa,b+=2*xa*xb,c+=xb*xb;
			double ya=dir[ii].y-dir[jj].y,yb=p[ii].y+dti*dir[ii].y-p[jj].y-dtj*dir[jj].y;
			a+=ya*ya,b+=2*ya*yb,c+=yb*yb;
			//printf("ii,jj=%d,%d dt=%lf,%lf rem=%lf,%lf\n",ii,jj,dti,dtj,remi,remj);
			double tmx=min(totlen/m-t,min(remi,remj)); assert(tmx>0);
			//printf("%.9lf*t^2+%.9lf*t+%.9lf (%lf..%lf)\n",a,b,c,t,t+tmx);
			q[i].PB(Q(a,b,c,t,t+tmx));
			remi-=tmx; remj-=tmx; while(remi<=0) dti-=slen[ii],ii=(ii+1)%n,remi+=slen[ii]; while(remj<=0) dtj-=slen[jj],jj=(jj+1)%n,remj+=slen[jj]; t+=tmx; dti+=tmx; dtj+=tmx;
		}
		//puts("");
	}

	double xmn=p[0].x,xmx=p[0].x,ymn=p[0].y,ymx=p[0].y; FOR(i,1,n) { if(p[i].x<xmn) xmn=p[i].x; if(p[i].x>xmx) xmx=p[i].x; if(p[i].y<ymn) ymn=p[i].y; if(p[i].y>ymx) ymx=p[i].y; }
	double l=0,h=(xmx-xmn)*(xmx-xmn)+(ymx-ymn)*(ymx-ymn);
	REP(i,100) {
		double m=l+(h-l)/2;
		if(ok(m)) h=m; else l=m;
	}
	printf("%.9lf\n",sqrt(h));
}

int main() {
	run();
	return 0;
}
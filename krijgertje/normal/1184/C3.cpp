#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
#include <chrono>
#include <random>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXRING=4;
const int MAXEACH=1000;
const int MAXN=MAXRING*MAXEACH;
const double M_PI=acos(-1.0);
struct P { double x,y; P() {} P(double x,double y):x(x),y(y) {} };
struct Circle { P center; double r; Circle() {} Circle(P center,double r):center(center),r(r) {} };

double dist(const P &a,const P &b) { double dx=a.x-b.x,dy=a.y-b.y; return sqrt(dx*dx+dy*dy); }

int nring,neach,n;
P p[MAXN];

std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());

bool makecircle(const P &a,const P &b,const P &c,P &center,double &r) {
	double denx=2*(a.y*(c.x-b.x)+b.y*(a.x-c.x)+c.y*(b.x-a.x));
	double deny=2*(a.x*(c.y-b.y)+b.x*(a.y-c.y)+c.x*(b.y-a.y));
	if(fabs(denx)<1e-3||fabs(deny)<1e-3) return false;
	double cx2=c.x*c.x,bx2=b.x*b.x,cy2=c.y*c.y,by2=b.y*b.y,ax2=a.x*a.x,ay2=a.y*a.y;
	double numx=a.y*(cx2-bx2+cy2-by2)+b.y*(ax2-cx2+ay2-cy2)+c.y*(bx2-ax2+by2-ay2);
	double numy=a.x*(cx2-bx2+cy2-by2)+b.x*(ax2-cx2+ay2-cy2)+c.x*(bx2-ax2+by2-ay2);
	center=P(numx/denx,numy/deny); r=(dist(a,center)+dist(b,center)+dist(c,center))/3;
	return true;
}

vector<Circle> cans;
vector<pair<Circle,double>> opt;

double dist(const Circle &a,const Circle &b) {
	double d=dist(a.center,b.center);
	vector<double> v(4); REP(i,4) { double cur=d; if((i&1)==0) cur+=a.r; else cur-=a.r; if((i&2)==0) cur+=b.r; else cur-=b.r; v[i]=abs(cur); }
	double ret=0; REP(i,4) REP(diff,2) { int j=i^(1<<diff); ret=max(ret,min(v[i],v[j])); } return ret;
}

double calc(const Circle &c,const P &p) { return fabs(dist(c.center,p)-c.r); }
void addopt(Circle c) {
	vector<double> cur; REP(j,n) cur.PB(calc(c,p[j])); sort(cur.begin(),cur.end()); double sum=0; REP(j,neach) sum+=cur[j]; sum/=neach; //if(ismissing) printf("%lf\n",sum);
	if(SZ(opt)<nring) { opt.PB(MP(c,sum)); /*printf("%lf\n",sum);*/ return; }
	//bool ismissing=false; REPSZ(i,cans) { bool have=false; REPSZ(j,opt) if(dist(cans[i],opt[j].first)<100000) have=true; if(!have&&dist(cans[i],c)<100000) ismissing=true; }
	double bestval=1e200; int bestreplace=-1;
	REPSZ(replace,opt) {
		double before=0,after=0;
		REP(j,n) {
			double have=1e200; REPSZ(i,opt) if(i!=replace) have=min(have,calc(opt[i].first,p[j]));
			before+=min(have,calc(opt[replace].first,p[j])); after+=min(have,calc(c,p[j]));
		}
		//if(ismissing) printf("before=%lf after=%lf\n",before,after);
		if(after<before&&after<bestval) bestval=after,bestreplace=replace;
	}
	if(bestreplace!=-1) {
		//printf("replacing %lf with %lf\n",opt[bestreplace].second,sum);
		opt[bestreplace]=MP(c,sum);
	} else {
		//if(ismissing) printf("skipping %lf\n",sum);
	}
}

void solve() {
	vector<pair<Circle,double>> bestopt; double bestval=1e200;
	REP(rep,10) {
		opt.clear();
		REP(i,1000) {
			int a=rnd()%n,b=rnd()%n,c=rnd()%n; if(b==a||c==a||c==b) continue;
			P center; double r; if(!makecircle(p[a],p[b],p[c],center,r)) continue;
			addopt(Circle(center,r));
			//printf("(%lf,%lf) rad=%lf sum=%lf\n",center.x,center.y,r,sum);
		}
		assert(SZ(opt)==nring);
		double curval=0; REP(j,n) { double me=1e200; REPSZ(i,opt) me=min(me,calc(opt[i].first,p[j])); curval+=me; }
		if(curval<bestval) bestval=curval,bestopt=opt;
	}
	opt=bestopt;
}

void run() {
	scanf("%d%d",&nring,&neach); n=nring*neach;
	REP(i,n) scanf("%lf%lf",&p[i].x,&p[i].y);
	solve();
	REPSZ(i,opt) printf("%lf %lf %lf\n",opt[i].first.center.x,opt[i].first.center.y,opt[i].first.r);
}

void stress() {
	std::mt19937 genrnd(12312);
	const double omx=1000000;
	std::uniform_real_distribution<double> gensquare(-omx, omx);
	std::uniform_real_distribution<double> genradius(250000, 750000);
	std::uniform_real_distribution<double> genang(0, 2*M_PI);
	std::uniform_real_distribution<double> genmlt(0.9,1.1);
	int mxring=4;
	REP(rep,100) {
		nring=genrnd()%mxring+1;
		neach=genrnd()%(1000-100+1)+100;
		n=nring*neach;
		vector<Circle> c(nring);
		REP(i,nring) {
			while(true) { 
				double cx=gensquare(genrnd),cy=gensquare(genrnd); if(cx*cx+cy*cy>omx*omx) continue; 
				c[i].center=P(cx,cy); 
				c[i].r=genradius(genrnd);
				//printf("testing (%lf,%lf,%lf)\n",c[i].center.x,c[i].center.y,c[i].r);
				bool ok=true; REP(j,i) if(dist(c[i],c[j])<600000) ok=false; if(!ok) continue;
				break;
			}

			REP(j,neach) { 
				double ang=genang(genrnd),mlt=genmlt(genrnd);
				double x=floor(c[i].center.x+mlt*c[i].r*cos(ang)+.5),y=floor(c[i].center.y+mlt*c[i].r*sin(ang)+.5);
				p[i*neach+j]=P(x,y);
			}
		}
		shuffle(p,p+n,genrnd);
		cans=c;
		//if(rep!=29) continue;
		rnd=genrnd;
		solve();
		vector<int> perm(nring); REP(i,nring) perm[i]=i;
		double best=1e200; vector<int> bestperm;
		do {
			double cur=0; REP(i,nring) cur=max(cur,dist(c[i],opt[perm[i]].first)); if(cur<best) best=cur,bestperm=perm;
		} while(next_permutation(perm.begin(),perm.end()));
		printf("want:"); REP(i,nring) printf(" (x-%.0lf)^2+(y-%.0lf)^2=%.0lf^2",c[i].center.x,c[i].center.y,c[i].r); puts("");
		printf("have:"); REP(i,nring) printf(" (x-%.0lf)^2+(y-%.0lf)^2=%.0lf^2",opt[bestperm[i]].first.center.x,opt[bestperm[i]].first.center.y,opt[bestperm[i]].first.r); puts("");
		printf("rep=%d best=%lf\n",rep,best);
		if(best>400000) return;

	}
}

int main() {
	run();
	//stress();
	return 0;
}


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
const double eps=1e-9;
typedef struct E { double x,y; int idx; } E;
bool operator<(const E &a,const E &b) {
	bool apos=a.y>=eps||a.y>-eps&&a.x>0;
	bool bpos=b.y>=eps||b.y>-eps&&b.x>0;
	if(apos!=bpos) return apos; return apos?a.x>b.x:a.x<b.x;
}

int n,bx;
int x[MAXN],y[MAXN]; double d[MAXN],r[MAXN];
E e[2*MAXN]; int ne;
int at[MAXN];
int bt[2*MAXN+1];
void bmod(int idx,int by) { /*printf("mod(%d,%d)\n",idx,by);*/ ++idx; while(idx<=ne) { bt[idx]+=by; idx+=idx&-idx; } }
int bget(int idx) { /*printf("get(%d)=",idx);*/ int ret=0; ++idx; while(idx>=1) { ret+=bt[idx]; idx-=idx&-idx; } /*printf("%d\n",ret);*/ return ret; } 

bool test(double R) {
	//printf("%.9lf: (%.9lf %.9lf | %.9lf %.9lf)\n",R,r[0],d[0],r[1],d[1]);
	ne=0;
	REP(i,n) {
		if(R>=r[i]+d[i]) return true;
		if(r[i]>R+d[i]||d[i]>R+r[i]) continue;
		double a=(d[i]*d[i]+R*R-r[i]*r[i])/(2*d[i]),b=sqrt(R*R-a*a);
		double dx=x[i]-bx,dy=y[i];
		double x1=bx+a*dx/d[i]-b*dy/d[i],y1=a*dy/d[i]+b*dx/d[i];
		double x2=bx+a*dx/d[i]+b*dy/d[i],y2=a*dy/d[i]-b*dx/d[i];
		//printf("(%.4lf,%.4lf) (%.4lf,%.4lf) [%.4lf,%.4lf | %.4lf,%.4lf]\n",x1,y1,x2,y2,a,b,dx,dy);
		//printf("%.9lf vs %.9lf, %.9lf vs %.9lf\n",sqrt((x1-x[i])*(x1-x[i])+(y1-y[i])*(y1-y[i]))-r[i],sqrt((x1-bx)*(x1-bx)+y1*y1)-R,sqrt((x2-x[i])*(x2-x[i])+(y2-y[i])*(y2-y[i]))-r[i],sqrt((x2-bx)*(x2-bx)+y2*y2)-R);
		e[ne].x=x1-bx,e[ne].y=y1,e[ne].idx=i,++ne; e[ne].x=x2-bx,e[ne].y=y2,e[ne].idx=i,++ne;
	}
	sort(e,e+ne);
	//REP(i,ne) printf(" %d",e[i].idx); printf(" ?\n");
	memset(at,-1,sizeof(at)); memset(bt,0,sizeof(bt)); int cnt=0;
	REP(i,ne) {
		int idx=e[i].idx;
		if(at[idx]==-1) { at[idx]=i; bmod(i,+1); ++cnt; }
		else { --cnt; bmod(at[idx],-1); if(bget(at[idx])!=cnt) return true; at[idx]=-1; }
	}
	return false;
}
void dtest(double R) { printf("%lf=%d\n",R,test(R)); }

void run() {
	scanf("%d%d",&n,&bx);
	REP(i,n) scanf("%d%d",&x[i],&y[i]);
	REP(i,n) d[i]=sqrt(1.0*(x[i]-bx)*(x[i]-bx)+1.0*y[i]*y[i]);
	REP(i,n) r[i]=sqrt(1.0*(x[i]+bx)*(x[i]+bx)+1.0*y[i]*y[i]);

	//REPE(i,12) dtest(9+i*.1);
	//dtest(9.1);

	double l=0,h=2*bx;
	REP(i,100) { double m=l+(h-l)/2; if(!test(m)) l=m; else h=m; }
	printf("%.9lf\n",l+(h-l)/2);
}

int main() {
	run();
	return 0;
}
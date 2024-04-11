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

const int MAXN=100000;
const int MAXLG=16;
const double MPI=acos(-1.0);
struct P { int x,y; };
double len(const P &a) { return sqrt(1.0*a.x*a.x+1.0*a.y*a.y); }
struct R { double l,r; R() {} R(double l,double r):l(l),r(r) {} };
bool operator<(const R &a,const R &b) { return a.r<b.r; }

int n,lim;
P p[MAXN];

R ranges[2*MAXN];
int cnt[MAXN][MAXLG+1];

bool can(double r) {
	//printf("testing %lf\n",r);
	REP(i,n) {
		double d=len(p[i]); if(d<r) return false; if(d==0) return r==0;
		double alpha=atan2(p[i].y,p[i].x),beta=acos(r/d);
		ranges[i]=R(alpha-beta,alpha+beta);
	}
	REP(i,n) {
		while(ranges[i].r<0) ranges[i].l+=2*MPI,ranges[i].r+=2*MPI; 
		while(ranges[i].r>=2*MPI) ranges[i].l-=2*MPI,ranges[i].r-=2*MPI;
	}
	sort(ranges,ranges+n);
	REP(i,n) ranges[n+i]=R(ranges[i].l+2*MPI,ranges[i].r+2*MPI);
	//printf("ranges:"); REP(i,2*n) printf(" [%.2lf..%.2lf]",ranges[i].l,ranges[i].r); puts("");
	int at=0;
	REP(i,n) {
		while(at<2*n&&ranges[i].r>=ranges[at].l) ++at; assert(at<2*n);
		cnt[i][0]=at-i;
	}
	//printf("cnt:"); REP(i,n) printf(" %d",cnt[i][0]); puts("");
	REP(k,MAXLG) REP(i,n) cnt[i][k+1]=min(n,cnt[i][k]+cnt[(i+cnt[i][k])%n][k]);
	REP(i,n) { int cur=0; REPE(k,MAXLG) if(lim&(1<<k)) cur=min(n,cur+cnt[(i+cur)%n][k]); if(cur>=n) return true; }
	return false;
}

double solve() {
	double closest=1e200;
	REP(i,n) { double dist=len(p[i]); closest=min(closest,dist); }
	double lo=0,hi=closest;
	REP(rep,100) {
		if(fabs(hi-lo)<1e-12) break;
		double mi=lo+(hi-lo)/2;
		if(can(mi)) lo=mi; else hi=mi;
	}
	return lo;
}

void run() {
	scanf("%d%d",&n,&lim);
	REP(i,n) scanf("%d%d",&p[i].x,&p[i].y);
	printf("%.15lf\n",solve());

}

int main() {
	run();
	return 0;
}
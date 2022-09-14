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
#include <list>
#include <cassert>
#include <climits>
#include <cstring>
#include <stack>
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
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;

typedef struct Ball { double x,v,m; int ind; } Ball;
bool operator<(const Ball &a,const Ball &b) { return a.x<b.x; }

void run() {
	int n,tend; scanf("%d%d",&n,&tend);
	vector<Ball> b(n); REP(i,n) { scanf("%lf%lf%lf",&b[i].x,&b[i].v,&b[i].m); b[i].ind=i; }
	sort(b.begin(),b.end());
//	REP(i,n) printf("(%lf,%lf,%lf)",b[i].x,b[i].v,b[i].m); puts("");
	
	double t=0;
	set<pair<double,int> > events;
	vector<double> myevent(n,-1);
	#define CHECK(i) if(b[i].v>b[(i)+1].v) { double tt=t+(b[(i)+1].x-b[i].x)/(b[i].v-b[(i)+1].v); /*printf("\t%lf\n",tt);*/ events.insert(MP(tt,i)); myevent[i]=tt; }
	REP(i,n-1) if(b[i].v>b[i+1].v) CHECK(i);
	events.insert(MP(tend,-1));
	while(SZ(events)>0) {
		double nt=events.begin()->first; int at=events.begin()->second; events.erase(events.begin());
//		printf("t=%lf at=%d\n",nt,at);
		REP(i,n) b[i].x+=(nt-t)*b[i].v; t=nt;
		if(at==-1) break; else myevent[at]=-1;
		double v1=((b[at].m-b[at+1].m)*b[at].v+2*b[at+1].m*b[at+1].v)/(b[at].m+b[at+1].m);
		double v2=((b[at+1].m-b[at].m)*b[at+1].v+2*b[at].m*b[at].v)/(b[at].m+b[at+1].m);
		assert(v1<v2);
		b[at].v=v1; b[at+1].v=v2;
		if(at-1>=0) {
			if(myevent[at-1]!=-1) events.erase(MP(myevent[at-1],at-1)),myevent[at-1]=-1;
			CHECK(at-1);
		}
		if(at+2<n) {
			if(myevent[at+1]!=-1) events.erase(MP(myevent[at+1],at+1)),myevent[at+1]=-1;
			CHECK(at+1);
		}
	}
	vector<double> ret(n); REP(i,n) ret[b[i].ind]=b[i].x;
	REP(i,n) printf("%.9lf\n",ret[i]);
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}
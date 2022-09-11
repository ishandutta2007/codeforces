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

struct R { 
	ll lx,hx,ly,hy; R(ll lx,ll hx,ll ly,ll hy):lx(lx),hx(hx),ly(ly),hy(hy) {} 
	double area() { return 1.0*(hx-lx+1)*(hy-ly+1); } 
	double area(ll chx) { return 1.0*(chx-lx+1)*(hy-ly+1); } 
	double area3(ll qx,ll qy) { if(lx>qx||ly>qy) return 0; return 1.0*(min(hx,qx)-lx+1)*(min(hy,qy)-ly+1); }
};

vector<R> opt;

pair<ll,ll> calcmove() {
	ll hx=opt.back().hx,hy=opt.back().hy; pair<ll,ll> ret=MP(hx,hy);
	double l=0,h=1.0;
	double area=0; REPSZ(i,opt) area+=opt[i].area();
	REP(rep,20) {
		double m=l+(h-l)/2;
		ll qx=-1,qy=-1;
		{
			double have=0;
			for(int i=SZ(opt)-1;i>=0;--i) {
				double cur=opt[i].area();
				if(have+cur>=m*area) { double frac=(m*area-have)/cur; ll dx=(ll)ceil(frac*(opt[i].hx-opt[i].lx+1)); qx=opt[i].hx-dx+1; break; }
				have+=cur;
			}
			assert(qx!=-1);
		}
		{
			double have=0;
			REPSZ(i,opt) {
				double cur=opt[i].area(hx);
				if(have+cur>=m*area) { double frac=(m*area-have)/cur; ll dy=(ll)ceil(frac*(opt[i].hy-opt[i].ly+1)); qy=opt[i].hy-dy+1; break; }
				have+=cur;
			}
			assert(qy!=-1);
		}
		{
			double have=0;
			REPSZ(i,opt) have+=opt[i].area3(qx,qy);
			double frac=have/area; 
			//printf("\t%.3lf -> (%lld,%lld) -> %.3lf [area=%le]\n",m,qx,qy,frac,area);
			if(frac>=m) l=m,ret=MP(qx,qy); else h=m;
		}
	}
	//printf("\t%le frac=%lf\n",area,l);
	return ret;
}

bool local=false; pair<ll,ll> localans; int nq;
int query(pair<ll,ll> move) {
	++nq;
	if(local) {
		if(localans==move) return 0;
		vector<int> poss;
		if(move.first<localans.first) poss.PB(1);
		if(move.second<localans.second) poss.PB(2);
		if(move.first>localans.first||move.second>localans.second) poss.PB(3);
		assert(SZ(poss)!=0); int idx=rand()%SZ(poss); return poss[idx];
	} else {
		printf("%lld %lld\n",move.first,move.second); fflush(stdout);
		int ret; scanf("%d",&ret); return ret;
	}
}

void solve(ll lim) {
	opt.clear(); opt.PB(R(1,lim,1,lim));
	while(SZ(opt)!=0) {
		//printf("opt:"); REPSZ(i,opt) printf(" [%lld..%lld]*[%lld..%lld]\n",opt[i].lx,opt[i].hx,opt[i].ly,opt[i].hy); puts("");
		FORSZ(i,1,opt) assert(opt[i-1].hx<opt[i].lx);
		pair<ll,ll> move=calcmove();
		int ans=query(MP(lim-move.first+1,lim-move.second+1));
		//printf("ans=%d\n",ans);
		if(ans==0) break;
		vector<R> nopt;
		if(ans==1) REPSZ(i,opt) if(opt[i].lx<move.first) nopt.PB(R(opt[i].lx,min(opt[i].hx,move.first-1),opt[i].ly,opt[i].hy));
		if(ans==2) REPSZ(i,opt) if(opt[i].ly<move.second) nopt.PB(R(opt[i].lx,opt[i].hx,opt[i].ly,min(opt[i].hy,move.second-1)));
		if(ans==3) REPSZ(i,opt) {
			if(opt[i].lx>move.first||opt[i].ly>move.second) { nopt.PB(opt[i]); continue; }
			if(opt[i].hy>move.second&&opt[i].lx<=move.first) nopt.PB(R(opt[i].lx,min(opt[i].hx,move.first),move.second+1,opt[i].hy));
			if(opt[i].hx>move.first) nopt.PB(R(max(move.first+1,opt[i].lx),opt[i].hx,opt[i].ly,opt[i].hy));
		}
		opt=nopt;
	}
}

void run() {
	ll lim; scanf("%lld",&lim); 
	solve(lim);
}

ll myrand() { return rand()%1000*(ll)1000000*1000000000+rand()%1000*(ll)1000*1000000000+rand()%1000*(ll)1000000000+rand()%1000*1000000+rand()%1000*1000+rand()%1000+1; }

void stress() {
	int mxq=0;
	REP(rep,10000) {
		ll lim=(ll)1000000000*1000000000;
		local=true; localans=MP(myrand(),myrand()); nq=0; int seed=rand()%1000*1000+rand()%1000; srand(seed);
		//printf("lim=%lld localans=(%lld,%lld) seed=%d\n",lim,localans.first,localans.second,seed);
		solve(lim);
		if(nq>mxq) mxq=nq,printf("%d\n",nq);
	}
}

void test() {
	ll lim=(ll)1000000000000000000LL;
	local=true; localans=MP(477659980146085779LL,521095928229275533LL); nq=0; srand(918951);
	printf("lim=%lld localans=(%lld,%lld)\n",lim,localans.first,localans.second);
	solve(lim);
	printf("%d\n",nq);
}

int main() {
	run();
	//stress();
	//test();
	return 0;
}
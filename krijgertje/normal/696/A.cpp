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

const int MAXQ=1000;
const int MAXBIT=59;
const int MAXE=MAXQ*MAXBIT*2;
typedef struct E { ll u; int t; } E;
bool operator<(const E &a,const E &b) { if(a.u!=b.u) return a.u<b.u; return a.t<b.t; }

int nq;
int qw[MAXQ];
ll ret[MAXQ];
E e[MAXE]; int ne;

int lg2(ll u) { int ret=0; while(u>=(1LL<<(ret+1))) ++ret; return ret; }
void addpath(ll u,ll v,int t) {
	int ud=lg2(u),vd=lg2(v);
	while(u!=v) {
		if(ud>=vd) {
			e[ne].u=u,e[ne].t=t,++ne;
			u/=2,--ud;
		} else {
			e[ne].u=v,e[ne].t=t,++ne;
			v/=2,--vd;
		}
	}
}

void run() {
	scanf("%d",&nq);
	ne=0;
	REP(i,nq) {
		int type; ll u,v; scanf("%d%lld%lld",&type,&u,&v); addpath(u,v,i);
		if(type==1) scanf("%d",&qw[i]); else qw[i]=-1,ret[i]=0;
	}
	sort(e,e+ne);
	//REP(i,ne) printf("%lld: %d (%d)\n",e[i].u,qw[e[i].t],e[i].t);
	for(int at=0,to=at;at<ne;at=to) {
		while(to<ne&&e[at].u==e[to].u) ++to;
		//printf("%d..%d\n",at,to);
		ll cur=0;
		FOR(i,at,to) {
			int t=e[i].t;
			if(qw[t]==-1) ret[t]+=cur; else cur+=qw[t];
		}
	}
	REP(i,nq) if(qw[i]==-1) printf("%lld\n",ret[i]);
}

int main() {
	run();
	return 0;
}
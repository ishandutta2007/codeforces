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
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;

typedef struct Emp { int cost,t,get,ind; } Emp;
bool operator<(const Emp &a,const Emp &b) { return a.t<b.t; }

bool active[1440];
int activetimebefore[1441];
int activetimeperday;

int convert(int d,int t) {
	return (d-1)*activetimeperday+activetimebefore[t];
}

void printt(int t) {
	int d=t/activetimeperday+1; t%=activetimeperday;
	printf("%d ",d);
	int tt=0; while(!active[tt]) ++tt; REP(i,t) { ++tt; while(!active[tt]) ++tt; }
	printf("%02d:%02d",tt/60,tt%60);
}

typedef struct X { int t,at,have; } X;
bool operator<(const X &a,const X &b) { if(a.at!=b.at) return a.at>b.at; if(a.t!=b.t) return a.t>b.t; }

void run() {
	int nsubj,nemp,ndays; scanf("%d%d%d",&nsubj,&nemp,&ndays);
	vector<string> subj(nsubj); REP(i,nsubj) cin>>subj[i];
	vector<int> costsubj(nsubj); REP(i,nsubj) scanf("%d",&costsubj[i]);

	memset(active,true,sizeof(active));
	REP(i,4) {
		int h1,m1,h2,m2; scanf("%d:%d-%d:%d",&h1,&m1,&h2,&m2); int t1=h1*60+m1,t2=h2*60+m2;
		int t=t1; while(true) { active[t]=false; if(t==t2) break; if(++t>=1440) t=0; }
	}
	activetimebefore[0]=0; REP(i,1440) activetimebefore[i+1]=activetimebefore[i]+(active[i]?1:0);
	activetimeperday=activetimebefore[1440];
	//REP(i,1440-1) if(active[i]!=active[i+1]) printf("%02d:%02d -> %d to %d\n",i/60,i%60,active[i],active[i+1]);
	
	vector<Emp> emp;
	REP(i,nemp) {
		string s; cin>>s; int d,h,m,get; scanf("%d %d:%d %d",&d,&h,&m,&get); int t=h*60+m;
		int cost=-1; REP(j,nsubj) if(subj[j]==s) { cost=costsubj[j]; break; } if(cost==-1) continue;
		emp.PB((Emp){cost,convert(d,t),get,i+1});
	}
	sort(emp.begin(),emp.end());
	//REPSZ(i,emp) printf("%d: %d %d %d\n",emp[i].ind,emp[i].t,emp[i].cost,emp[i].get);
	
	VVI best(ndays*activetimeperday+1,VI(nemp+1,-1));
	VVI prevt(ndays*activetimeperday+1,VI(nemp+1,-1));
	#define ADD(t,at,have,pt) { /*printf("\tadding %d %d %d\n",t,at,have);*/ if(t<=ndays*activetimeperday&&have>best[t][at]) { best[t][at]=have,prevt[t][at]=pt; } }
	ADD(0,0,0,-1);
	int maxhave=0,endat=-1,endt=-1;
	REPE(at,SZ(emp)) REPE(t,ndays*activetimeperday) {
		int have=best[t][at]; if(have==-1) continue;
//		printf("(%d,%d)=%d\n",t,at,have);
		if(at>=SZ(emp)) {
			if(have>maxhave) maxhave=have,endat=at,endt=t;
			continue;
		}
		ADD(t,at+1,have,t);
		if(t+emp[at].cost<=emp[at].t) ADD(t+emp[at].cost,at+1,have+emp[at].get,t);
	}
	vector<pair<int,int> > res;
	for(int t=endt,at=endat;at>0;t=prevt[t][at],--at) {
		if(prevt[t][at]!=t) res.PB(MP(at-1,prevt[t][at]));
	}
	reverse(res.begin(),res.end());
	printf("%d\n",maxhave);
	printf("%d\n",SZ(res));
	REPSZ(i,res) { printf("%d ",emp[res[i].first].ind); printt(res[i].second); printf(" "); printt(res[i].second+emp[res[i].first].cost-1); puts(""); }
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}
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

int n,nred;
int s; ll nsteps;

int nxt[MAXN];
ll visit[MAXN];

int calc(int at) {
	for(int i=n;i>=1;--i) {
		if(at<nred) {
			at+=i; if(at>=n) at-=n;
		} else {
			at+=n-i; if(at>=n) at-=n;
		}
	}
	return at;
}

int solve() {
	int at=s;
	while(nsteps%n!=0) {
		if(at<nred) at=(at+nsteps)%n; else at=((at-nsteps)%n+n)%n;
		--nsteps;
	}
	//printf("at=%d nsteps=%d\n",at,nsteps);
	
	REP(i,n) nxt[i]=-1,visit[i]=-1;
	while(nsteps!=0) {
		if(visit[at]!=-1) nsteps%=(visit[at]-nsteps); else visit[at]=nsteps;
		if(nsteps==0) break;
		if(nxt[at]==-1) nxt[at]=calc(at);
		at=nxt[at]; nsteps-=n;
	}

	return at;
}

void run() {
	scanf("%d%d",&n,&nred);
	scanf("%d%lld",&s,&nsteps); --s;
	printf("%d\n",solve()+1);
}

void research() {
	int n=200;
	FORE(n,10,1000) {
		//printf("%4d: ",n);
		if(n!=99) continue;
		FORE(na,1,n-1) {
			vector<int> dst;
			REP(sat,n) {
				int at=sat;
				vector<int> pos(1,at);
				for(int step=n;step>=1;--step) {
					if(at<na) at=(at+step)%n; else at=(at+n-step)%n;
					pos.PB(at);
				}
				dst.PB(at);
			}
			bool alternating=abs(dst[0]-dst[1])==1; FORSZ(i,2,dst) if(dst[i]!=dst[i-2]) alternating=false;
			//printf("%c",alternating?'.':'x');
			printf("%d:\n",na); REPSZ(i,dst) printf(" %d",dst[i]); puts("");
		}
		//puts("");
	}
}

void stress() {
	REP(rep,1000) {
		n=MAXN-rand()%2;
		nred=1+(rand()%1000*1000+rand()%1000)%(n-1);
		s=(rand()%1000*1000+rand()%1000)%n;
		nsteps=1000000000LL-rand()%1000;
		solve();
		printf(".");
	}
}

int main() {
	//research();
	run();
	//stress();
	return 0;
}
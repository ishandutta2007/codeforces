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
const int MAXGAP=1000;
const int MAXHAVE=100000;

int n;
int x[MAXN+2];
int nhave;
int have[MAXHAVE];
int ncan;
int can[MAXHAVE];
int nuse;
int use[MAXHAVE];
int ngap;
int gap[MAXN+2];
int ret[MAXN+2];

int lis[MAXN+2],nlis;
int maxlis[MAXN+2];




void run() {
	scanf("%d",&n); x[0]=0; REP(i,n) scanf("%d",&x[i+1]); x[n+1]=1000000001; n+=2;
	scanf("%d",&nhave); REP(i,nhave) scanf("%d",&have[i]); sort(have,have+nhave);
	ncan=nhave; REP(i,nhave) can[i]=have[i]; ncan=unique(can,can+ncan)-can;

	nlis=0;
	REP(i,n) {
		if(x[i]!=-1) {
			int l=-1,h=nlis; // (l,h]
			while(l+1<h) { int m=l+(h-l)/2; if(lis[m]>=x[i]) h=m; else l=m; }
			lis[h]=x[i]; if(h==nlis) ++nlis; maxlis[i]=h+1;
		} else {
			int h=nlis;
			for(int j=nhave-1;j>=0;--j) {
				while(h!=0&&have[j]<=lis[h-1]) --h;
				lis[h]=have[j]; if(h==nlis) ++nlis;
			}
			maxlis[i]=-1;
		}
		//printf("%d: %d ->",i,maxlis[i]); REP(j,nlis) printf(" %d",lis[j]); puts("");
	}

	REP(i,n) ret[i]=x[i];
	int to=n-1; int tocan=ncan; nuse=0;
	while(to!=0) {
		int at=to-1; ngap=0;
		while(tocan>0&&can[tocan-1]>=x[to]) --tocan;
		while(true) {
			assert(at>=0);
			if(x[at]==-1) { gap[ngap++]=at; --at; continue; }
			if(x[at]>=x[to]) { --at; continue; }
			//printf("%d..%d = %d..%d -> %d gaps, [?..%d) fit\n",at,to,x[at],x[to],ngap,tocan);
			if(maxlis[to]-maxlis[at]-1>min(tocan,ngap)||maxlis[to]-maxlis[at]-1>0&&can[tocan-(maxlis[to]-maxlis[at]-1)]<=x[at]) { --at; continue; }
			break;
		}
		REP(i,maxlis[to]-maxlis[at]-1) ret[gap[i]]=can[tocan-i-1],use[nuse++]=can[tocan-i-1];
		to=at;
	}

	sort(use,use+nuse); int athave=0,atuse=0;
	REP(i,n) if(ret[i]==-1) { while(atuse<nuse&&athave<nhave&&have[athave]==use[atuse]) ++atuse,++athave; assert(athave<nhave); ret[i]=have[athave++]; }

	//TODO: fill remaining gaps
	FOR(i,1,n-1) { if(i!=1) printf(" "); printf("%d",ret[i]); } puts("");

}


int main() {
	run();
	return 0;
}
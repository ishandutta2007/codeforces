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

const int MAXN=1000000;

int n,nq;
int dpar[MAXN];
vector<int> dch[MAXN];
vector<ll> dchsum[MAXN];

void mergeappend(vector<int> &c,const vector<int> &a,int da,const vector<int> &b,int db) {
	int ai=0,bi=0;
	while(ai<SZ(a)||bi<SZ(b)) if(ai<SZ(a)&&(bi>=SZ(b)||a[ai]+da<=b[bi]+db)) c.PB(a[ai++]+da); else c.PB(b[bi++]+db);
}

ll calc(int at,int sval) {
	int idx=lower_bound(dch[at].begin(),dch[at].end(),sval)-dch[at].begin();
	return (ll)idx*sval-dchsum[at][idx];
}

void run() {
	scanf("%d%d",&n,&nq);
	dpar[0]=-1; FOR(i,1,n) scanf("%d",&dpar[i]);
	for(int i=n-1;i>=0;--i) {
		dch[i].PB(0);
		if(2*i+1<n&&2*i+2>=n) REPSZ(j,dch[2*i+1]) dch[i].PB(dch[2*i+1][j]+dpar[2*i+1]);
		if(2*i+1<n&&2*i+2<n) mergeappend(dch[i],dch[2*i+1],dpar[2*i+1],dch[2*i+2],dpar[2*i+2]);
		dchsum[i].PB(0); REPSZ(j,dch[i]) dchsum[i].PB(dchsum[i].back()+dch[i][j]);
	}
	//REP(i,n) { printf("%d:",i); REPSZ(j,dch[i]) printf(" %d",dch[i][j]); puts(""); }
	//REP(i,n) { printf("%dsum:",i); REPSZ(j,dchsum[i]) printf(" %lld",dchsum[i][j]); puts(""); }

	REP(i,nq) {
		int x,sval; scanf("%d%d",&x,&sval); --x;
		int at=x,val=sval; ll ret=calc(at,val);
		while(at!=0&&val>0) {
			ret-=calc(at,val-2*dpar[at]);
			val-=dpar[at]; at=(at-1)/2;
			ret+=calc(at,val);
		}
		printf("%lld\n",ret);
	}
}

int main() {
	run();
	return 0;
}
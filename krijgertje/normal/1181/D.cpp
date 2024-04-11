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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXHAVE=500000;
const int MAXCAND=500000;
const int MAXQ=500000;
const int MAXS=4*MAXCAND;

int nhave,ncand,nq;
int have[MAXHAVE];
ll q[MAXQ]; int qans[MAXQ];

int cnt[MAXCAND];
pair<int,int> candord[MAXCAND];
pair<ll,int> qord[MAXQ];

int sval[MAXS];
void sinit(int x,int l,int r) {
	if(l==r) {
		sval[x]=0;
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		sval[x]=sval[2*x+1]+sval[2*x+2];
	}
}
void smod(int x,int l,int r,int IDX) {
	if(l==r) {
		++sval[x];
	} else {
		int m=l+(r-l)/2;
		if(IDX<=m) smod(2*x+1,l,m,IDX); else smod(2*x+2,m+1,r,IDX);
		sval[x]=sval[2*x+1]+sval[2*x+2];
	}
}
int sget(int x,int l,int r,int IDX) {
	assert(IDX<sval[x]);
	if(l==r) {
		return l;
	} else {
		int m=l+(r-l)/2;
		if(IDX<sval[2*x+1]) return sget(2*x+1,l,m,IDX); else return sget(2*x+2,m+1,r,IDX-sval[2*x+1]);
	}
}

void solve() {
	REP(i,ncand) cnt[i]=0;
	REP(i,nhave) ++cnt[have[i]];
	REP(i,ncand) candord[i]=MP(cnt[i],i);
	sort(candord,candord+ncand);
	REP(i,nq) qord[i]=MP(q[i],i);
	sort(qord,qord+nq);

	sinit(0,0,ncand-1);
	ll atyear=nhave+1; int atq=0,atcand=0; ll timeseach=candord[atcand].first;
	while(atq<nq) {
		int period=atcand;
		if(period>0) {
			ll k=(qord[atq].first-atyear)/period;
			if(atcand<ncand) k=min(k,candord[atcand].first-timeseach);
			atyear+=k*period; timeseach+=k;
		}
		while(atcand<ncand&&candord[atcand].first==timeseach) smod(0,0,ncand-1,candord[atcand].second),++atcand,++period;
		while(atq<nq&&qord[atq].first-atyear<period) {
			//printf("q%d is %dth when each city as organized at least %lld times\n",qord[atq].second+1,(int)(qord[atq].first-atyear+1),timeseach);
			qans[qord[atq].second]=sget(0,0,ncand-1,(int)(qord[atq].first-atyear));
			++atq;
		}
	}
}

void run() {
	scanf("%d%d%d",&nhave,&ncand,&nq);
	REP(i,nhave) scanf("%d",&have[i]),--have[i];
	REP(i,nq) scanf("%lld",&q[i]);
	solve();
	REP(i,nq) printf("%d\n",qans[i]+1);
}

int main() {
	run();
	return 0;
}
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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=500;
const int MOD=998244353;

int n;
ll a[MAXN];

ll rem[MAXN];
vector<pair<ll,int>> p[MAXN];

vector<pair<ll,int>> allp;

ll prod[MAXN]; int nprod;


ll findroot(ll x,int k) {
	ll l=1,h=x;
	while(l<=h) {
		ll m=l+(h-l)/2;
		ll cur=1; REP(i,k) cur=m>LLONG_MAX/cur?LLONG_MAX:cur*m;
		if(cur<x) l=m+1; else if(cur>x) h=m-1; else return m;
	}
	return -1;
}

int solve() {
	REP(i,n) {
		p[i].clear(); rem[i]=a[i];
		for(int j=4;j>=2;--j) {
			ll cur=findroot(rem[i],j); if(cur!=-1) { p[i].PB(MP(cur,j)); rem[i]=1; break; }
		}
	}
	REP(i,n) FOR(j,i+1,n) {
		ll g=gcd(rem[i],rem[j]); if(g==1||g==rem[i]||g==rem[j]) continue;
		assert(rem[i]/g!=g&&rem[j]/g!=g);
		p[i].PB(MP(g,1)); p[i].PB(MP(rem[i]/g,1)); p[j].PB(MP(g,1)); p[j].PB(MP(rem[j]/g,1)); rem[i]=rem[j]=1;
	}

	while(true) {
		bool change=false;
		allp.clear(); REP(i,n) REPSZ(j,p[i]) allp.PB(p[i][j]); sort(allp.begin(),allp.end());
		int nsz=0; REPSZ(i,allp) if(nsz==0||allp[i].first!=allp[nsz-1].first) allp[nsz++]=allp[i]; else allp[nsz-1].second+=allp[i].second; allp.resize(nsz);
		REP(i,n) if(rem[i]!=1) REPSZ(j,allp) if(rem[i]%allp[j].first==0) { assert(rem[i]/allp[j].first!=allp[j].first); p[i].PB(MP(allp[j].first,1)); p[i].PB(MP(rem[i]/allp[j].first,1)); rem[i]=1; change=true; }
		if(!change) break;
	}

	//REP(i,n) { printf("%lld:",a[i]); REPSZ(j,p[i]) printf(" %lld^%d",p[i][j].first,p[i][j].second); if(rem[i]!=1) printf(" (%lld)",rem[i]); puts(""); }

	int ret=1;
	REPSZ(i,allp) ret=(ll)ret*(allp[i].second+1)%MOD;
	nprod=0; REP(i,n) if(rem[i]!=1) prod[nprod++]=rem[i];
	sort(prod,prod+nprod);
	for(int l=0,r=l;l<nprod;l=r) {
		while(r<nprod&&prod[l]==prod[r]) ++r;
		int cnt=r-l;
		ret=(ll)ret*(cnt+1)%MOD;
		ret=(ll)ret*(cnt+1)%MOD;
	}
	return ret;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%lld",&a[i]);
	printf("%d\n",solve());
	fflush(stdout);
}

int main() {
	run();
	return 0;
}
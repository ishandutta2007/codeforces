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

const int MAXN=200000;

int n;
ll x[MAXN]; char col[MAXN];

int r[MAXN],nr;
int g[MAXN],ng;
int b[MAXN],nb;

ll solve() {
	nr=ng=nb=0; REP(i,n) if(col[i]=='R') r[nr++]=i; else if(col[i]=='B') b[nb++]=i; else if(col[i]=='G') g[ng++]=i;
	ll ret=0;
	if(ng==0) {
		if(nr>0) ret+=x[r[nr-1]]-x[r[0]];
		if(nb>0) ret+=x[b[nb-1]]-x[b[0]];
	} else {
		if(nr>0&&r[0]<g[0]) ret+=x[g[0]]-x[r[0]];
		if(nb>0&&b[0]<g[0]) ret+=x[g[0]]-x[b[0]];
		if(nr>0&&r[nr-1]>g[ng-1]) ret+=x[r[nr-1]]-x[g[ng-1]];
		if(nb>0&&b[nb-1]>g[ng-1]) ret+=x[b[nb-1]]-x[g[ng-1]];
		//printf("sofar=%lld\n",ret);
		REP(i,ng-1) {
			int lft=g[i],rgt=g[i+1];
			ll len=x[rgt]-x[lft];
			ll rmx=0; int rprv=lft; FORE(j,lft+1,rgt) if(col[j]!='B') { ll cur=x[j]-x[rprv]; if(cur>rmx) rmx=cur; rprv=j; }
			ll bmx=0; int bprv=lft; FORE(j,lft+1,rgt) if(col[j]!='R') { ll cur=x[j]-x[bprv]; if(cur>bmx) bmx=cur; bprv=j; }
			ll now=min(2*len,3*len-rmx-bmx);
			//printf("now=%lld (len=%lld rmx=%lld bmx=%lld)\n",now,len,rmx,bmx);
			ret+=now;
		}
	}
	return ret;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%lld %c",&x[i],&col[i]); REP(i,n) if(col[i]=='P') col[i]='G';
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}
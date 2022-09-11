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

const int MAXN=300000;

int n;
int x[MAXN]; char col[MAXN];

int r[MAXN],nr;
int b[MAXN],nb;
int g[MAXN],ng;



void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d %c",&x[i],&col[i]);
	
	ng=nb=nr=0; REP(i,n) if(col[i]=='G') g[ng++]=x[i]; else if(col[i]=='R') r[nr++]=x[i]; else if(col[i]=='B') b[nb++]=x[i];
	if(ng==0) {
		ll ret=0; if(nb>=1) ret+=b[nb-1]-b[0]; if(nr>=1) ret+=r[nr-1]-r[0]; printf("%lld\n",ret);
	} else {
		ll ret=0;
		if(nb>=1&&b[0]<g[0]) ret+=g[0]-b[0]; if(nr>=1&&r[0]<g[0]) ret+=g[0]-r[0];
		if(nb>=1&&b[nb-1]>g[ng-1]) ret+=b[nb-1]-g[ng-1]; if(nr>=1&&r[nr-1]>g[ng-1]) ret+=r[nr-1]-g[ng-1];
		int ri=0,rj=0,bi=0,bj=0;
		REP(i,ng-1) {
			while(ri<nr&&r[ri]<g[i]) ++ri; while(rj<nr&&r[rj]<g[i+1]) ++rj;
			while(bi<nb&&b[bi]<g[i]) ++bi; while(bj<nb&&b[bj]<g[i+1]) ++bj;
			int len=g[i+1]-g[i];
			ll opt1=(ll)2*len;
			int subr=0,subb=0;
			if(ri==rj) subr=len; else { subr=max(r[ri]-g[i],g[i+1]-r[rj-1]); FOR(k,ri+1,rj) subr=max(subr,r[k]-r[k-1]); }
			if(bi==bj) subb=len; else { subb=max(b[bi]-g[i],g[i+1]-b[bj-1]); FOR(k,bi+1,bj) subb=max(subb,b[k]-b[k-1]); }
			ll opt2=(ll)3*len-subr-subb;
			//printf("%d..%d opt1=%lld opt2=%lld\n",g[i],g[i+1],opt1,opt2);
			ret+=min(opt1,opt2);
		}
		printf("%lld\n",ret);
	}
}

int main() {
	run();
	return 0;
}
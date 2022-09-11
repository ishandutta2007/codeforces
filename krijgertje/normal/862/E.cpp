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

int a[MAXN],na;
int b[MAXN],nb;
int nq;

ll c[MAXN]; int nc;

void calcc() {
	nc=0;
	ll have=0; REP(i,na) if(i%2==0) have-=b[i]; else have+=b[i];
	REPE(i,nb-na) {
		c[nc++]=have;
		if(na+i<nb) { have+=b[i]; have=-have; if(na%2==1) have-=b[na+i]; else have+=b[na+i]; }
	}
	sort(c,c+nc); nc=unique(c,c+nc)-c;
	//printf("c:"); REP(i,nc) printf(" %lld",c[i]); puts("");
}

void solve(ll have) {
	int idx=lower_bound(c,c+nc,-have)-c;
	ll ret=idx>=nc?abs(have+c[idx-1]):idx==0?abs(have+c[idx]):min(abs(have+c[idx-1]),abs(have+c[idx]));
	printf("%lld\n",ret);
}

void run() {
	scanf("%d%d%d",&na,&nb,&nq);
	REP(i,na) scanf("%d",&a[i]);
	REP(i,nb) scanf("%d",&b[i]);
	calcc();
	ll have=0; REP(i,na) if(i%2==0) have+=a[i]; else have-=a[i];
	solve(have);
	REP(i,nq) {
		int l,r,by; scanf("%d%d%d",&l,&r,&by); --l,r;
		if(r%2==1) have+=by; if(l%2==1) have-=by;
		solve(have);
	}
}

int main() {
	run();
	return 0;
}
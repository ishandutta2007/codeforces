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

const int MAXN=150000;
typedef struct R { int p,t; ll mnx,mxx; } R;
bool ratcmp(const R &a,const R &b) { return (ll)a.p*b.t>(ll)b.p*a.t; }
bool pcmp(const R &a,const R &b) { return a.p<b.p; }

int n;
R r[MAXN];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&r[i].p); REP(i,n) scanf("%d",&r[i].t);
	ll T=0; REP(i,n) T+=r[i].t;

	sort(r,r+n,ratcmp); //REP(i,n) printf("(%d,%d)",r[i].p,r[i].t); puts("");
	ll x=0; for(int at=0,to=at;to<n;at=to) {
		while(to<n&&(ll)r[at].p*r[to].t==(ll)r[to].p*r[at].t) ++to;
		FOR(i,at,to) r[i].mnx=x+r[i].t; FOR(i,at,to) x+=r[i].t; FOR(i,at,to) r[i].mxx=x;
	}

	sort(r,r+n,pcmp);
	{ int nn=0; REP(i,n) if(nn==0||r[i].p!=r[nn-1].p) r[nn++]=r[i]; else r[nn-1].mnx=min(r[nn-1].mnx,r[i].mnx),r[nn-1].mxx=max(r[nn-1].mxx,r[i].mxx); n=nn; }
	double ret=1;
	REP(i,n-1) {
		//c=T*(r[i+1].p-r[i].p)/(r[i+1].p*r[i+1].mxx-r[i].p*r[i].mnx)
		double num=1.0*T*(r[i+1].p-r[i].p),den=1.0*r[i+1].p*r[i+1].mxx-1.0*r[i].p*r[i].mnx;
		if(den<=0) continue;
		double c=num/den; if(c<ret) ret=c;
	}
	printf("%.9lf\n",ret);
}

int main() {
	run();
	return 0;
}
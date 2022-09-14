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

const int MAXN=5000;

typedef struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} } P;
bool operator<(const P &a,const P &b) { if(a.x!=b.x) return a.x<b.x; return a.y<b.y; }
const P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
const P operator+(const P &a,const P &b) { return P(a.x+b.x,a.y+b.y); }
const ll operator^(const P &a,const P &b) { return (ll)a.x*b.y-(ll)a.y*b.x; }

ll darea(const P &a,const P &b,const P &c) { return (b-a)^(c-a); }
bool ok(const P &a,const P &b,const P &c) { return darea(a,b,c)>0; }

int n; ll mxarea,mxdarea;
P p[MAXN];

P h[2*MAXN]; int nh;

void input() {
	scanf("%d%lld",&n,&mxarea);
	REP(i,n) scanf("%d%d",&p[i].x,&p[i].y);
}

P qa,qb,qc;
P ra,rb,rc;

void solve() {
	sort(p,p+n);

	nh=0;
	REP(i,n) {
		while(nh>=2&&!ok(h[nh-2],h[nh-1],p[i])) --nh;
		h[nh++]=p[i];
	}
	int th=nh;
	for(int i=n-2;i>=0;--i) {
		while(nh-th>=1&&!ok(h[nh-2],h[nh-1],p[i])) --nh;
		h[nh++]=p[i];
	}
	--nh;
	REP(i,nh) h[nh+i]=h[i];

	int ba=-1,bb=-1,bc=-1; mxdarea=0;
	REP(a,nh) {
		int c=a;
		FOR(b,a+1,a+nh-1) {
			if(c<=b) c=b+1;
			while(c+1<a+nh&&darea(h[a],h[b],h[c+1])>darea(h[a],h[b],h[c])) ++c;
			if(darea(h[a],h[b],h[c])>mxdarea) mxdarea=darea(h[a],h[b],h[c]),ba=a,bb=b,bc=c;
		}
	}

	qa=h[ba],qb=h[bb],qc=h[bc];
	ra=qb+(qc-qa);
	rb=qc+(qa-qb);
	rc=qa+(qb-qc);
}

void test() {
	//fprintf(stderr,"h:"); REP(i,nh) fprintf(stderr," (%d,%d)",h[i].x,h[i].y); fprintf(stderr,"\n");
	//fprintf(stderr,"\t%d %d\n",qa.x,qa.y);
	//fprintf(stderr,"\t%d %d\n",qb.x,qb.y);
	//fprintf(stderr,"\t%d %d\n",qc.x,qc.y);
	REP(i,n) if(darea(ra,rb,p[i])<0) fprintf(stderr,"err a b (%d,%d)\n",p[i].x,p[i].y);
	REP(i,n) if(darea(rb,rc,p[i])<0) fprintf(stderr,"err b c (%d,%d)\n",p[i].x,p[i].y);
	REP(i,n) if(darea(rc,ra,p[i])<0) fprintf(stderr,"err c a (%d,%d)\n",p[i].x,p[i].y);

	if(mxdarea>2*mxarea) fprintf(stderr,"found larger triangle\n");
	//fprintf(stderr,"%lf (%lld %lld)\n",1.0*darea(ra,rb,rc)/darea(qa,qb,qc),darea(ra,rb,rc),darea(qa,qb,qc));
}

void output() {
	printf("%d %d\n",ra.x,ra.y);
	printf("%d %d\n",rb.x,rb.y);
	printf("%d %d\n",rc.x,rc.y);
}


void run() {
	input();
	solve();
	//test();
	output();

}

int myrand(int mod) {
	ll ret=1;
	REP(i,4) ret=ret*RAND_MAX+rand();
	return ret%mod;
}

int main() {
	run();
	/*while(true) {
		n=5000; mxarea=LLONG_MAX/2;
		int z=100000000;
		REP(i,n) {
			p[i].x=myrand(2*z+1)-z;
			p[i].y=myrand(2*z+1)-z;
		}
		//REP(i,n) printf("(%d,%d)",p[i].x,p[i].y); puts("");
		solve();
		test();
		//output();
	}*/
	return 0;
}
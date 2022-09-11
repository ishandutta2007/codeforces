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
#include <chrono>
#include <chrono>
#include <random>
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

const int MAXN=1000;
struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} };
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
ll operator^(const P &a,const P &b) { return (ll)a.x*b.y-(ll)a.y*b.x; }

bool local=false;
P plocal[MAXN];

int queryside(int a,int b,int c) {
	if(!local) {
		printf("2 %d %d %d\n",a+1,b+1,c+1); fflush(stdout);
		int ret; scanf("%d",&ret); return ret;
	} else {
		ll signedarea=(plocal[b]-plocal[a])^(plocal[c]-plocal[a]);
		assert(signedarea!=0); return signedarea>0?+1:-1;
	}
}

ll queryarea(int a,int b,int c) {
	if(!local) {
		printf("1 %d %d %d\n",a+1,b+1,c+1); fflush(stdout);
		ll ret; scanf("%lld",&ret); return ret;
	} else {
		ll signedarea=(plocal[b]-plocal[a])^(plocal[c]-plocal[a]);
		return abs(signedarea);
	}
}

vector<int> solveside(int a,vector<int> p,int b) {
	//printf("solveside: %d (",a+1); REPSZ(i,p) printf(" %d",p[i]+1); printf(") %d\n",b+1);
	int n=SZ(p);
	if(n==0) return vector<int>();
	vector<ll> area(n);
	REP(i,n) area[i]=queryarea(a,b,p[i]);
	int mxidx=0; FOR(i,1,n) if(area[i]>area[mxidx]) mxidx=i;
	vector<pair<ll,int>> l,r;
	REP(i,n) if(i!=mxidx) {
		int side=queryside(a,p[mxidx],p[i]);
		if(side>0) l.PB(MP(area[i],p[i])); else r.PB(MP(-area[i],p[i]));
	}
	sort(l.begin(),l.end());
	sort(r.begin(),r.end());
	vector<int> ret; REPSZ(i,l) ret.PB(l[i].second); ret.PB(p[mxidx]); REPSZ(i,r) ret.PB(r[i].second); return ret;
}

int n;

vector<int> solve() {
	int a=n-2,b=n-1;
	int nrem=n-2;
	vector<int> l,r;
	REP(c,nrem) {
		int side=queryside(a,b,c);
		if(side>0) l.PB(c); else r.PB(c);
	}
	l=solveside(a,l,b);
	r=solveside(b,r,a);
	vector<int> ret; ret.PB(a); REPSZ(i,l) ret.PB(l[i]); ret.PB(b); REPSZ(i,r) ret.PB(r[i]);
	reverse(ret.begin(),ret.end());
	int zeroidx=-1; REPSZ(i,ret) if(ret[i]==0) { assert(zeroidx==-1); zeroidx=i; } assert(zeroidx!=-1);
	rotate(ret.begin(),ret.begin()+zeroidx,ret.end());
	return ret;
}

void run() {
	scanf("%d",&n);
	vector<int> ans=solve();
	printf("0"); REPSZ(i,ans) printf(" %d",ans[i]+1); puts(""); fflush(stdout);
}

void test() {
	local=true;
	scanf("%d",&n);
	REP(i,n) scanf("%d %d",&plocal[i].x,&plocal[i].y);
	vector<int> ans=solve();
	printf("!"); REPSZ(i,ans) printf(" %d",ans[i]+1); puts("");
}

int main() {
	run();
	//test();
	return 0;
}
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

ll A;
ll fact[20]; int factcnt[20],nfact;

typedef struct X { ll cur; int id; ll p; } X;
bool operator<(const X &a,const X &b) { return a.p<b.p; }
X x[20000]; int nx;

void adddiv(ll cur,int id,ll p) {
	//if(p!=cur-1) printf("%lld -> %lld (%d)\n",cur,p,id);
	x[nx].cur=cur; x[nx].id=id; x[nx].p=p; ++nx;
}

void testdiv(ll cur,int id) {
	ll x=cur-1; for(ll i=2;i*i<=x;++i) if(x%i==0) { while(x%i==0) x/=i; if(x==1) adddiv(cur,id,i); return; } adddiv(cur,id,x);
}

void gendivs(ll cur,int at,int id) {
	if(at>=nfact) { if(cur>=3) testdiv(cur,id); return; }
	REPE(i,factcnt[at]) { gendivs(cur,at+1,id*(factcnt[at]+1)+i); cur*=fact[at]; }
}

ll ways[20000];
bool ok(int a,int b) {
	for(int i=nfact-1;i>=0;--i) {
		int aa=a%(factcnt[i]+1); a/=factcnt[i]+1;
		int bb=b%(factcnt[i]+1); b/=factcnt[i]+1;
		if(aa+bb>factcnt[i]) return false;
	}
	return true;
}

void run() {
	cin>>A;
	{ ll x=A; for(ll i=2;i*i<=x;++i) if(x%i==0) { fact[nfact]=i; factcnt[nfact]=0; while(x%i==0) factcnt[nfact]++,x/=i; ++nfact; } if(x!=1) fact[nfact]=x,factcnt[nfact]=1,++nfact; }
	//REP(i,nfact) printf("%lld^%d ",fact[i],factcnt[i]); puts("");

	nx=0; gendivs(1,0,0); sort(x,x+nx);
	int start=0; REP(i,nfact) start=start*(factcnt[i]+1)+factcnt[i]; //printf("start=%d\n",start);

	memset(ways,0,sizeof(ways)); ways[0]=1;
	//REP(i,nx) printf("%lld %d %lld\n",x[i].cur,x[i].id,x[i].p);
	int at=0;
	while(at<nx) {
		int to=at; while(to<nx&&x[at].p==x[to].p) ++to;
		for(int i=start-1;i>=0;--i) FOR(j,at,to) if(ok(i,x[j].id)) ways[i+x[j].id]+=ways[i];
		at=to;
	}
	cout<<ways[start]<<endl;
}

int main() {
	run();
	return 0;
}
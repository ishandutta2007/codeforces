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
typedef struct R { int rem; ll fst; int id; int k; } R;
bool operator<(const R &a,const R &b) { if(a.rem!=b.rem) return a.rem<b.rem; if(a.k!=b.k) return a.k<b.k; return a.id<b.id; }

int T,n;
int a[MAXN];
ll P;
int g;
R o[MAXN];
int ret[MAXN];

ll egcd(ll a,ll b,ll &p,ll &q) { // p*a+q*b=g
	if(b==0) { p=1,q=0; return a; }
	ll g=egcd(b,a%b,q,p); q-=p*(a/b); return g;
}

void run() {
	scanf("%d%d",&T,&n); REP(i,n) scanf("%d",&a[i]);
	P=0; REP(i,n) P+=a[i]; ll A,B; g=egcd(P,T,A,B); int MOD=T/g; int Pdivginv=(A%MOD+MOD)%MOD;
	REP(i,n) { o[i].fst=i==0?0:o[i-1].fst+a[i]; o[i].rem=o[i].fst%g; o[i].id=i; o[i].k=((o[i].rem-o[i].fst)/g%MOD*Pdivginv%MOD+MOD)%MOD; }
	sort(o,o+n);
	//REP(i,n) printf("%d: %d [%d: %lld]\n",o[i].rem,o[i].k,o[i].id,o[i].fst);
	for(int at=0,to=at;at<n;at=to) {
		while(to<n&&o[at].rem==o[to].rem) ++to;
		FOR(i,at,to) {
			int j=i==at?to-1:i-1;
			ret[o[i].id]=o[i].k==o[j].k&&i==at?MOD:(o[i].k-o[j].k+MOD)%MOD;
		}
	}
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}
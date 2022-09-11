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

const int MAXVAL=100000;
const int MAXN=100000;

int pmn[MAXVAL+1];

int n,k;
int a[MAXN];

int cnt[MAXVAL+1];

ll safemlt(ll a,ll b) { assert(a>=1&&b>=1); return a>LLONG_MAX/b?LLONG_MAX:a*b; }

void precalc() {
	memset(pmn,-1,sizeof(pmn));
	FORE(i,2,MAXVAL) if(pmn[i]==-1) for(int j=i;j<=MAXVAL;j+=i) if(pmn[j]==-1) pmn[j]=i;
}

vector<pair<int,int>> factorize(int x) {
	vector<pair<int,int>> ret;
	while(x>1) { int p=pmn[x],cnt=0; while(x%p==0) x/=p,++cnt; ret.PB(MP(p,cnt)); }
	return ret;
}

ll go(const vector<pair<int,int>> &fac,int at,ll x,ll y) {
	if(x>MAXVAL||y>MAXVAL) return 0;
	if(at>=SZ(fac)) {
		if(x<y) return (ll)cnt[x]*cnt[y];
		if(x==y) return (ll)cnt[x]*(cnt[x]-1)/2;
		return 0;
	}
	ll ret=0;
	REP(k,fac[at].second) y*=fac[at].first;
	REPE(k,fac[at].second) { ret+=go(fac,at+1,x,y); if(k<fac[at].second) x*=fac[at].first,y/=fac[at].first; }
	return ret;
}

ll solve() {
	precalc();
	memset(cnt,0,sizeof(cnt)); REP(i,n) ++cnt[a[i]];
	ll ret=0;
	for(int x=1;;++x) {
		ll prod=1; REP(i,k) prod=safemlt(prod,x); if(prod>(ll)MAXVAL*MAXVAL) break;
		//printf("x=%d prod=%lld\n",x,prod);
		vector<pair<int,int>> fac=factorize(x); REPSZ(j,fac) fac[j].second*=k;
		ll cur=go(fac,0,1,1);
		//if(cur>0) printf("x=%d prod=%lld -> cur=%lld\n",x,prod,cur);
		ret+=cur;
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&k);
	REP(i,n) scanf("%d",&a[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}
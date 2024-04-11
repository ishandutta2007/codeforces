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
#include <bitset>
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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const ll MRP[]={2LL, 325LL, 9375LL, 28178LL, 450775LL, 9780504LL, 1795265022LL};

void inc(ll &a,ll b,ll mod) { if((a+=b)>=mod) a-=mod; }
ll mlt(ll a,ll b,ll mod) { ll ret=0; while(true) { if(b&1) inc(ret,a,mod); if((b>>=1)==0) return ret; inc(a,a,mod); } }
ll pw(ll x,ll n,ll mod) { ll ret=1%mod; x%=mod; while(true) { if(n&1) ret=mlt(ret,x,mod); if((n>>=1)==0) return ret; x=mlt(x,x,mod); } }
bool millerrabin_isprime(ll n,ll a) {
	ll d=n-1; int r=0; while(d%2==0) d/=2,++r; a%=n; if(a==0) return true;
	ll x=pw(a,d,n);
	//printf("mrtest %lld %lld -> d=%lld r=%d x=%lld\n",n,a,d,r,x);
	if(x==1||x==n-1) return true;
	REP(i,r-1) {
		x=mlt(x,x,n);
		if(x==1) return false;
		if(x==n-1) return true;
	}
	return false;
}
bool millerrabin_isprime(ll n) { if(n%2==0) return n==2; if(n<=3) return n==3; REP(i,7) if(!millerrabin_isprime(n,MRP[i])) return false; return true; }
ll pollardrho(ll val) {
	if(val==1) return 1; else if(val%2==0) return 2;
	static mt19937_64 rnd(1237891);
	while(true) {
		ll x=rnd()%(val-3)+2,y=x,c=rnd()%val,d=1; 
		while(d==1) { x=mlt(x,x,val); inc(x,c,val); y=mlt(y,y,val); inc(y,c,val); y=mlt(y,y,val); inc(y,c,val); d=gcd(abs(x-y),val); }
		if(d!=val) return d;
	} 
}
vector<pair<ll,int>> factorize(ll val) {
	vector<ll> factors; queue<ll> q; if(val!=1) q.push(val);
	while(!q.empty()) {
		ll cur=q.front(); q.pop();
		//printf("testing %lld\n",cur);
		if(millerrabin_isprime(cur)) { factors.PB(cur); continue; }
		//printf("testing %lld\n",cur);
		ll d=pollardrho(cur); q.push(d); q.push(cur/d);
		//printf("testing %lld\n",cur);
	}
	sort(factors.begin(),factors.end()); vector<pair<ll,int>> ret; for(int l=0,r=l;l<SZ(factors);l=r) { while(r<SZ(factors)&&factors[r]==factors[l]) ++r; ret.PB(MP(factors[l],r-l)); } return ret;
}

const int MAXNEED=500000;

int need; ll mod,forbidden;
ll ans[MAXNEED]; int nans;

ll p; int k; // mod=p^k
ll phi; vector<pair<ll,int>> phifactors; ll forbiddenorder;
ll gen,genord;

ll safemlt(ll a,ll b) { assert(a>=1&&b>=1); return a>LLONG_MAX/b?LLONG_MAX:a*b; }
ll safepw(ll x,int n) { ll ret=1; while(true) { if(n&1) ret=safemlt(ret,x); if((n>>=1)==0) return ret; x=safemlt(x,x); } }

void calcpk() {
	p=mod; k=1;
	for(int i=2;;++i) {
		if(safepw(2,i)>mod) break;
		ll l=2,r=4; while(safepw(r,i)<=mod) l=r,r+=r;
		while(l+1<r) { ll m=l+(r-l)/2; if(safepw(m,i)<=mod) l=m; else r=m; }
		if(safepw(l,i)==mod) p=l,k=i;
	}
	//printf("p=%lld k=%d\n",p,k);
}


void calcforbiddenorder() {
	phi=p-1; REP(i,k-1) phi*=p;
	phifactors=factorize(phi);
	//printf("phifactors:"); REPSZ(i,phifactors) printf(" %lld^%d",phifactors[i].first,phifactors[i].second); puts("");
	if(gcd(mod,forbidden)==1) {
		forbiddenorder=phi;
		REPSZ(i,phifactors) {
			ll pp=phifactors[i].first; REP(j,phifactors[i].second) forbiddenorder/=pp; 
			ll cur=pw(forbidden,forbiddenorder,mod); while(cur!=1) cur=pw(cur,pp,mod),forbiddenorder*=pp;
		}
	} else {
		forbiddenorder=-1;
	}
	//printf("forbiddenorder=%lld\n",forbiddenorder);
}

void calcgen() {
	if(p==2) {
		genord=phi/2;
		if(k==1) gen=1; else if(k==2) gen=3; else gen=5;
	} else {
		genord=phi;
		for(gen=2;;++gen) { assert(gen<mod); bool ok=true; REPSZ(i,phifactors) if(pw(gen,phi/phifactors[i].first,mod)==1) { ok=false; break; } if(ok) break; }
	}
	//printf("gen=%lld\n",gen);
}



bool solve() {
	calcpk();
	calcforbiddenorder();
	ll have=phi-(forbiddenorder==-1?1:forbiddenorder);
	//printf("have=%lld\n",have);
	if(have<need) return false;
	nans=0;
	if(forbiddenorder==-1) {
		for(ll i=2;nans<need&&i<mod;++i) if(i%p!=0) ans[nans++]=i;
	} else {
		calcgen();
		if(genord!=phi&&forbidden%4==3) {
			for(ll aval=1,bval=forbidden,exp=0;exp<genord&&nans<need;aval=mlt(aval,gen,mod),bval=mlt(bval,gen,mod),++exp) {
				if(nans<need&&exp%(2*genord/forbiddenorder)!=0) ans[nans++]=aval;
				if(nans<need&&exp%(2*genord/forbiddenorder)!=0) ans[nans++]=bval;
			}
		} else {
			for(ll val=1,exp=0;exp<genord&&nans<need;val=mlt(val,gen,mod),++exp) {
				if(nans<need&&exp%(genord/forbiddenorder)!=0) ans[nans++]=val;
				if(nans<need&&genord!=phi) ans[nans++]=mod-val;
			}
		}
	}
	assert(nans==need);
	return true;
}

void run() {
	scanf("%d%lld%lld",&need,&mod,&forbidden);
	if(!solve()) { printf("-1\n"); return; }
	REP(i,need) { if(i!=0) printf(" "); printf("%lld",ans[i]); } puts("");

}

int main() {
	run();
	return 0;
}
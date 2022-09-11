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
const int MAXPATH=100000;
const int MOD=998244353;
const int PRIMROOT=3;
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }

struct NTT {
	void _init(int n,int &nlog,int &g,vector<int> &w) {
		assert((MOD - 1) % n == 0);
		g = pw(PRIMROOT, (MOD - 1) / n); nlog = 0; while ((1 << nlog) < n) ++nlog; if ((1 << nlog) != n) nlog = -1;
		w = vector<int>(n); w[0] = 1; FOR(i, 1, n) w[i] = (ll)w[i - 1]*g%MOD;
	}
	int fftn, fftnlog; int fftg; vector<int> fftw;
	void initfft(int n) { fftn = n, _init(fftn, fftnlog, fftg, fftw); assert(fftnlog != -1); }
	void fft(int *a, int n, bool inv) {
		if (n != fftn) initfft(n);
		for (int i = 1, j = n >> 1, k, l = j; i < n; j ^= k, ++i) { if (i < j) swap(a[i], a[j]); for (k = l; k&j; j ^= k, k >>= 1); }
		int *l, *r, *w;
		if (inv) reverse(fftw.begin() + 1, fftw.end());
		for (int hlen = 1, step = n >> 1; hlen < n; hlen <<= 1, step >>= 1) {
			for (int i = 0; i < n; i += (hlen << 1)) {
				l = a + i, r = l + hlen, w = fftw.data();
				REP(off, hlen) {
					int v = (ll)(*r)*(*w)%MOD;
					*r = (*l)-v; if(*r<0) *r+=MOD;
					*l = (*l)+v; if(*l>=MOD) *l-=MOD;
					++l, ++r, w += step;
				}
			}
		}
		if (inv) reverse(fftw.begin() + 1, fftw.end());
		if (inv) { int mlt = pw(n, MOD - 2); REP(i, n) a[i] = (ll)a[i]*mlt%MOD; }
	}
	void mult(int *a,int na,int *b,int nb,int *c,int nc) {
		int sz=1; while(sz<na+nb-1) sz*=2;
		vector<int> A(sz,0),B(sz,0);
		REP(i,na) A[i]=a[i]; REP(i,nb) B[i]=b[i];
		fft(A.data(),sz,false); fft(B.data(),sz,false); REP(i,sz) A[i]=(ll)A[i]*B[i]%MOD; fft(A.data(),sz,true);
		REP(i,nc) c[i]=i<sz?A[i]:0;
	}
};


int n,npath;
vector<int> adj[MAXN];

int fac[MAXPATH+1];
int inv[MAXPATH+1];
int ifac[MAXPATH+1];

int sz[MAXN];
int waysdown[MAXN]; // # ways for this subtree when the incoming edge occurs in all paths
int waysup[MAXN]; // # ways for everything except this subtree when the incoming edge occurs in all paths

void dfsinit(int at,int par) {
	sz[at]=1;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		dfsinit(to,at);
		sz[at]+=sz[to];
	}
}

pair<int,int> opt[MAXN]; int nopt;

//struct Pol { vector<int> coef; };
typedef vector<int> Pol;
NTT ntt;

Pol rec(int l,int r) {
	if(l==r) { Pol ret; ret.PB(1); ret.PB(opt[l].first); return ret; }
	int m=l+(r-l)/2;
	Pol a=rec(l,m),b=rec(m+1,r);
	Pol c; c.resize(SZ(a)+SZ(b)-1); ntt.mult(a.data(),SZ(a),b.data(),SZ(b),c.data(),SZ(c)); return c;
}


void dfsways(int at,int par) {
	nopt=0;
	if(par!=-1) opt[nopt++]=MP(n-sz[at],par);
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		opt[nopt++]=MP(sz[to],to);
	}
	sort(opt,opt+nopt);
	Pol pol=rec(0,nopt-1); assert(SZ(pol)==nopt+1);
	int ways=-1;
	REP(i,nopt) {
		if(i==0||opt[i-1].first!=opt[i].first) {
			int a=opt[i].first,ainv=pw(a,MOD-2);
			// pol/(a*x+1)
			Pol cpol(nopt,0); int carry=pol[nopt];
			for(int i=nopt-1;i>=0;--i) {
				cpol[i]=(ll)carry*ainv%MOD;
				carry=(pol[i]+MOD-cpol[i])%MOD;
			}
			assert(carry==0);
			ways=0; REPSZ(k,cpol) if(k<=npath) ways=(ways+(ll)cpol[k]*fac[npath]%MOD*ifac[npath-k])%MOD;
		}
		if(opt[i].second==par) waysdown[at]=ways; else waysup[opt[i].second]=ways;
	}


	/*noptval=0; REP(i,nopt) optval[noptval++]=opt[i].first; sort(optval,optval+noptval); noptval=unique(optval,optval+noptval)-optval;
	REP(i,noptval) optfreq[i]=0; REP(i,nopt) { int idx=lower_bound(optval,optval+noptval,opt[i].first)-optval; opt[i].first=idx; ++optfreq[idx]; }
	printf("nopt=%d noptval=%d\n",nopt,noptval);

	REP(i,noptval) { pol[i].clear(); pol[i].PB(1); pol[i].PB(optval[i]); polpw[i]=pw(pol[i],optfreq[i]); }
	pref[0].clear(); pref[0].PB(1); REP(i,noptval) pref[i+1]=pmult(pref[i],polpw[i]);
	suff[noptval].clear(); suff[noptval].PB(1); for(int i=noptval-1;i>=0;--i) suff[i]=pmult(suff[i+1],polpw[i]);
	REP(j,noptval) {
		Pol cur=pmult(pmult(pref[j],suff[j+1]),pw(pol[j],optfreq[j]-1));
		int ways=0;
		REPSZ(k,cur) if(k<=npath) {
			ways=(ways+(ll)cur[k]*fac[npath]%MOD*ifac[npath-k])%MOD;
		}
		optans[j]=ways;
	}
	REP(j,nopt) {
		int ways=optans[opt[j].first];
		if(opt[j].second==par) waysdown[at]=(waysdown[at]+ways)%MOD; else waysup[opt[j].second]=(waysup[opt[j].second]+ways)%MOD;
	}
	REPE(i,noptval) pol[i].clear(),pref[i].clear(),suff[i].clear(); */

	//printf("at %d -> opt:",at+1); REP(j,nopt) printf(" %d=%d",opt[j].second+1,opt[j].first); puts("");
	//printf("optval:"); REP(i,noptval) printf(" %d (%d times)",optval[i],optfreq[i]); puts("");
	/*REP(i,1<<nopt) {
		int cnt=0,prod=1;
		REP(j,nopt) if(i&(1<<j)) ++cnt,prod=(ll)prod*opt[j].first%MOD;
		if(cnt>npath) continue;
		int ways=(ll)prod*fac[npath]%MOD*ifac[npath-cnt]%MOD;
		//printf("\t%x -> %d\n",i,ways);
		REP(j,nopt) if((i&(1<<j))==0) if(opt[j].second==par) waysdown[at]=(waysdown[at]+ways)%MOD; else waysup[opt[j].second]=(waysup[opt[j].second]+ways)%MOD;
	}*/
	//if(par!=-1) printf("waysdown[%d]=%d\n",at+1,waysdown[at]);
	//REP(j,nopt) if(opt[j].second!=par) printf("waysup[%d]=%d\n",opt[j].second+1,waysup[opt[j].second]);

	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		dfsways(to,at);
		waysdown[at]=(waysdown[at]+waysdown[to])%MOD;
	}
}

int dfscalc(int at,int par) { // #ways when there is at least one edge that occurs in all paths in this subtree, and not in any other part
	int ret=0;
	// no adjacent edge in all paths
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		ret=(ret+dfscalc(to,at))%MOD;
	}
	// one adjacent edge in all paths
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		//printf("\t%d->%d: %d*%d\n",at+1,to+1,waysup[to],waysdown[to]);
		ret=(ret+(ll)waysup[to]*waysdown[to])%MOD;
	}
	// two adjacent edges in all paths
	int sum=0;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		ret=(ret+(ll)sum*waysdown[to])%MOD;
		sum=(sum+waysdown[to])%MOD;
	}
	//printf("dfscalc(%d)=%d\n",at+1,ret);
	return ret;
}



int solve() {
	if(npath==1) return (ll)n*(n-1)/2%MOD;
	if(n==1) return 0;

	inv[1]=1; FORE(i,2,npath) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	fac[0]=1; FORE(i,1,npath) fac[i]=(ll)fac[i-1]*i%MOD;
	ifac[0]=1; FORE(i,1,npath) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;

	dfsinit(0,-1);
	dfsways(0,-1);
	return dfscalc(0,-1);
}

void run() {
	scanf("%d%d",&n,&npath); REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b),adj[b].PB(a); }
	printf("%d\n",solve());
}

void stress1() {
	n=MAXN,npath=MAXN; REP(i,n) adj[i].clear();
	int at=1; for(int len=1;at<n;++len) { int clen=min(len,n-at); int prv=0; REP(i,clen) { adj[prv].PB(at); adj[at].PB(prv); prv=at; ++at; } }
	printf("%d\n",solve());
}

void stress2() {
	n=MAXN,npath=MAXN; REP(i,n) adj[i].clear();
	int at=1; while(at<n) { int clen=1; int prv=0; REP(i,clen) { adj[prv].PB(at); adj[at].PB(prv); prv=at; ++at; } }
	printf("%d\n",solve());
}

int main() {
	run();
	//stress2();
	return 0;
}
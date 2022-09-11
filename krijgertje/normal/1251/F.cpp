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

const int MOD=998244353;
const int PRIMROOT=3;
void mlt(int &a,int b) { a=(ll)a*b%MOD; }
int pw(int x,int n) { int ret=1; while(true) { if(n&1) mlt(ret,x); if((n>>=1)==0) return ret; mlt(x,x); } }

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
	void mult(const int *a,int na,const int *b,int nb,int *c,int nc) {
		int sz=1; while(sz<na+nb-1) sz*=2;
		vector<int> A(sz,0),B(sz,0);
		REP(i,na) A[i]=a[i]; REP(i,nb) B[i]=b[i];
		fft(A.data(),sz,false); fft(B.data(),sz,false); REP(i,sz) A[i]=(ll)A[i]*B[i]%MOD; fft(A.data(),sz,true);
		REP(i,nc) c[i]=i<sz?A[i]:0;
	}
};
 
NTT ntt;

const int MAXWHITE=300000;
const int MAXRED=5;
const int MAXQ=300000;
const int MAXN=MAXWHITE;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

int nwhite,nred;
int white[MAXWHITE];
int red[MAXRED];
int nq;
int qperim[MAXQ],qans[MAXQ];

int inv[MAXN+1];
int fac[MAXN+1];
int ifac[MAXN+1];
int p2[MAXN+1];

int choose(int n,int k) {
	if(k<0||k>n) return 0;
	return (ll)fac[n]*ifac[k]%MOD*ifac[n-k]%MOD;
}

vector<int> mult(const vector<int> &a,const vector<int> &b) {
	vector<int> ret(SZ(a)+SZ(b)-1,0);
	ntt.mult(a.data(),SZ(a),b.data(),SZ(b),ret.data(),SZ(ret));
	//REPSZ(i,a) REPSZ(j,b) inc(ret[i+j],(ll)a[i]*b[j]%MOD);
	return ret;
}

void solve() {
	inv[1]=1; FORE(i,2,MAXN) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	fac[0]=1; FORE(i,1,MAXN) fac[i]=(ll)fac[i-1]*i%MOD;
	ifac[0]=1; FORE(i,1,MAXN) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;
	p2[0]=1; FORE(i,1,MAXN) p2[i]=(ll)p2[i-1]*2%MOD;

	sort(white,white+nwhite);
	sort(red,red+nred);

	REP(i,nq) qans[i]=0;
	REP(i,nred) {
		int a=0,b=0;
		for(int l=0,r=l;l<nwhite;l=r) {
			while(r<nwhite&&white[r]==white[l]) ++r;
			int cnt=r-l,val=white[l];
			if(val<red[i]) { if(cnt==1) ++b; else ++a; }
		}
		//printf("%d: %d/%d\n",red[i],a,b);
		vector<int> apol(2*a+1); REPE(k,2*a) apol[k]=choose(2*a,k);
		vector<int> bpol(b+1); REPE(k,b) bpol[k]=(ll)choose(b,k)*p2[k]%MOD;
		vector<int> cpol=mult(apol,bpol);
		//printf("bpol:"); REPSZ(k,bpol) printf(" %d",bpol[k]); puts("");
		//printf("cpol:"); REPSZ(k,cpol) printf(" %d",cpol[k]); puts("");
		REP(j,nq) {
			int rem=qperim[j]-2*red[i]-2;
			int cur=rem%2==0&&0<=rem/2&&rem/2<SZ(cpol)?cpol[rem/2]:0;
			inc(qans[j],cur);
		}

	}
}

void run() {
	scanf("%d%d",&nwhite,&nred);
	REP(i,nwhite) scanf("%d",&white[i]);
	REP(i,nred) scanf("%d",&red[i]);
	scanf("%d",&nq);
	REP(i,nq) scanf("%d",&qperim[i]);
	solve();
	REP(i,nq) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}
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

const int MAXN=100000;
const int MAXLGN=17; // MAXN<=(1<<MAXLGN)

int n,a,b;

int tmp[2<<MAXLGN];
NTT ntt;

int calcstirling(int n,int k) {
	int sz=1; while(n>sz) sz*=2;
	REP(i,sz) if(i<n) tmp[2*i+0]=i,tmp[2*i+1]=1; else tmp[2*i+0]=1,tmp[2*i+1]=0;
	for(int hlen=1;hlen<sz;hlen*=2) {
		for(int i=0;i<sz;i+=2*hlen) {
			ntt.mult(tmp+2*i,2*hlen,tmp+2*i+2*hlen,2*hlen,tmp+2*i,4*hlen);
		}
	}
	//printf("stirling: "); REP(i,2*sz) printf(" %d",tmp[i]); puts("");
	return tmp[k];
}

int inv[MAXN+1];
int fac[MAXN+1];
int ifac[MAXN+1];

int C(int n,int k) {
	inv[1]=1; FORE(i,2,n) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	fac[0]=1; FORE(i,1,n) fac[i]=(ll)fac[i-1]*i%MOD;
	ifac[0]=1; FORE(i,1,n) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;
	return (ll)fac[n]*ifac[k]%MOD*ifac[n-k]%MOD;
}

int solve() {
	if(a<1||b<1||a+b-2>n-1) return 0;

	int x=calcstirling(n-1,a+b-2);
	int y=C(a+b-2,a-1);

	return (ll)x*y%MOD;
}

void run() {
	scanf("%d%d%d",&n,&a,&b);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
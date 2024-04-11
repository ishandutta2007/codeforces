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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MOD=998244353;
const int PRIMROOT=3;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
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
	void power(int *a,int na,int b,int *c,int nc) {
		int sz=1; while(sz<1+(na-1)*b) sz*=2;
		vector<int> A(sz,0);
		REP(i,na) A[i]=a[i];
		fft(A.data(),sz,false); REP(i,sz) A[i]=pw(A[i],b); fft(A.data(),sz,true);
		REP(i,nc) c[i]=i<sz?A[i]:0;
	}
};


const int MAXN=200000;
const int MAXHAVE=10;
const int MAXHSUM=(MAXN/2)*(MAXHAVE-1);

int n,nhave;
int d[MAXHAVE];

int a[MAXHAVE];
int b[MAXHSUM+1];
NTT ntt;

int solve() {
	REP(i,MAXHAVE) a[i]=0; REP(i,nhave) a[d[i]]=1;
	ntt.power(a,MAXHAVE,n/2,b,MAXHSUM+1);
	int ret=0; REPE(i,MAXHSUM) inc(ret,(ll)b[i]*b[i]%MOD); return ret;
}

void run() {
	scanf("%d%d",&n,&nhave);
	REP(i,nhave) scanf("%d",&d[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
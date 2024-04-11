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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MOD = 998244353;
const int PRIMROOT = 3;
int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret*x%MOD; if ((n >>= 1) == 0) return ret; x = (ll)x*x%MOD; } }

struct NTT {
	void _init(int n, int &nlog, int &g, vector<int> &w) {
		assert((MOD - 1) % n == 0);
		g = pw(PRIMROOT, (MOD - 1) / n); nlog = 0; while ((1 << nlog) < n) ++nlog; if ((1 << nlog) != n) nlog = -1;
		w = vector<int>(n); w[0] = 1; FOR(i, 1, n) w[i] = (ll)w[i - 1] * g%MOD;
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
					int v = (ll)(*r)*(*w) % MOD;
					*r = (*l) - v; if (*r<0) *r += MOD;
					*l = (*l) + v; if (*l >= MOD) *l -= MOD;
					++l, ++r, w += step;
				}
			}
		}
		if (inv) reverse(fftw.begin() + 1, fftw.end());
		if (inv) { int mlt = pw(n, MOD - 2); REP(i, n) a[i] = (ll)a[i] * mlt%MOD; }
	}
	void mult(const int *a, int na, const int *b, int nb, int *c, int nc) {
		int sz = 1; while (sz<na + nb - 1) sz *= 2;
		vector<int> A(sz, 0), B(sz, 0);
		REP(i, na) A[i] = a[i]; REP(i, nb) B[i] = b[i];
		fft(A.data(), sz, false); fft(B.data(), sz, false); REP(i, sz) A[i] = (ll)A[i] * B[i] % MOD; fft(A.data(), sz, true);
		REP(i, nc) c[i] = i<sz ? A[i] : 0;
	}
};

const int MAXN=20000;
const int MAXQ=10;
const int MAXS=4*MAXN;


int n,tupsz;
int a[MAXN];
int nq;
int qv[MAXQ],ql[MAXQ],qr[MAXQ],qd[MAXQ],qans[MAXQ];

int inv[MAXN+1];
int fac[MAXN+1];
int ifac[MAXN+1];
int choose(int n,int k) { if(k<0||k>n) return 0; return (ll)fac[n]*ifac[k]%MOD*ifac[n-k]%MOD; }

int b[MAXN];
vector<int> sprod[MAXS];
NTT ntt;

vector<int> mlt(const vector<int> &a,const vector<int> &b) {
	if(SZ(a)==0||SZ(b)==0) return vector<int>();
	//vector<int> ret(SZ(a)+SZ(b)-1,0); REPSZ(i,a) REPSZ(j,b) ret[i+j]=(ret[i+j]+(ll)a[i]*b[j])%MOD; return ret;
	vector<int> ret(SZ(a)+SZ(b)-1,0); ntt.mult(a.data(),SZ(a),b.data(),SZ(b),ret.data(),SZ(ret)); return ret;
}

void sinit(int x,int l,int r) {
	if(l==r) {
		sprod[x].clear(); sprod[x].PB(1); sprod[x].PB(b[l]);
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		sprod[x]=mlt(sprod[2*x+1],sprod[2*x+2]);
	}
}

void sappend(int x,int l,int r,int L,int R,vector<int> &LST) {
	if(L<=l&&r<=R) {
		LST.PB(x);
	} else {
		int m=l+(r-l)/2;
		if(L<=m) sappend(2*x+1,l,m,L,R,LST);
		if(m+1<=R) sappend(2*x+2,m+1,r,L,R,LST);
	}
}

vector<int> add(const vector<int> &a,int b) {
	b=(b%MOD+MOD)%MOD; int n=SZ(a)-1;
	vector<int> bpw(n+1); bpw[0]=1; FORE(i,1,n) bpw[i]=(ll)bpw[i-1]*b%MOD;
	//vector<int> ret(n+1,0); REPE(k,n) REPE(x,k) ret[k]=(ret[k]+(ll)choose(n-x,k-x)*a[x]%MOD*bpw[k-x])%MOD; return ret;
	vector<int> c(n+1); REPE(x,n) c[x]=(ll)fac[n-x]*a[x]%MOD;
	vector<int> d(n+1); REPE(y,n) d[y]=(ll)ifac[y]*bpw[y]%MOD;
	vector<int> ret=mlt(c,d); ret.resize(n+1); REPE(k,n) ret[k]=(ll)ret[k]*ifac[n-k]%MOD; return ret;
}

void solve() {
	inv[1]=1; FORE(i,2,n) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	fac[0]=1; FORE(i,1,n) fac[i]=(ll)fac[i-1]*i%MOD;
	ifac[0]=1; FORE(i,1,n) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;
	
	REP(i,n) b[i]=(-a[i]%MOD+MOD)%MOD;
	sinit(0,0,n-1);
	
	REP(i,nq) {
		vector<int> outidx;
		vector<int> inidx;
		if(ql[i]!=0) sappend(0,0,n-1,0,ql[i]-1,outidx);
		sappend(0,0,n-1,ql[i],qr[i],inidx);
		if(qr[i]!=n-1) sappend(0,0,n-1,qr[i]+1,n-1,outidx);
		sort(outidx.begin(),outidx.end(),[&](const int &x,const int &y) { return SZ(sprod[x])<SZ(sprod[y]); });
		sort( inidx.begin(), inidx.end(),[&](const int &x,const int &y) { return SZ(sprod[x])<SZ(sprod[y]); });
		//printf("out:"); REPSZ(j,outidx) { printf(" ["); int idx=outidx[j]; REPSZ(k,sprod[idx]) { if(k!=0) printf(","); printf("%d",sprod[idx][k]); } printf("]"); } puts("");
		//printf(" in:"); REPSZ(j, inidx) { printf(" ["); int idx= inidx[j]; REPSZ(k,sprod[idx]) { if(k!=0) printf(","); printf("%d",sprod[idx][k]); } printf("]"); } puts("");
		vector<int> out(1,1); REPSZ(j,outidx) out=mlt(out,sprod[outidx[j]]);
		vector<int>  in(1,1); REPSZ(j, inidx)  in=mlt( in,sprod[ inidx[j]]);
		//printf("out: ["); REPSZ(k,out) { if(k!=0) printf(","); printf("%d",out[k]); } printf("]\n");
		//printf(" in: ["); REPSZ(k, in) { if(k!=0) printf(","); printf("%d", in[k]); } printf("]\n");
		//printf("out+%d in+%d\n",qv[i],qv[i]-qd[i]);
		out=add(out,qv[i]);
		in=add(in,qv[i]-qd[i]);
		//printf("out: ["); REPSZ(k,out) { if(k!=0) printf(","); printf("%d",out[k]); } printf("]\n");
		//printf(" in: ["); REPSZ(k, in) { if(k!=0) printf(","); printf("%d", in[k]); } printf("]\n");
		vector<int> res=mlt(out,in);
		//printf("res: ["); REPSZ(k,res) { if(k!=0) printf(","); printf("%d",res[k]); } printf("]\n");
		qans[i]=res[tupsz];
		//puts("");
	}
}

void run() {
	scanf("%d%d",&n,&tupsz);
	REP(i,n) scanf("%d",&a[i]);
	scanf("%d",&nq);
	REP(i,nq) { int kind; scanf("%d%d",&kind,&qv[i]); if(kind==1) scanf("%d%d",&ql[i],&qd[i]),--ql[i],qr[i]=ql[i],qd[i]-=a[ql[i]]; if(kind==2) scanf("%d%d%d",&ql[i],&qr[i],&qd[i]),--ql[i],--qr[i]; }
	solve();
	REP(i,nq) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}
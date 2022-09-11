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

const int MAXN=200000;

int n;
int a[MAXN];

int b[MAXN],nb;


queue<vector<int>> q1;
queue<vector<int>> q2;

vector<int> retrieve() { vector<int> ret; if(SZ(q1)>0&&(SZ(q2)==0||SZ(q1.front())<SZ(q2.front()))) { ret=q1.front(); q1.pop(); } else { ret=q2.front(); q2.pop(); } return ret; }

vector<int> mult(const vector<int> &a,const vector<int> &b) {
	if(SZ(a)==0||SZ(b)==0) return vector<int>();
	vector<int> c(SZ(a)+SZ(b)-1,0);
	//REPSZ(i,a) REPSZ(j,b) c[i+j]=(c[i+j]+(ll)a[i]*b[j])%MOD;
	ntt.mult(a.data(),SZ(a),b.data(),SZ(b),c.data(),SZ(c));
	return c;
}

int solve() {
	sort(a,a+n);
	nb=0;
	for(int l=0,r=l;l<n;l=r) {
		while(r<n&&a[r]==a[l]) ++r;
		b[nb++]=r-l;
	}
	sort(b,b+nb);
	//printf("b:"); REP(i,nb) printf(" %d",b[i]); puts("");

	q1=queue<vector<int>>();
	q2=queue<vector<int>>();
	REP(i,nb) q1.push(vector<int>(b[i]+1,1));
	while(SZ(q1)+SZ(q2)>1) {
		vector<int> x1=retrieve(); 
		vector<int> x2=retrieve();
		vector<int> x3=mult(x1,x2);
		q2.push(x3);
	}
	vector<int> ans=retrieve();
	//printf("ans:"); REPSZ(i,ans) printf(" %d",ans[i]); puts("");
	assert(SZ(ans)==n+1);
	return ans[n/2];
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
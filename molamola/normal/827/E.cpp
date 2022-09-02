#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

vector <int> A, B, C;
char S[500050];
int pos[500050];

#include <complex>
namespace FFT{
	// blog.myungwoo.kr/54
	typedef complex<double> base;
	typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
 
	const double C_PI = acos(-1);
 
	void fft(vector <base> &a, bool invert){
		int n = sz(a);
		for(int i=0,j=0;i<n;++i) {
			if(i>j) swap(a[i],a[j]);
			for(int k=n>>1;(j^=k)<k;k>>=1);
		}
		for (int len=2;len<=n;len<<=1){
			double ang = 2*C_PI/len*(invert?-1:1);
			base wlen(cos(ang), sin(ang));
			for (int i=0;i<n;i+=len){
				base w(1);
				for (int j=0;j<len/2;j++){
					if((j & 511) == 511)w = base(cos(ang * j), sin(ang * j));	//     . cos, sin     
					base u = a[i+j], v = a[i+j+len/2]*w;
					a[i+j] = u+v;
					a[i+j+len/2] = u-v;
					w *= wlen;
				}
			}
		}
		if (invert){
			for (int i=0;i<n;i++) a[i] /= n;
		}
	}
 
	void multiply(const vector<int> &a,const vector<int> &b,vector<int> &res){
		vector <base> fa(all(a)), fb(all(b));
		int n = 1;
		while (n < max(sz(a),sz(b))) n <<= 1; n <<= 1;
		fa.resize(n); fb.resize(n);
		fft(fa,false); fft(fb,false);
		for (int i=0;i<n;i++) fa[i] *= fb[i];
		fft(fa,true);
		res.resize(n);
		for (int i=0;i<n;i++) res[i] = ((int)(fa[i].real()+(fa[i].real()>0?0.5:-0.5)));
	}
 
	void multiply_with_modulo(const vector<int> &a,const vector<int> &b,vector<int> &res, const int MOD){
		int n = 1;
		while (n < max(sz(a),sz(b))) n <<= 1; n <<= 1;
		vector <base> A(n), B(n);
		int L_BLOCK = 15;	//2^L_BLOCK ~= sqrt(MOD).
		for(int i=0;i<n;i++) A[i] = (i < sz(a) ? base(a[i] & ((1<<L_BLOCK)-1), a[i] >> L_BLOCK) : base(0));
		for(int i=0;i<n;i++) B[i] = (i < sz(b) ? base(b[i] & ((1<<L_BLOCK)-1), b[i] >> L_BLOCK) : base(0));
		fft(A, false); fft(B, false);
		vector <base> f1(n), f2(n), f3(n), f4(n);
		for(int i=0;i<n;i++) {
			int j=(n-i)&(n-1);
			f2[i]=(A[i]+conj(A[j]))*base(0.5,0);
			f1[i]=(A[i]-conj(A[j]))*base(0,-0.5);
			f4[i]=(B[i]+conj(B[j]))*base(0.5,0);
			f3[i]=(B[i]-conj(B[j]))*base(0,-0.5);
		}
		for(int i=0;i<n;i++) {
			A[i]=f1[i]*f3[i]+f1[i]*f4[i]*base(0,1);
			B[i]=f2[i]*f4[i]*base(0,1)+f2[i]*f3[i];
		}
		fft(A, true); fft(B, true);
		res.resize(n);
		for(int i=0;i<n;i++) {
			ll g1=(ll)(A[i].real()+0.5) % MOD;	//A[i].real > 0  .
			ll g2=(ll)(A[i].imag()+0.5) % MOD;
			ll g3=(ll)(B[i].real()+0.5) % MOD;
			ll g4=(ll)(B[i].imag()+0.5) % MOD;
			res[i] = (g4 + ((g2+g3)<<L_BLOCK) + (g1<<(L_BLOCK<<1))) % MOD;
		}
	}
 
	void multiply_big(const vector<int> &a,const vector<int> &b, vector <ll> &res){
		//      
		//  long long  
		int n = 1;
		while (n < max(sz(a),sz(b))) n <<= 1; n <<= 1;
		vector <base> A(n), B(n);
		int L_BLOCK = 10;
		for(int i=0;i<n;i++) A[i] = (i < sz(a) ? base(a[i] & ((1<<L_BLOCK)-1), a[i] >> L_BLOCK) : base(0));
		for(int i=0;i<n;i++) B[i] = (i < sz(b) ? base(b[i] & ((1<<L_BLOCK)-1), b[i] >> L_BLOCK) : base(0));
		fft(A, false); fft(B, false);
		vector <base> f1(n), f2(n), f3(n), f4(n);
		for(int i=0;i<n;i++) {
			int j=(n-i)&(n-1);
			f2[i]=(A[i]+conj(A[j]))*base(0.5,0);
			f1[i]=(A[i]-conj(A[j]))*base(0,-0.5);
			f4[i]=(B[i]+conj(B[j]))*base(0.5,0);
			f3[i]=(B[i]-conj(B[j]))*base(0,-0.5);
		}
		for(int i=0;i<n;i++) {
			A[i]=f1[i]*f3[i]+f1[i]*f4[i]*base(0,1);
			B[i]=f2[i]*f4[i]*base(0,1)+f2[i]*f3[i];
		}
		fft(A, true); fft(B, true);
		res.resize(n);
		for(int i=0;i<n;i++) {
			ll g1=(ll)(A[i].real()+0.5);
			ll g2=(ll)(A[i].imag()+0.5);
			ll g3=(ll)(B[i].real()+0.5);
			ll g4=(ll)(B[i].imag()+0.5);
			res[i] = (g4 + ((g2+g3)<<(L_BLOCK)) + (g1<<(L_BLOCK<<1)));
		}
	}
}

void solve(){
	int n; scanf("%d%s", &n, S);
	A.resize(n); B.resize(n);
	rep(i, n) {
		if(S[i] == 'V') A[i] = 1;
		else A[i] = 0;
		if(S[i] == 'K') B[n-1-i] = 1;
		else B[n-1-i] = 0;
	}
	C.clear();
	FFT::multiply(A, B, C);
	for(int i=0;i<=n;i++) pos[i] = 0;
	for(int i=0;i<sz(C);i++) if(C[i] > 0) {
		int f = abs(n-1-i);
		pos[f] = 1;
	}
	vector <int> ans;
	for(int i=1;i<=n;i++) {
		int ok = 1;
		for(int j=i;j<=n;j+=i) if(pos[j]){ ok = 0;break;}
		if(ok) ans.pb(i);
	}
	printf("%d\n", sz(ans));
	for(int e : ans) printf("%d ", e); puts("");
}

int main(){
	int Tc = 1; scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
};
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=998244353;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int P = 998244353;

const int MaxN = 100000;
const int MaxM = MaxN * 2;

const int N=301000;
const int FFT_G = 3;
const int MaxFFTN = 262144;

int preGPow[MaxFFTN],tn;

void init(int l) {
	tn = 1;
	while (tn < l) tn <<= 1;
	int curG = powmod(FFT_G, (P - 1) / tn);
	preGPow[0] = 1;
	for (int i = 1; i < tn; i++)
		preGPow[i] = (ll)preGPow[i - 1] * curG % P;
}
void fft(int *a, int n, int s, int *out)
{
	if (n == 1)
	{
		out[0] = a[0];
		return;
	}

	int m = n >> 1;
	fft(a, m, s + 1, out);
	fft(a + (1 << s), m, s + 1, out + m);
	for (int i = 0, *po = out, *pe = out + m; i < m; i++, pe++, po++)
	{
		int o = *po, e = (ll)*pe * preGPow[i << s] % P;
		*po = (o + e) % P;
		*pe = (o + P - e) % P;
	}
}

void ifft(int *a,int *out) {
	fft(a,tn,0,out);
	ll revTN = powmod(tn, P - 2);
	for (int i = 0; i < tn; i++) out[i]=out[i]*revTN%mod;
}
int a[N],b[N],c[N],fa[N],fb[N],fc[N],ta[N],tb[N],n,k;
void solve(int n) {
	if (n==1) {
		b[0]=1;
		return;
	} else if (n%2==0) {
		// (b*y+a)^2
		solve(n/2);
		fft(a,tn,0,ta);
		fft(b,tn,0,tb);
		rep(i,0,tn) fa[i]=(ll)ta[i]*ta[i]%mod,fb[i]=2ll*ta[i]*tb[i]%mod,fc[i]=(ll)tb[i]*tb[i]%mod;
		reverse(preGPow + 1, preGPow + tn);
		ifft(fa,a); ifft(fb,b); ifft(fc,c);
		reverse(preGPow + 1, preGPow + tn);
		rep(i,0,tn) {
			a[i+1]=(a[i+1]+c[i])%mod;
			b[i]=(b[i]+c[i])%mod;
			b[i+1]=(b[i+1]+c[i])%mod;
		}
		rep(i,k+1,tn) a[i]=b[i]=0;
//		rep(i,0,tn) printf("%d ",a[i]); puts("");
//		rep(i,0,tn) printf("%d ",b[i]); puts("");
	} else {
		solve(n-1);
		rep(i,0,tn) c[i]=b[i],b[i]=a[i],a[i]=0;
		rep(i,0,tn) {
			a[i+1]=(a[i+1]+c[i])%mod;
			b[i]=(b[i]+c[i])%mod;
			b[i+1]=(b[i+1]+c[i])%mod;
		}
		rep(i,k+1,tn) a[i]=b[i]=0;
//		rep(i,0,tn) printf("%d ",a[i]); puts("");
//		rep(i,0,tn) printf("%d ",b[i]); puts("");
	}
}
int main() {
	scanf("%d%d",&n,&k);
	init((k+1)*2);
	solve(n);
	rep(i,0,tn) {
		a[i+1]=(a[i+1]+b[i])%mod;
		a[i]=(a[i]+b[i])%mod;
	}
	rep(i,1,k+1) printf("%d ",a[i]);
}
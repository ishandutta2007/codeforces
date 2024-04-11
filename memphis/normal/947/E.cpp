#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#define REP(i, x, y) for(int i = (int)x; i <= (int)y; i ++)
#define FOR(i, x, y) for(int i = (int)x; i <  (int)y; i ++)
#define PER(i, x, y) for(int i = (int)x; i >= (int)y; i --)
using namespace std;
typedef long long LL;
const int N = 300005;
const int P = 998244353;
const int inf = 1e9;
const LL Inf = 1e18;

int Pow(int x, LL y, int p){
	int an = 1;
	for(; y; y >>= 1, x = (LL)x * x % p) if(y & 1) an = (LL)an * x % p;
	return an;
}

void renew(int &x, int y){
	x += y;
	if(x < 0) x += P;
	else if(x >= P) x -= P;
}

template<typename T> inline void chkmin(T &a, const T &b) {if(a > b) a = b;}
template<typename T> inline void chkmax(T &a, const T &b) {if(a < b) a = b;}

int n,p[N],rev[N];
LL k;
const int G=3;
int w[2][N],tn,tl;

void dft(int *a,int f){
	FOR(i,0,tn) if(i<rev[i]) swap(a[i],a[rev[i]]);

	for(int i=1;i<tn;i<<=1)
	for(int j=0,t=tn/(i<<1);j<tn;j+=i<<1)
	for(int k=0,l=0;k<i;k++,l+=t){
		int x=a[j+k];
		int y=(LL)a[j+k+i]*w[f][l]%P;
		a[j+k]=(x+y)%P;
		a[j+k+i]=(x+P-y)%P;
	}

	if(f){
		int rn=Pow(tn,P-2,P);
		FOR(i,0,tn) a[i]=(LL)a[i]*rn%P;
	}
}

int A[N],B[N],fac[N],ifac[N],T[N];

void prep(int n){
	for(tn=1,tl=-1;tn<=(n*2);tn<<=1,tl++);

	w[0][0]=w[1][0]=1;
	int ng=Pow(3,(P-1)/tn,P);
	FOR(i,1,tn){
		w[0][i]=(LL)w[0][i-1]*ng%P;
		w[1][i]=Pow(w[0][i],P-2,P);
		rev[i]=(rev[i>>1]>>1)|((i&1)<<tl);
	}
}

int main(){
	scanf("%d%I64d",&n,&k);
	REP(i,0,n) scanf("%d",p+i);
	reverse(p,p+n+1);
	prep(n);


	fac[0]=ifac[0]=1;
	REP(i,1,n) fac[i]=(LL)fac[i-1]*i%P;
	REP(i,1,n) ifac[i]=Pow(fac[i],P-2,P);

	memset(A,0,sizeof A);
	memset(B,0,sizeof B);
	REP(i,0,n) A[i]=(LL)p[n-i]*fac[i]%P,B[n-i]=ifac[i];
	dft(A,0); dft(B,0);
	FOR(i,0,tn) A[i]=(LL)A[i]*B[i]%P;
	dft(A,1);

	memset(T,0,sizeof T);
	REP(i,0,n) T[i]=(LL)A[i+n]*ifac[i]%P;
	FOR(i,0,tn) T[i]=(LL)T[i]*Pow(Pow(i+1,P-2,P),k,P)%P;

	memset(A,0,sizeof A);
	memset(B,0,sizeof B);
	REP(i,0,n) A[i]=(LL)T[i]*fac[i]%P,B[n-i]=(i&1?P-ifac[i]:ifac[i]);
	dft(A,0); dft(B,0);
	FOR(i,0,tn) A[i]=(LL)A[i]*B[i]%P;
	dft(A,1);

	REP(i,0,n) T[n-i]=(LL)A[i+n]*ifac[i]%P;

	reverse(T,T+n+1);
	REP(i,0,n){
		printf("%d ",T[i]);
	}
	puts("");
}
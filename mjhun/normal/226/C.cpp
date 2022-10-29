#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

ll m,a,b,k;
ll r=1;

void doit(ll w){
	if(w==0)return;
	if(b/w-(a-1)/w>=k)r=max(r,w);
}

ll x[2][2];

void mmul(ll rr[2][2], ll a[2][2], ll b[2][2]){
	ll r[2][2];
	fore(i,0,2)fore(j,0,2){
		r[i][j]=0;
		fore(k,0,2)r[i][j]+=(a[i][k]*b[k][j])%m,r[i][j]%=m;
	}
	fore(i,0,2)fore(j,0,2)rr[i][j]=r[i][j];
}

ll fib(ll e){
	ll a[2][2],r[2][2];
	r[0][0]=r[1][1]=1;r[0][1]=r[1][0]=0;
	a[0][0]=0;a[0][1]=a[1][0]=a[1][1]=1;
	while(e){
		if(e&1)mmul(r,r,a);
		e>>=1;
		mmul(a,a,a);
	}
	return r[0][1];
}

int main(){
	scanf("%lld%lld%lld%lld",&m,&a,&b,&k);
	if(a>1)doit(a-1);
	ll k=2;
	while((a-1)/k<(a-1)/(k-1)){doit((a-1)/k);k++;}
	doit(b);
	k=2;
	while(b/k<b/(k-1)){doit(b/k);k++;}
	fore(i,1,b/k+1)doit(i);
	printf("%lld\n",fib(r));
	return 0;
}
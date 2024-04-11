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
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

#define MOD 998244353

ll pm(ll a, ll e){
	ll r=1;
	while(e){
		if(e&1)r=r*a%MOD;
		e>>=1;
		a=a*a%MOD;
	}
	return r;
}

ll f[1000005];

ll c(int n, int k){
	return f[n]*pm(f[k],MOD-2)%MOD*pm(f[n-k],MOD-2)%MOD;
}

int n;ll r;

int main(){
	f[0]=1;
	fore(i,1,1000005)f[i]=f[i-1]*i%MOD;
	scanf("%d",&n);
	fore(i,1,n+1){
		ll t=c(n,i)*pm(3,1LL*n*(n-i)+i)*2%MOD;
		if(i&1)r+=t;
		else r+=MOD-t;
		if(r>=MOD)r-=MOD;
	}
	fore(i,1,n+1){
		ll t=3*c(n,i)*((pm(3,1LL*(n-i)*n)-pm(pm(3,n-i)-1,n)+MOD)%MOD)%MOD;
		if(i&1)r+=MOD-t;
		else r+=t;
		if(r>=MOD)r-=MOD;
	}
	printf("%lld\n",r);
	return 0;
}
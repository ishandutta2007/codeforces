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

ll sum(ll a, ll b){
	a+=b;
	if(a>=MOD)a-=MOD;
	return a;
}
ll sub(ll a, ll b){
	a-=b;
	if(a<0)a+=MOD;
	return a;
}
ll mul(ll a, ll b){return (a*b)%MOD;}
ll pm(ll a, ll e){
	ll r=1;
	while(e){
		if(e&1)r=mul(r,a);
		e>>=1;
		a=mul(a,a);
	}
	return r;
}
ll inv(ll a){return pm(a,MOD-2);}

ll f[200005];

ll comb(int n, int k){
	ll r=f[n];
	r=mul(r,inv(f[k]));
	r=mul(r,inv(f[n-k]));
	return r;
}

int n,q;ll k,r;
int h[200005];

int main(){
	f[0]=1;
	fore(i,1,200005)f[i]=mul(f[i-1],i);
	scanf("%d%lld",&n,&k);
	fore(i,0,n)scanf("%d",h+i);
	if(k==1){puts("0");return 0;}
	fore(i,0,n)if(h[i]==h[(i+1)%n])q++;
	n-=q;
	fore(i,0,n+1){ // igual
		int t=n-i;
		ll w;
		if(t%2)w=pm(2,t-1);
		else w=mul(sub(pm(2,t),comb(t,t/2)),inv(2));
		r=sum(r,mul(mul(w,comb(n,i)),pm(k-2,i)));
	}
	r=mul(r,pm(k,q));
	printf("%lld\n",r);
	return 0;
}
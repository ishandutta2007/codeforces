#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define fst first
#define snd second
using namespace std;
typedef long long LL;
typedef long long ll;
ll gcd(ll a, ll b){return a?gcd(b%a,a):b;}
ll mulmod(ll a, ll b, ll m) {
	ll r=a*b-(ll)((long double)a*b/m+.5)*m;
	return r<0?r+m:r;
}
ll expmod(ll b, ll e, ll m){
	if(!e)return 1;
	ll q=expmod(b,e/2,m);q=mulmod(q,q,m);
	return e&1?mulmod(b,q,m):q;
}
bool is_prime_prob(ll n, int a){
	if(n==a)return true;
	ll s=0,d=n-1;
	while(d%2==0)s++,d/=2;
	ll x=expmod(a,d,n);
	if((x==1)||(x+1==n))return true;
	fore(_,0,s-1){
		x=mulmod(x,x,n);
		if(x==1)return false;
		if(x+1==n)return true;
	}
	return false;
}
bool rabin(ll n){ // true iff n is prime
	if(n==1)return false;
	int ar[]={2,3,5,7,11,13,17,19,23};
	fore(i,0,9)if(!is_prime_prob(n,ar[i]))return false;
	return true;
}
const int MAXP=1e6+1; // sieve size
int sv[MAXP]; // sieve
ll add(ll a, ll b, ll m){return (a+=b)<m?a:a-m;}
ll rho(ll n){
    static ll s[MAXP];
    while(1){
    	ll x=rand()%n,y=x,c=rand()%n;
    	ll *px=s,*py=s,v=0,p=1;
    	while(1){
    		*py++=y=add(mulmod(y,y,n),c,n);
    		*py++=y=add(mulmod(y,y,n),c,n);
    		if((x=*px++)==y)break;
    		ll t=p;
    		p=mulmod(p,abs(y-x),n);
    		if(!p)return gcd(t,n);
    		if(++v==26){
    			if((p=gcd(p,n))>1&&p<n)return p;
    			v=0;
    		}
    	}
    	if(v&&(p=gcd(p,n))>1&&p<n)return p;
    }
}
void init_sv(){
	fore(i,2,MAXP)if(!sv[i])for(ll j=i;j<MAXP;j+=i)sv[j]=i;
}
void fact(ll n, map<ll,int>& f){ // call init_sv first!!!
	for(auto&& p:f){
		while(n%p.fst==0){
			p.snd++;
			n/=p.fst;
		}
	}
	if(n<MAXP)while(n>1)f[sv[n]]++,n/=sv[n];
	else if(rabin(n))f[n]++;
	else {ll q=rho(n);fact(q,f);fact(n/q,f);}
}
ll n;
map<ll,int> f;
int main() {
	init_sv();
	int m, mod = 998244353;
	scanf("%d", &m);
	while(m--) {
		scanf("%lld", &n);
		fact(n,f);
	}
	//sort(p, p + cnt);
	int ans = 1;
	for(auto p:f)ans=ans*(p.snd+1LL)%mod;
	//for(int i = 0; i < cnt; ) {
	//	int ctr = 0;
	//	for(LL pp = p[i]; i < cnt && p[i] == pp; ++i, ++ctr);
	//	ans = ans * (ctr + 1LL) % mod;
	//}
	printf("%d\n", ans);
	return 0;
}
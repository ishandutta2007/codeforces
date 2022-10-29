#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){return a?gcd(b%a,a):b;}
ll mulmod(ll a, ll b, ll m) {
	if(!b)return 0;
	ll q=mulmod(a,b/2,m);q=(q+q)%m;
	return b&1?(q+a)%m:q;
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
ll rho(ll n){
    if(!(n&1))return 2;
    ll x=2,y=2,d=1;
    ll c=rand()%n+1;
    while(d==1){
        x=(mulmod(x,x,n)+c)%n;
        y=(mulmod(y,y,n)+c)%n;
        y=(mulmod(y,y,n)+c)%n;
        if(x>=y)d=gcd(x-y,n);
        else d=gcd(y-x,n);
    }
    return d==n?rho(n):d;
}
void fact(ll n, map<ll,int>& f){
	if(n==1)return;
	if(rabin(n)){f[n]++;return;}
	ll q=rho(n);fact(q,f);fact(n/q,f);
}

ll a,b;

int main(){
	scanf("%lld%lld",&a,&b);
	map<ll,int> f;
	fact(a,f);
	vector<ll> v;
	for(auto p:f)v.pb(p.fst);
	ll r=0;
	while(b){
		ll g=gcd(a,b);
		a/=g;b/=g;
		ll z=0;
		for(ll p:v)if(a%p==0)z=max(z,b/p*p);
		r+=b-z;b=z;
	}
	printf("%lld\n",r);
	return 0;
}
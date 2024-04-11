#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define INF 1000000000000000001LL
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
	while(b){
		ll c=a%b;
		a=b;b=c;
	}
	return a;
}

ll add(ll a, ll b){return min(a+b,INF);}
ll mul(ll a, ll b){
	ll r=0;
	while(b){
		if(b&1)r=add(r,a);
		b>>=1;
		a=add(a,a);
	}
	return r;
}

int n;ll k;
vector<ll> a;

ll comb(ll n, ll k){
	assert(k>=0&&k<=n);
	if(k==0)return 1;
	if(n-k<k)k=n-k;
	vector<ll> d;
	fore(i,2,k+1)d.pb(i);
	ll r=1;
	for(ll i=n-k+1;i<=n;++i){
		ll w=i;
		fore(j,0,d.size()){
			ll g=gcd(d[j],w);
			d[j]/=g;
			w/=g;
		}
		r=mul(r,w);
	}
	for(ll z:d)assert(z==1);
	return r;
}

bool can(ll q){
	ll s=0;
	fore(i,0,n)s=add(s,mul(comb(q-2+n-i,q-1),a[i]));
	//printf("%lld %lld\n",q,s);
	return s>=k;
}

int main(){
	scanf("%d%lld",&n,&k);
	ll r=-1;
	fore(i,0,n){
		ll x;
		scanf("%lld",&x);
		if(x>=k)r=0;
		a.pb(x);
	}
	if(r==0){puts("0");return 0;}
	reverse(a.begin(),a.end());
	while(!a.back())a.pop_back();
	reverse(a.begin(),a.end());
	n=SZ(a);
	if(n>10){
		r=0;
		while(a[n-1]<k){
			fore(i,1,n)a[i]=add(a[i],a[i-1]);
			r++;
		}
	}
	else {
		ll s=1,e=INF+5;
		while(e-s>1){
			ll m=(s+e)/2;
			if(can(m-1))e=m;
			else s=m;
		}
		r=s;
	}
	printf("%lld\n",r);
	return 0;
}
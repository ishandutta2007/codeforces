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

#define INF (1LL<<61)

ll mul(ll a, ll b){
	if(INF/b<=a)return INF;
	return min(a*b,INF);
}

vector<pair<int,int> > w;

ll do2(ll n){ // piso de raiz
	ll s=0,e=1e9+7;
	while(e-s>1){
		ll m=(s+e)/2;
		if(m*m<=n)s=m;
		else e=m;
	}
	return s;
}

ll do3(ll n){
	ll s=0,e=1e6+7;
	while(e-s>1){
		ll m=(s+e)/2;
		if(m*m*m<=n)s=m;
		else e=m;
	}
	return s;
}

vector<ll> asd[64];

ll get(ll n, ll x){
	if(x==2)return do2(n);
	if(x==3)return do3(n);
	return upper_bound(asd[x].begin(),asd[x].end(),n)-asd[x].begin();
}

ll f(ll n){
	ll r=n-1;
	for(auto p:w){
		ll x=p.fst,t=p.snd;
		ll z=get(n,x);
		z=max(z-1,0LL);
		if(t)r-=z;
		else r+=z;
	}
	return r;
}

ll pw(ll a, ll b){
	ll r=1;
	fore(_,0,b){
		r=mul(r,a);
	}
	return r;
}

int main(){
	fore(i,2,61){
		int n=i,t=0;bool val=true;
		for(int j=2;n>1;j++)if(n%j==0){
			if(n%(j*j)==0){val=false;break;}
			t^=1;
			n/=j;
		}
		if(val)w.pb(mp(i,t));
		if(i>3){
			ll t=1;
			while(pw(t,i)<INF)asd[i].pb(pw(t,i)),t++;
		}
	}
	int tn;
	scanf("%d",&tn);
	while(tn--){
		ll n;
		scanf("%lld",&n);
		printf("%lld\n",f(n));
	}
	return 0;
}
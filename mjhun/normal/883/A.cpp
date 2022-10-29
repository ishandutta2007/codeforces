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

ll n,a,d;
int m;
set<ll> w;
ll z;
ll q; // cuantos entran

ll nxt(ll t){
	// primero >= t
	return (t+a-1)/a*a;
}

int main(){
	scanf("%lld%d%lld%lld",&n,&m,&a,&d);
	z=1LL*n*a;
	q=d/a+1;
	while(m--){
		ll t;
		scanf("%lld",&t);
		w.insert(t);
	}
	ll t=1;
	ll r=0;
	while(1){
		auto it=w.lower_bound(t);
		if(it==w.end()){
			ll s=nxt(t);
			if(s>z)break;
			r+=((z-s)/a+1+q-1)/q;
			break;
		}
		ll pt=t;
		t=*it;
		if(nxt(pt)<=z)t=min(t,nxt(pt));
		if(t==*it){
			r++;
			t+=d+1;
		}
		else {
			//ll e=nxt(*it)-a;
			ll e=min(nxt(*it)-a,z);
			assert(e>=t);
			r+=((e-t)/a+1+q-1)/q;
			t=e-(((e-t)/a+1+q-1)%q)*a+d+1;
		}
	}
	printf("%lld\n",r);
	return 0;
}
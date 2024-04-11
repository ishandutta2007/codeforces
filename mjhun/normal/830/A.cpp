#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n,k;ll x;
ll a[2048],b[2048];
multiset<ll> z;
vector<pair<ll,ll> > e;

bool can(ll w){
	z.clear();e.clear();
	fore(i,0,n)e.pb(mp(a[i],1LL<<60));
	fore(i,0,k){
		ll d=abs(b[i]-x);
		if(d>w)continue;
		e.pb(mp(b[i]-(w-d),b[i]+(w-d)+1));
	}
	sort(e.begin(),e.end());
	for(auto p:e){
		if(p.snd==(1LL<<60)){
			while(!z.empty()&&*z.begin()<=p.fst)z.erase(z.begin());
			if(z.empty())return false;
			z.erase(z.begin());
		}
		else {
			z.insert(p.snd);
		}
	}
	return true;
}

int main(){
	scanf("%d%d%lld",&n,&k,&x);
	fore(i,0,n)scanf("%lld",a+i);
	fore(i,0,k)scanf("%lld",b+i);
	sort(a,a+n);sort(b,b+k);
	ll s=0,e=1LL<<40;
	while(e-s>1){
		ll m=(s+e)/2;
		if(can(m-1))e=m;
		else s=m;
	}
	printf("%lld\n",s);
	return 0;
}
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

int n;
ll a[1<<19];
vector<ll> pos,neg;

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%lld",a+i);
	if(n==1){printf("%lld\n",a[0]);return 0;}
	fore(i,0,n){
		if(a[i]>0)pos.pb(a[i]);
		else neg.pb(a[i]);
	}
	sort(pos.begin(),pos.end());
	sort(neg.begin(),neg.end());
	ll r=-(1LL<<60);
	if(!neg.empty()){
		ll s=0;
		fore(i,0,SZ(neg)-1)s-=neg[i];
		s+=neg.back();
		for(ll t:pos)s+=t;
		r=max(r,s);
	}
	if(!pos.empty()){
		ll s=0;
		for(ll t:neg)s-=t;
		fore(i,1,SZ(pos))s+=pos[i];
		s-=pos[0];
		r=max(r,s);
	}
	if(!pos.empty()&&!neg.empty()){
		ll s=0;
		for(ll t:neg)s-=t;
		for(ll t:pos)s+=t;
		r=max(r,s);
	}
	printf("%lld\n",r);
	return 0;
}
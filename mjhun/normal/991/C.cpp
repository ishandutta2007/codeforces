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

ll n;

ll doit(ll k){
	ll s=0,m=n;
	while(m){
		ll t=min(m,k);
		s+=t;
		m-=t;
		m-=m/10;
	}
	return s;
}

int main(){
	scanf("%lld",&n);
	ll s=1,e=1LL<<59;
	while(e-s>1){
		ll m=(s+e)/2;
		if(2*doit(m-1)>=n)e=m;
		else s=m;
	}
	printf("%lld\n",s);
	return 0;
}
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

ll t,n,a,b,k;

bool can(ll t){
	ll w=min(a,t)*((n+1)/2)+min(b,t)*(n/2);
	return w>=t*k;
}

int main(){
	scanf("%lld%lld%lld%lld%lld",&t,&n,&a,&b,&k);
	ll s=0,e=t+1;
	while(e-s>1){
		ll m=(s+e)/2;
		if(can(m))s=m;
		else e=m;
	}
	printf("%lld\n",s);
	return 0;
}
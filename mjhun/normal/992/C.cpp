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

#define MOD 1000000007

ll pm(ll a, ll e){
	ll r=1;
	while(e){
		if(e&1)r=r*a%MOD;
		e>>=1;
		a=a*a%MOD;
	}
	return r;
}

int main(){
	ll k,t;
	scanf("%lld%lld",&k,&t);
	if(k==0)puts("0");
	else printf("%lld\n",(k%MOD*pm(2,t+1)%MOD+MOD-pm(2,t)+1)%MOD);
	return 0;
}
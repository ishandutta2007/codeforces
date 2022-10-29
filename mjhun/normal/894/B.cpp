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

#define MOD 1000000007

ll pm(ll a, ll e){
	ll r=1;
	while(e){
		if(e&1)r*=a,r%=MOD;
		e>>=1;
		a*=a;a%=MOD;
	}
	return r;
}

int main(){
	ll n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	if(k<0&&n%2!=m%2){puts("0");return 0;}
	printf("%lld\n",((pm(pm(2,m),n)*pm((MOD+1)/2,m+n))%MOD*2)%MOD);
	return 0;
}
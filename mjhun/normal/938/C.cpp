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
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

ll xx;

bool doit(ll a, ll b){
	if((a+b)%2)return false;
	ll n=(a+b)/2;
	ll nm=n-a;
	ll s=1,e=n+1;
	while(e-s>1){
		//printf(" %lld %lld  %lld %lld\n",n,nm,s,e);
		ll z=(s+e)/2;
		if(n/z>=nm)s=z;
		else e=z;
	}
	//printf("%lld %lld\n",s,n/s);
	if(n/s!=nm)return false;
	//if(1LL*n*n-1LL*(n/s)*(n/s)!=xx){
	//	printf(" %lld %lld %lld %lld %lld\n",a,b,n,nm,s);
	//	printf("  %lld\n",xx);
	//}
	assert(1LL*n*n-1LL*(n/s)*(n/s)==xx);
	printf("%lld %lld\n",n,s);
	return true;

/*
	ll m=n/nm;
	while(n/m>nm)m++;
	if(n/m==nm){
		printf("%lld %lld\n",n,m);return true;
	}
	return false;*/
}

int main(){
	ll tn;
	scanf("%lld",&tn);
	while(tn--){
		ll x;
		scanf("%lld",&x);xx=x;
		if(x==0){puts("1 1");continue;}
		bool r=false;
		for(ll i=1;i*i<=x;++i)if(x%i==0&&doit(i,x/i)){r=true;break;}
		if(!r)puts("-1");
	}
	return 0;
}
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
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

ll k,d,t;

int main(){
	scanf("%lld%lld%lld",&k,&d,&t);t*=2;
	ll t0=k;ll t1=(k+d-1)/d*d-k;ll c=(k+d-1)/d*d;
	ll v=2*t0+t1;
	ll r=t/v*c;
	t%=v;bool asd=false;
	if(t<=2*t0){
		r+=t/2;
		if(t%2)asd=true;
	}
	else {
		r+=t0;
		t-=2*t0;
		r+=t;
	}
	printf("%lld",r);
	if(asd)puts(".5");
	else puts(".0");
	return 0;
}
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

ll n;int k;
int q=0;
ll asd=1000;

bool ask(ll s, ll e){
	//q++;
	//assert(q<=4500);
	//assert(s<e);assert(s>=1);assert(e-1<=n);
	//asd+=10;
	//return asd-10>=s&&asd-10<e;
	printf("%lld %lld\n",s,e-1);fflush(stdout);
	char r[8];
	scanf("%s",r);
	return r[0]=='Y';
}

int main(){
	srand(time(0));
	scanf("%lld%d",&n,&k);k=10;
	ll s=1,e=n+1;
	while(1){
		while(e-s>45){
			ll m=(s+e)/2;
			if(ask(s,m))e=min(m+k,n+1),s=max(s-k,1LL);
			else s=max(m-k,1LL),e=min(e+k,n+1);
		}
		ll x=s+rand()%(e-s);
		if(ask(x,x+1))return 0;
		s=max(s-2*k,1LL);e=min(e+2*k,n+1);
	}
	return 0;
}
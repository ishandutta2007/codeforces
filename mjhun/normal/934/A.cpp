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
#define mset(a,v) memset(a,v,sizeof(a))
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int n,m;
ll a[64],b[64];

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n)scanf("%lld",a+i);
	fore(i,0,m)scanf("%lld",b+i);
	ll r=1LL<<60;
	fore(_,0,n){
		ll rr=-(1LL<<60);
		fore(i,0,n)if(i!=_)fore(j,0,m)rr=max(rr,a[i]*b[j]);
		r=min(r,rr);
	}
	printf("%lld\n",r);
	return 0;
}
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

int n,q;
ll a[200005],s[200005];
ll t;

int main(){
	scanf("%d%d",&n,&q);
	fore(i,0,n)scanf("%lld",a+i),s[i+1]=s[i]+a[i];
	while(q--){
		ll x;
		scanf("%lld",&x);
		t+=x;
		if(t>=s[n])t=0;
		printf("%d\n",(int)(n-(upper_bound(s,s+n,t)-s)+1));
	}
	return 0;
}
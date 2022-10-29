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

int n;ll k;
ll a[100005],sp[100005];

int main(){
	scanf("%d%lld",&n,&k);
	fore(i,0,n)scanf("%lld",a+i);
	sort(a,a+n);
	fore(i,0,n)sp[i+1]=sp[i]+a[i];
	pair<int,ll> r={0,0LL};
	fore(i,0,n){
		int s=0,e=i+1;
		while(e-s>1){
			int m=(s+e)/2;
			if(a[i]*m-(sp[i]-sp[i-m])<=k)s=m;
			else e=m;
		}
		r=max(r,mp(s+1,-a[i]));
	}
	printf("%d %lld\n",r.fst,-r.snd);
	return 0;
}
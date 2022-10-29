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

int n;ll l,w;
pair<ll,int> t[100005];
vector<ll> z;

int main(){
	scanf("%d%lld%lld",&n,&l,&w);
	fore(i,0,n){
		ll a;int v;
		scanf("%lld%d",&a,&v);
		t[i]=mp(a,v);
	}
	sort(t,t+n);
	ll r=0;
	fore(i,0,n){
		if(t[i].snd>0)z.pb(t[i].fst);
		else {
			int b=lower_bound(z.begin(),z.end(),((w-1)*(t[i].fst+l)+w)/(w+1))-z.begin();
			int a=lower_bound(z.begin(),z.end(),-t[i].fst-l)-z.begin();
			//printf(" %lld ",t[i].fst);fore(i,a,b)printf(" %lld",z[i]);puts("");
			//printf(" %lld %d\n",t[i].fst,k);
			r+=b-a;
		}
	}
	fore(i,0,n)t[i].fst*=-1,t[i].fst-=l,t[i].snd*=-1;
	reverse(t,t+n);z.clear();//puts("");
	fore(i,0,n){
		if(t[i].snd>0)z.pb(t[i].fst);
		else {
			int b=lower_bound(z.begin(),z.end(),((w-1)*(t[i].fst+l)+w)/(w+1))-z.begin();
			int a=upper_bound(z.begin(),z.end(),-t[i].fst-l)-z.begin();
			//printf(" qwe %lld\n",-t[i].fst-l);
			//printf(" %lld ",t[i].fst);fore(i,a,b)printf(" %lld",z[i]);puts("");
			//printf(" %lld %d\n",t[i].fst,k);
			r+=b-a;
		}
	}
	printf("%lld\n",r);
	return 0;
}
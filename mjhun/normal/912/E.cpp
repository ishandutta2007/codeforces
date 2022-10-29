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


ll mx=1000000000000000000LL;

ll mul(ll x, ll y){
	ll r=x*y;
	if(r%x!=0||r/x!=y)return mx+1;
	return r;
}

vector<ll> w;
vector<int> p;
void go(int k, ll c){
	if(k==SZ(p)){w.pb(c);return;}
	while(c<=mx){
		go(k+1,c);
		c=mul(c,p[k]);
	}
}

vector<ll> v;
vector<int> q;
int n;

ll f(ll x){
	ll r=0;
	for(ll y:w)r+=upper_bound(v.begin(),v.end(),x/y)-v.begin();
	return r;
}

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		int x;
		scanf("%d",&x);
		if(i<n/2)p.pb(x);
		else q.pb(x);
	}
	go(0,1);v=w;w.clear();p=q;go(0,1);
	sort(v.begin(),v.end());
	ll k;
	scanf("%lld",&k);
	ll s=1,e=mx+1;
	while(e-s>1){
		ll m=(s+e)/2;
		if(f(m-1)>=k)e=m;
		else s=m;
	}
	printf("%I64d\n",s);
	return 0;
}
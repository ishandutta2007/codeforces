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
#define INF (1LL<<61)
using namespace std;
typedef long long ll;

ll add(ll a, ll b){return min(a+b,INF);}

int n,r;ll k;
ll sp[1<<19];
ll w[1<<19];

bool can(ll x){
	mset(w,0);
	ll b=0,t=0;
	fore(i,0,n){
		b+=w[i];
		ll s=sp[min(i+r+1,n)]-sp[max(i-r,0)]+b;
		if(s<x){
			t=add(t,x-s);
			b=add(b,x-s);
			if(i+2*r+1<n)w[i+2*r+1]-=x-s;
		}
		if(t>k)return false;
	}
	return true;
}

int main(){
	scanf("%d%d%lld",&n,&r,&k);
	fore(i,0,n)scanf("%lld",sp+i+1);
	fore(i,0,n)sp[i+1]+=sp[i];
	ll s=0,e=INF;
	while(e-s>1){
		ll m=(s+e)/2;
		if(can(m))s=m;
		else e=m;
	}
	printf("%lld\n",s);
	return 0;
}
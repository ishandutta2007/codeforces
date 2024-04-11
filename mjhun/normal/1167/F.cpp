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
#define MOD 1000000007


struct Pingo {
	int q=0,s=0;ll s0=0,s1=0;
};

Pingo st[1<<20];

void init(int k, int s, int e){
	st[k].q=e-s;
	if(s+1==e)return;
	int m=(s+e)/2;
	init(2*k,s,m);init(2*k+1,m,e);
}

void merge(Pingo& r, Pingo& a, Pingo& b){
	r.s0=a.s0+b.s0+1LL*a.s*b.q;
	r.s1=b.s1+a.s1+1LL*b.s*a.q;
	r.q=a.q+b.q;
	r.s=a.s+b.s;
}

void st_upd(int k, int s, int e, int p){
	if(s+1==e){st[k]=(Pingo){1,1,1LL,1LL};return;}
	int m=(s+e)/2;
	if(p<m)st_upd(2*k,s,m,p);
	else st_upd(2*k+1,m,e,p);
	merge(st[k],st[2*k],st[2*k+1]);
}

void st_query(int k, int s, int e, int a, int b, Pingo& r){
	if(s>=b||e<=a)return;
	if(s>=a&&e<=b){
		merge(r,r,st[k]);
		return;
	}
	int m=(s+e)/2;
	st_query(2*k,s,m,a,b,r);
	st_query(2*k+1,m,e,a,b,r);
}

int n;
pair<int,int> a[1<<19];

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		int t;
		scanf("%d",&t);
		a[i]=mp(t,i);
	}
	sort(a,a+n);
	init(1,0,n);
	ll r=0;
	fore(i,0,n){
		Pingo t0,t1;
		st_query(1,0,n,0,a[i].snd,t0);
		st_query(1,0,n,a[i].snd+1,n,t1);
		ll x=t0.s1%MOD,y=t1.s0%MOD;
		r+=(x*(n-a[i].snd)+y*(a[i].snd+1)+1LL*(n-a[i].snd)*(a[i].snd+1))%MOD*a[i].fst;
		r%=MOD;
		st_upd(1,0,n,a[i].snd);
	}
	printf("%lld\n",r);
	return 0;
}
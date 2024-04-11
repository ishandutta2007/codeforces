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

struct STree {
	vector<ll> st,lazy;int n;
	STree(int n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	void push(int k, int s, int e){
		if(!lazy[k])return;
		st[k]+=(e-s)*lazy[k];
		if(s+1<e){
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}
		lazy[k]=0;
	}
	void upd(int k, int s, int e, int a, int b, ll v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]+=v;
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=st[2*k]+st[2*k+1];
	}
	ll query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return 0;
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return query(2*k,s,m,a,b)+query(2*k+1,m,e,a,b);
	}
	void upd(int a, int b, ll v){upd(1,0,n,a,b,v);}
	ll query(int a, int b){return query(1,0,n,a,b);}
};

int n,m,q;

int main(){
	scanf("%d%d%d",&n,&m,&q);STree s0(n),s1(m);
	while(q--){
		int t,x0,x1,y0,y1;
		scanf("%d%d%d%d%d",&t,&x0,&y0,&x1,&y1);x0--;y0--;
		if(t==0){
			int v;
			scanf("%d",&v);
			s0.upd(x0,x1,1LL*(y1-y0)*v);
			s1.upd(y0,y1,1LL*(x1-x0)*v);
		}
		else printf("%lld\n",s0.query(x0,x1)+s1.query(y0,y1)-s0.query(0,n));
	}
	return 0;
}
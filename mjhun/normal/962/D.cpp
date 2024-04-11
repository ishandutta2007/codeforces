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

#define INF (1LL<<60)

#define oper min
#define NEUT mp(INF,-1)
struct STree {
	vector<pair<ll,int> > st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	STree(){}
	void init(int k, int s, int e, ll *a){
		if(s+1==e){st[k]=mp(a[s],s);return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int k, int s, int e, int p, ll v){
		if(s+1==e){st[k].fst=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	pair<ll,int> query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(ll *a){init(1,0,n,a);}
	void upd(int p, ll v){upd(1,0,n,p,v);}
	pair<ll,int> query(int a, int b){return query(1,0,n,a,b);}
};

ll a[200005];int n;STree w;

bool doit(){
	auto p=w.query(0,n);
	if(p.fst>=INF)return false;
	int k=p.snd;
	auto q=w.query(k+1,n);
	if(p.fst==q.fst){
		a[k]=-1;a[q.snd]*=2;
		w.upd(q.snd,a[q.snd]);
	}
	w.upd(k,INF);
	return true;
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%lld",a+i);
	w=STree(n);
	w.init(a);
	while(doit());
	int k=0;
	fore(i,0,n)k+=a[i]>=0;
	printf("%d\n",k);
	fore(i,0,n)if(a[i]>=0)printf("%lld%c",a[i],(--k)?' ':'\n');
	return 0;
}
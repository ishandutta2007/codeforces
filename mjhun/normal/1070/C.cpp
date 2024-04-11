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

int N=1000005;

pair<ll,ll> add(pair<ll,ll> a, pair<ll,ll> b){
	return mp(a.fst+b.fst,a.snd+b.snd);
}

pair<ll,ll> st[1<<21];
void st_upd(int k, int s, int e, int p, ll v){
	if(s+1==e){st[k].fst+=v;st[k].snd+=v*s;return;}
	int m=(s+e)/2;
	if(p<m)st_upd(2*k,s,m,p,v);
	else st_upd(2*k+1,m,e,p,v);
	st[k]=add(st[2*k],st[2*k+1]);
}
ll st_query(int k, int s, int e, ll q){
	if(q>=st[k].fst)return st[k].snd;
	if(s+1==e)return 1LL*s*q;
	int m=(s+e)/2;
	if(q<=st[2*k].fst)return st_query(2*k,s,m,q);
	return st[2*k].snd+st_query(2*k+1,m,e,q-st[2*k].fst);
}

int n;ll k;int m;ll r;
vector<pair<int,int> > e[1<<20]; // precio,cantidad

int main(){
	scanf("%d%lld%d",&n,&k,&m);
	fore(_,0,m){
		int a,b,c,p;
		scanf("%d%d%d%d",&a,&b,&c,&p);a--;
		e[a].pb(mp(p,c));
		e[b].pb(mp(p,-c));
	}
	fore(i,0,n){
		for(auto p:e[i])st_upd(1,0,N,p.fst,p.snd);
		r+=st_query(1,0,N,k);
	}
	printf("%lld\n",r);
	return 0;
}
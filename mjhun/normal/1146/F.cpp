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

#define MOD 998244353

ll add(ll a, ll b){
	a+=b;
	if(a>=MOD)a-=MOD;
	return a;
}
ll sub(ll a, ll b){
	a-=b;
	if(a<0)a+=MOD;
	return a;
}
ll mul(ll a, ll b){
	return a*b%MOD;
}
ll inv(ll a){
	ll e=MOD-2,r=1;
	while(e){
		if(e&1)r=mul(r,a);
		e>>=1;
		a=mul(a,a);
	}
	return r;
}

vector<int> g[200005];
int n;
ll q0[200005],q1[200005],s0[200005];

void dfs(int x){
	if(!SZ(g[x])){q0[x]=0;q1[x]=1;s0[x]=0;return;}
	if(SZ(g[x])==1){
		int y=g[x][0];
		dfs(y);
		q0[x]=q0[y];q1[x]=q1[y];s0[x]=s0[y];
		return;
	}
	for(int y:g[x])dfs(y);
	q0[x]=1;
	for(int y:g[x])q0[x]=mul(q0[x],add(q0[y],q1[y]));

	q1[x]=1;
	for(int a:g[x]){
		ll pingo=add(s0[a],q1[a]);
		pingo=add(pingo,q0[a]);
		pingo=add(pingo,q1[a]);
		q1[x]=mul(q1[x],pingo);
	}
	ll m=1;
	for(int a:g[x])m=mul(m,add(q0[a],q1[a]));
	q1[x]=sub(q1[x],m); // ninguno

	for(int a:g[x]){
		ll concha=mul(m,inv(add(q0[a],q1[a])));
		ll pingo=add(s0[a],q1[a]);
		//pingo=add(pingo,q0[a]);
		//pingo=add(pingo,q1[a]);
		concha=mul(concha,pingo);
		q1[x]=sub(q1[x],concha); // uno
	}/*
	for(int b:g[x]){m=add(m,mul(add(s0[b],q1[b]),inv(add(q0[b],q1[b]))));}
	q1[x]=0;
	for(int a:g[x]){
		ll pingo=mul(add(s0[a],q1[a]),inv(add(q0[a],q1[a])));
		ll m2=sub(m,pingo);
		q1[x]=add(q1[x],mul(pingo,m2));
	}
	q1[x]=mul(q1[x],q0[x]);
	*/
	s0[x]=0;
	for(int a:g[x]){
		ll pingo=mul(q0[x],inv(add(q0[a],q1[a])));
		s0[x]=add(s0[x],mul(pingo,add(s0[a],q1[a])));
	}
}

int main(){
	scanf("%d",&n);
	fore(i,1,n){
		int p;
		scanf("%d",&p);p--;
		g[p].pb(i);
	}
	dfs(0);
	printf("%lld\n",add(q0[0],q1[0]));
	return 0;
}
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
#define MOD 1000000007
using namespace std;
typedef long long ll;

void mmul(ll r[][3], ll x[][3], ll y[][3]){
	ll t[3][3];
	fore(i,0,3){
		fore(j,0,3){
			t[i][j]=0;
			fore(k,0,3){
				t[i][j]+=(x[i][k]*y[k][j])%MOD;
				if(t[i][j]>=MOD)t[i][j]-=MOD;
			}
		}
	}
	fore(i,0,3)fore(j,0,3)r[i][j]=t[i][j];
}

void mexp(ll r[][3], ll x[][3], ll e){
	ll t[3][3];
	ll t2[3][3];
	memset(t,0,sizeof(t));
	fore(i,0,3)t[i][i]=1;
	memcpy(t2,x,sizeof(t2));
	while(e){
		if(e&1)mmul(t,t,t2);
		e>>=1;
		mmul(t2,t2,t2);
	}
	memcpy(r,t,sizeof(t));
}

int n;ll m;
map<ll,vector<pair<int,int> > > w;
ll r[3],nr[3];int q[3],nq[3];
ll x[3][3];

void doit(ll e){ // actualiza r en base a r y q
	fore(i,0,3)fore(j,0,3){
		if(abs(i-j)<=1&&!q[i]&&!q[j])x[i][j]=1;
		else x[i][j]=0;
	}
	mexp(x,x,e);
	fore(i,0,3){
		nr[i]=0;
		fore(j,0,3){
			nr[i]+=x[i][j]*r[j]%MOD;
			nr[i]%=MOD;
		}
	}
	fore(i,0,3)r[i]=nr[i];
}

int main(){
	scanf("%d%lld",&n,&m);
	fore(i,0,n){
		int a;ll s,e;
		scanf("%d%lld%lld",&a,&s,&e);a--;
		w[s].pb(mp(a,1));
		w[e+1].pb(mp(a,-1));
	}
	r[1]=1;
	ll l=1;
	for(auto p:w){
		//printf(" %lld\n",p.fst);
		doit(p.fst-l-1);
		//printf("  %lld\n",p.fst);
		fore(i,0,3)nq[i]=q[i],nr[i]=0;
		for(auto pp:p.snd)nq[pp.fst]+=pp.snd;
		fore(i,0,3)fore(j,0,3)if(abs(i-j)<=1&&!q[i]&&!nq[j]){
			nr[j]+=r[i];nr[j]%=MOD;
		}
		fore(i,0,3)q[i]=nq[i],r[i]=nr[i];
		l=p.fst;
		//fore(i,0,3)printf(" %lld",r[i]);puts("");
	}
	doit(m-l);
	printf("%lld\n",r[1]);
	return 0;
}
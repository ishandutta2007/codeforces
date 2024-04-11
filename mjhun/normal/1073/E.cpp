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

const ll MOD=998244353;

bool bad[1<<10];
vector<int> d;
ll dp[22][1<<10][2][2];
ll dp2[22][1<<10][2][2];
ll p10[22];
ll rr;
vector<pair<pair<int,int>,pair<int,int> > > g[22][1<<10][2][2];

ll f(int i, int m, int b, int z){
	ll& r=dp[i][m][b][z];
	if(r>=0)return r;
	r=0;
	//if(!bad[m]){printf("  %d\n",m);}
	if(bad[m]){
		return r;
	}
	if(i==SZ(d))return r=1;
	fore(k,0,10){
		if(b&&k>d[i])break;
		int mm=m;
		if(!z||k)mm|=1<<k;
		ll t=f(i+1,mm,b&&k==d[i],z&&!k);
		g[i+1][mm][b&&k==d[i]][z&&!k].pb(mp(mp(i,m),mp(b,z)));
		//rr+=(t*k)%MOD*p10[i];
		//rr%=MOD;
		r+=t;
		if(r>=MOD)r-=MOD;
	}
	return r;
}

ll f2(int i, int m, int b, int z){
	ll& r=dp2[i][m][b][z];
	if(r>=0)return r;
	if(i==0)return r=1;
	r=0;
	for(auto p:g[i][m][b][z]){
		r+=f2(p.fst.fst,p.fst.snd,p.snd.fst,p.snd.snd);
		if(r>=MOD)r-=MOD;
	}
	return r;
}

ll doit(ll x){
	if(x==0)return 0;
	d.clear();
	while(x)d.pb(x%10),x/=10;
	reverse(d.begin(),d.end());
	p10[0]=1;
	fore(i,1,SZ(d))p10[i]=(p10[i-1]*10)%MOD;
	reverse(p10,p10+SZ(d));
	mset(dp,-1);mset(dp2,-1);
	rr=0;
	f(0,0,1,1);
	fore(i,0,SZ(d))fore(m,0,1<<10)fore(b,0,2)fore(z,0,2){
		if(dp[i][m][b][z]<0)continue;
		fore(k,0,10){
			if(b&&k>d[i])break;
			int mm=m;
			if(!z||k)mm|=1<<k;
			ll t=f(i+1,mm,b&&k==d[i],z&&!k);
			rr+=t*k%MOD*p10[i]%MOD*f2(i,m,b,z);
			rr%=MOD;
		}
	}
	fore(i,0,22)fore(m,0,1<<10)fore(b,0,2)fore(z,0,2)g[i][m][b][z].clear();
	//printf(" %lld\n",rr);
	return rr;
}

ll a,b;int k;

int main(){
	scanf("%lld%lld%d",&a,&b,&k);
	fore(i,0,1<<10)bad[i]=__builtin_popcount(i)>k;
	printf("%lld\n",(doit(b)+MOD-doit(a-1))%MOD);
	return 0;
}
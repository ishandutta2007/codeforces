#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const ll MOD=998244353;

const int MAXN=200005;

bool isprime[MAXN];
vector<ll> prime;
int SPF[MAXN];
 
//Inicializar en true isprime
void sieve(int n){
    isprime[0] = isprime[1] = false;
    fore(i,2,n+1){
        if(isprime[i]) prime.push_back(i), SPF[i] = i;
        for(int j=0; j<SZ(prime)&&i*prime[j]<=n&&prime[j]<=SPF[i]; j++){
            isprime[i*prime[j]] = false;
            SPF[i*prime[j]] = prime[j];
        }
    }
}

struct edge{ 
	ll y,a,b;
};

vector<edge> g[MAXN];

vector<pair<ll,ll>> fact(ll n){
	vector<pair<ll,ll>> res;
	while(n>1){
		auto p=SPF[n];
		if(!SZ(res)||res.back().fst!=p)res.pb({p,1});
		else res[SZ(res)-1].snd++;
		n/=p;
	}
	return res;
}

ll vis[MAXN];

edge pa[MAXN];

ll cp[MAXN],mini[MAXN];

vector<ll> visp;

vector<ll> ord;

void add(vector<pair<ll,ll>> &f){
	for(auto i:f){
		visp.pb(i.fst);
		cp[i.fst]+=i.snd;
		mini[i.fst]=min(mini[i.fst],cp[i.fst]);
	}
}

void rem(vector<pair<ll,ll>> &f){
	for(auto i:f){
		visp.pb(i.fst);
		cp[i.fst]-=i.snd;
		mini[i.fst]=min(mini[i.fst],cp[i.fst]);
	}
}

void dfs(ll x){
	vis[x]=1;
	ord.pb(x);
	for(auto i:g[x]){
		if(vis[i.y])continue;
		pa[i.y]={x,i.b,i.a};
		auto fa=fact(i.a);
		auto fb=fact(i.b);
		add(fb);
		rem(fa);
		dfs(i.y);
		rem(fb);
		add(fa);
	}
}

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

int main(){FIN;
	mset(isprime,true);
	sieve(MAXN-1);
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)g[i].clear();
		fore(i,0,n-1){
			ll x,y,a,b; cin>>x>>y>>a>>b; x--; y--;
			ll gc=__gcd(a,b);
			a/=gc;
			b/=gc;
			g[x].pb({y,a,b});
			g[y].pb({x,b,a});
		}
		fore(i,0,n)vis[i]=0;
		ord.clear();
		visp.clear();
		dfs(0);
		sort(ALL(visp));
		visp.erase(unique(ALL(visp)), visp.end());
		ll val=1;
		for(auto i:visp){
			val=val*fpow(i,-mini[i])%MOD;
			//cout<<i<<" "<<-mini[i]<<"\n";
		}
		//cout<<val<<"\n";
		vector<ll> v(n);
		v[0]=val;
		for(auto i:ord){
			if(i==0)continue;
			v[i]=v[pa[i].y];
			v[i]=v[i]*pa[i].a%MOD;
			v[i]=v[i]*fpow(pa[i].b,MOD-2)%MOD;
		}
		ll res=0;
		for(auto i:v)res=(res+i)%MOD;
		cout<<res<<"\n";
		for(auto i:visp)mini[i]=0;
	}
	
	return 0;
}
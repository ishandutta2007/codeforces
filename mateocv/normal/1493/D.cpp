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

//Criba n*log(log(n)) Inicializar en true isprime

const int MAXN=200005;

bool isprime[MAXN];
vector<ll> prime;
ll SPF[MAXN];

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

const ll MOD=1000000007;

ll a[MAXN];
ll oc[MAXN];

set<pair<ll,ll>> p[MAXN];

void ins(ll id, ll pr){
	auto it=p[id].lower_bound({pr,-1});
	if(it==p[id].end()||it->fst!=pr){
		p[id].insert({pr,1});
	}else{
		pair<ll,ll> pa=*it;
		p[id].erase(*it);
		pa.snd++;
		p[id].insert(pa);
	}
}

void eli(ll id, ll pr){
	auto it=p[id].lower_bound({pr,-1});
	if(it==p[id].end()||it->fst!=pr){
		assert(0);
	}else{
		pair<ll,ll> pa=*it;
		p[id].erase(*it);
		pa.snd--;
		if(pa.snd!=0)p[id].insert(pa);
	}
}

bool is(ll id, ll pr){
	auto it=p[id].lower_bound({pr,-1});
	if(it==p[id].end()||it->fst!=pr){
		return 0;
	}
	return 1;
}

vector<ll> getp(ll n){
	vector<ll> res;
	while(n>1){
		res.pb(SPF[n]);
		n/=SPF[n];
	}
	return res;
}

ll res,n;

void upd(ll pr){
	fore(i,0,n)eli(i,pr);
	res=res*pr%MOD;
	oc[pr]=0;
	fore(i,0,n)if(is(i,pr))oc[pr]++;
}

int main(){FIN;
	mset(isprime,true);
	sieve(MAXN-1);
	ll q; cin>>n>>q;
	fore(i,0,n){
		cin>>a[i];
	}
	fore(i,0,n){
		auto g=getp(a[i]);
		for(auto j:g)ins(i,j);
	}
	res=1;
	fore(i,0,n){
		for(auto j:p[i]){
			oc[j.fst]++;
		}
	}
	fore(i,0,MAXN){
		while(oc[i]==n)upd(i);
	}
	while(q--){
		ll pos,x; cin>>pos>>x;
		pos--;
		auto g=getp(x);
		for(auto i:g){
			if(!is(pos,i)){
				ins(pos,i);
				oc[i]++;
				while(oc[i]==n)upd(i);
			}else{
				ins(pos,i);
			}
		}
		cout<<res<<"\n";
	}
	
	
	return 0;
}
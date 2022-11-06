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

const int MAXN=20000007;

vector<ll> prime;
bool isprime[MAXN];
ll SPF[MAXN];

//Criba n*log(log(n)) Inicializar en true isprime
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

vector<pair<ll,ll>> fact(ll n){
	vector<pair<ll,ll>> res;
	while(n>1){
		ll s=SPF[n];
		if(SZ(res)==0||res.back().fst!=s){
			res.pb({s,1});
		}else{
			res[SZ(res)-1].snd++;
		}
		n/=s;
	}
	return res;
}

vector<ll> div(ll n){
	auto f=fact(n);
	vector<ll> res={1};
	fore(i,0,SZ(f)){
		fore(j,0,SZ(res)){
			ll va=f[i].fst;
			fore(ii,1,f[i].snd+1){
				res.pb(res[j]*va);
				va*=f[i].fst;
			}
		}
	}
	return res;
}

ll pot[30];

ll divi(ll a, ll b){
	ll res=a/b;
	if(a-res*b!=0)return -1;
	return res;
}

ll cantp[MAXN];

int main(){FIN;
	mset(isprime,true);
	sieve(MAXN-1);
	pot[0]=1;
	fore(i,1,30)pot[i]=2*pot[i-1];
	fore(i,2,MAXN){
		ll s=SPF[i];
		ll c=i/s;
		if(SPF[c]==s)cantp[i]=cantp[c];
		else cantp[i]=cantp[c]+1;
	}
	ll t; cin>>t;
	while(t--){
		ll c,d,x; cin>>c>>d>>x;
		auto di=div(x);
		ll res=0;
		for(auto i:di){
			ll l=divi(x+d*i,c);
			if(l==-1)continue;
			ll d=divi(l,i);
			if(d==-1)continue;
			res+=pot[cantp[d]];
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
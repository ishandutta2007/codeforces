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

const int MAXN=1000006;
bool isprime[MAXN];
ll SPF[MAXN];
vector<ll> prime;

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

ll pc(ll n){
	vector<pair<ll,ll>> v;
	while(n>1){
		ll p=SPF[n];
		ll va=0;
		while(n%p==0){
			va++; n/=p;
		}
		v.pb({p,va});
	}
	ll res=1;
	for(auto i:v){
		if(i.snd&1)res*=i.fst;
	}
	return res;
}

set<ll> vis;
ll c[MAXN];

int main(){FIN;
	mset(isprime,true);
	sieve(MAXN-1);
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n){
			ll p=pc(a[i]);
			c[p]++;
			vis.insert(p);
		}
		ll res[2]={0,0};
		ll va=0;
		for(auto i:vis){
			//cout<<i<<" "<<c[i]<<"\n";
			res[0]=max(res[0],c[i]);
			if(c[i]%2==0&&i!=1)va+=c[i];
		}
		for(auto i:vis){
			if(i==1)res[1]=max(res[1],c[i]+va);
			else res[1]=max(res[1],c[i]);
		}
		res[1]=max(res[1],c[1]+va);
		ll q; cin>>q;
		while(q--){
			ll w; cin>>w;
			if(w==0)cout<<res[0]<<"\n";
			else cout<<res[1]<<"\n";
		}
		for(auto i:vis)c[i]=0;
		vis.clear();
	}
	
	return 0;
}
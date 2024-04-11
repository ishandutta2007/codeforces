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
ll isprime[15000007];
ll SPF[15000007];
vector<ll>prime;
void sieve(int n){
	mset(isprime,true);
    isprime[0] = isprime[1] = false;
    fore(i,2,n+1){
        if(isprime[i]) prime.push_back(i), SPF[i] = i;
        for(int j=0; j<SZ(prime)&&i*prime[j]<=n&&prime[j]<=SPF[i]; j++){
            isprime[i*prime[j]] = false;
            SPF[i*prime[j]] = prime[j];
        }
    }
}

map<ll,ll> fact(ll n){
	map<ll,ll> res;
	while(!isprime[n]){
		res[SPF[n]]++;
		n/=SPF[n];
	}
	res[n]++;
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll g=0;
	fore(i,0,n)g=__gcd(g,a[i]);
	fore(i,0,n)a[i]/=g;
	sort(a,a+n);
	vector<ll> v;
	fore(i,0,n)v.pb(a[i]);
	reverse(ALL(v));
	ll res=0;
	while(SZ(v)&&v.back()==1){
		res++;
		v.pop_back();
	}
	if(SZ(v)==0){
		cout<<-1; return 0;
	}
	sieve(15000005);
	map<ll,ll> mp;
	fore(i,0,SZ(v)){
		map<ll,ll> m=fact(v[i]);
		for(auto j:m){
			mp[j.fst]++;
		}
	}
	ll maxi=-1;
	for(auto i:mp){
		maxi=max(maxi,i.snd);
	}
	cout<<n-maxi;
	return 0;
}
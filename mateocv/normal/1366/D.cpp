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

const int MAXN=10000007;
//Criba n*log(log(n)) Inicializar en true isprime
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

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	mset(isprime,true);
	sieve(MAXN);
	vector<pair<ll,ll>> res;
	fore(i,0,n){
		vector<ll> p;
		ll val=a[i];
		while(val>1){
			ll s=SPF[val];
			p.pb(s);
			while(val%s==0)val/=s;
		}
		ll maxi=1;
		val=a[i];
		while(val%p[0]==0)maxi*=p[0],val/=p[0];
		if(val!=1)res.pb({maxi,val});
		else res.pb({-1,-1});
	}
	fore(i,0,n)cout<<res[i].fst<<" "; cout<<"\n";
	fore(i,0,n)cout<<res[i].snd<<" "; cout<<"\n";
	
	return 0;
}
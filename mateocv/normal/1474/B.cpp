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

const int MAXN=30004;

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

int main(){FIN;
	mset(isprime,true);
	sieve(MAXN-1);
	//cout<<SZ(prime)<<"\n";
	ll t; cin>>t;
	while(t--){
		ll d; cin>>d;
		ll va=1;
		vector<ll> res;
		fore(i,0,SZ(prime)){
			if(prime[i]>=va+d){
				res.pb(prime[i]);
				va=res.back();
				if(SZ(res)==2)break;
			}
		}
		ll resf=1;
		for(auto i:res)resf*=i;
		fore(i,0,SZ(prime)){
			if(prime[i]>=d+1){
				resf=min(resf,prime[i]*prime[i]*prime[i]);
			}
		}
		cout<<resf<<"\n";
	}
	return 0;
}
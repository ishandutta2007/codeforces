#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const int MAXN=10000007;

bool isprime[MAXN];
vector<ll> prime;
int SPF[MAXN];

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

int resp[MAXN],sumd[MAXN],sumdd[MAXN],cants[MAXN];

vector<ll> sump[MAXN];

ll sumpc(pair<ll,ll> p){
	if(SZ(sump[p.fst])>p.snd)return sump[p.fst][p.snd];
	assert(SZ(sump[p.fst])==p.snd);
	sump[p.fst].pb(sump[p.fst].back()*p.fst+1);
	return sump[p.fst][p.snd];
}

int main(){FIN;
	mset(isprime,true);
	sieve(MAXN-1);
	mset(resp,-1);
	for(auto i:prime)sump[i].pb(1);
	fore(i,1,MAXN){
		if(i==1)cants[i]=0;
		else{
			ll sp=SPF[i];
			if((i/sp)%sp==0){
				cants[i]=cants[i/sp]+1;
			}else{
				cants[i]=1;
			}
		}
	}
	fore(i,1,MAXN){
		ll s=0,ss=0;
		if(i==1)s=1,ss=1;
		else{
			ll sp=SPF[i];
			if((i/sp)%sp==0){
				s=sumdd[i/sp]*sumpc({sp,cants[i]});
				ss=sumdd[i/sp];
			}else{
				s=sumd[i/sp]*(sp+1);
				ss=sumd[i/sp];
				sumpc({sp,1});
			}
		}
		sumd[i]=s;
		sumdd[i]=ss;
		assert(s<=2000000000);
		if(s<MAXN&&resp[s]==-1)resp[s]=i;
	}
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		cout<<resp[n]<<"\n";
	}
	
	return 0;
}
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

ll ask(ll x, ll y){
	cout<<"? "<<x+1<<" "<<y+1<<endl;
	ll res; cin>>res;
	return res;
}

const int MAXN=200005;

/*----------------------CRIBA_LOGLOG-------------------------*/
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

ll getr(){
	return (rand()<<15)^rand();
}

int main(){FIN;
	mset(isprime,true);
	sieve(MAXN-1);
	ll t; cin>>t;
	srand(ll(&t));
	while(t--){
		ll n; cin>>n;
		if(n<=100){
			vector<vector<ll>> a(n);
			fore(i,0,n){
				fore(j,i+1,n){
					auto as=ask(i,j);
					a[i].pb(as);
					a[j].pb(as);
				}
			}
			vector<ll> res;
			fore(i,0,n){
				res.pb(0);
				for(auto j:a[i])res.back()=__gcd(res.back(),j);
			}
			ll mini=MAXN;
			for(auto i:res)mini=min(mini,i);
			fore(i,0,SZ(res)){
				while(res[i]>=mini+n)res[i]/=2;
			}
			cout<<"! ";
			for(auto i:res)cout<<i<<" ";
			cout<<endl;
		}else{
			ll it0=250;
			ll pos=-1,p=-1;
			while(it0--){
				ll r=getr()%n;
				ll it1=20;
				ll val=0;
				while(it1--){
					ll rr=getr()%n;
					while(rr==r)rr=getr()%n;
					val=__gcd(val,ask(r,rr));
				}
				if(isprime[val]&&val>p){
					p=val;
					pos=r;
				}
			}
			assert(pos!=-1);
			vector<ll> res;
			fore(i,0,n){
				if(i!=pos)res.pb(ask(pos,i)/p);
				else res.pb(p);
			}
			cout<<"! ";
			for(auto i:res)cout<<i<<" ";
			cout<<endl;
		}
	}
	
	return 0;
}
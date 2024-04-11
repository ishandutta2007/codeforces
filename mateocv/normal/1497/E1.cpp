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

bool isprime[MAXN];
vector<ll> prime;
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

ll sqp(ll n){
	vector<ll> pr;
	while(n>1){
		ll s=SPF[n];
		n/=s;
		if(SZ(pr)&&pr.back()==s)pr.pop_back();
		else pr.pb(s);
	}
	ll res=1;
	for(auto i:pr)res=res*i;
	return res;
}

set<ll> st;

int main(){FIN;
	mset(isprime,true);
	sieve(MAXN-1);
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		st.clear();
		ll res=0;
		fore(i,0,n){
			ll a; cin>>a;
			a=sqp(a);
			if(!st.count(a))st.insert(a);
			else{
				res++;
				st.clear();
				st.insert(a);
			}
		}
		res++;
		cout<<res<<"\n";
	}
	
	return 0;
}
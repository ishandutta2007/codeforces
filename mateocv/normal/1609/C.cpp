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
vector<ll> prime;
int SPF[MAXN];
 
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

ll solve(vector<ll> v){
	vector<ll> cs(2*SZ(v)+10);
	cs[0]=1;
	ll va=0,res=0;
	for(auto i:v){
		va+=i;
		if(va)res+=cs[va-1];
		cs[va]++;
	}
	return res;
}

vector<ll> b[200005];

int main(){FIN;
	mset(isprime,true);
	sieve(MAXN-1);
	ll t; cin>>t;
	while(t--){
		ll n,e; cin>>n>>e;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n){
			if(a[i]==1)a[i]=0;
			else if(isprime[a[i]])a[i]=1;
			else a[i]=2;
		}
		fore(i,0,e)b[i].clear();
		fore(i,0,n)b[i%e].pb(a[i]);
		ll res=0;
		fore(i,0,e)res+=solve(b[i]);
		fore(i,0,n)res-=(a[i]==1);
		cout<<res<<"\n";
	}
	
	return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

bool isprime[1000008];
vector<ll> prime;
ll SPF[1000008];

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

ll phi(ll n){
	ll res=1,ex=0;
	if(n==4||n==6)return 3;
	//if(n%2==0)ex++;
	while(n>1){
		ll p=SPF[n];
		res*=p-1; n/=p;
		while(n%p==0){
			res*=p; n/=p;
		}
	}
	//res+=ex;
	return res;
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	fore(i,0,n+2)isprime[i]=true;
	sieve(n+1);
	vector<pair<ll,ll>> v;
	fore(i,3,n+1){
		v.pb({phi(i),i});
	}
	sort(ALL(v));
	//fore(i,0,SZ(v))cout<<v[i].fst<<" "<<v[i].snd<<"\n";
	ll res=1;
	fore(i,0,k)res+=v[i].fst;
	if(n>=6&&k>=3)res--;
	cout<<res;
	return 0;
}
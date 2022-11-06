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

vector<ll> fact(ll n){
	if(n==0)return {};
	vector<ll> res;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			res.pb(i);
			while(n%i==0){
				n/=i;
			}
		}
	}
	if(n>1)res.pb(n);
	return res;
}

ll n; 
ll a[200005];

ll get(){
	return (rand()<<16)+rand();
}

ll solve(ll k){
	assert(k!=1);
	ll res=0;
	fore(i,0,n){
		ll m=a[i]%k;
		if(a[i]==m){
			res+=k-a[i];
		}else{
			res+=min(m,k-m);
		}
	}
	//cout<<k<<" "<<res<<"\n";
	return res;
}

int main(){FIN;
	srand(time(NULL));
	cin>>n;
	fore(i,0,n)cin>>a[i];
	ll it=50;
	set<ll> s;
	while(it--){
		ll x=a[get()%n];
		fore(i,-2,3){
			vector<ll> f=fact(abs(x+i));
			for(auto j:f)s.insert(j);
		}
	}
	//cout<<"HOLAAAAAAAAAAA"<<endl;
	vector<ll> v;
	for(auto i:s)v.pb(i);
	ll res=solve(2);
	for(auto i:v){
		res=min(res,solve(i));
	}
	cout<<res;
	return 0;
}
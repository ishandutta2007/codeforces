#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll vp(ll x,ll p){
	ll sum=0;
	while(x>0){
		x/=p;
		sum+=x;
	}
	return sum;
}

vector<pair<ll,ll>> fact(ll x){
	vector<pair<ll,ll>> res;
	for(ll i=2;i*i<=x;i++){
		if(x%i==0){ll cuenta=0;
			while(x%i==0){
				cuenta++; x/=i;	
			}
			pair<ll,ll> pr;
			pr.fst=i; pr.snd=cuenta;
			res.pb(pr);
		}
	}
	if(x>1){
		pair<ll,ll> pr;
		pr.fst=x; pr.snd=1;
		res.pb(pr);
	}
	return res;
}

int main(){FIN;
	ll n,b; cin>>n>>b;
	ll mini=20+1e18;
	if(n==1){cout<<0;
	}else{
		fore(i,0,SZ(fact(b))){
		//cout<<vp(n,fact(b)[i].fst)/fact(b)[i].snd;
		mini=min(mini,vp(n,fact(b)[i].fst)/fact(b)[i].snd);
		
		}
	
	cout<<mini;
	}
	return 0;
}
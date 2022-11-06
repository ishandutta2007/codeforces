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

map<ll,ll> p;

ll esp(ll x){
	for(ll i=2;i*i<=x;i++){
		if(x%i==0)return 0;
	}
	return 1;
}

ll maxd(ll x){
	for(ll i=2;i*i<=x;i++){
		if(x%i==0)return x/i;
	}
	return 1;
}

void calc(){
	ll va=1;
	fore(i,2,2750132){
		if(esp(i)){
			p[i]=va;
			va++;
		}
	}
}

map<ll,ll> m;

void rest(ll x){
	m[x]--;
	if(m[x]==0)m.erase(x);
}

int main(){FIN;
	ll n; cin>>n;
	ll a[2*n];
	fore(i,0,2*n)cin>>a[i];
	//sort(a,a+2*n);
	calc();
	//cout<<p[2750131];
	fore(i,0,2*n){
		m[a[i]]++;
	}
	vector<ll> v;
	while(SZ(v)<n){
		auto it=m.end();
		it--;
		ll num=(it->fst);
		if(esp(num)){
			rest(num); rest(p[num]);
			v.pb(p[num]);
		}else{
			rest(num); rest(maxd(num));
			v.pb(num);
		}
	}
	fore(i,0,n)cout<<v[i]<<" ";
	
	return 0;
}
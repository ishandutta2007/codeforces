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

vector<ll> v[10];

vector<ll> dig(ll n){
	vector<ll> res;
	while(n){
		res.pb(n%10);
		n/=10;
	}
	return res;
}

vector<ll> mul(vector<ll> a, vector<ll> b){
	vector<ll> res(SZ(a)+SZ(b)-1);
	fore(i,0,SZ(a)){
		fore(j,0,SZ(b)){
			res[i+j]+=a[i]*b[j];
		}
	}
	return res;
}

ll r[10][10];

int main(){FIN;
	fore(i,1,100){
		auto d=dig(i);
		for(auto j:d)v[j].pb(i);
	}
	fore(i,1,10){
		fore(j,0,10){
			r[i][j]=100;
		}
		vector<ll> p(100);
		for(auto j:v[i])p[j]=1;
		p[0]=1;
		vector<ll> pf=p;
		fore(ii,0,i+1){
			pf=mul(pf,pf);
			while(SZ(pf)>100)pf.pop_back();
			fore(j,0,SZ(pf))if(pf[j])pf[j]=1;
		}
		fore(j,0,SZ(pf)){
			if(pf[j])r[i][j%i]=min(r[i][j%i],j);
		}
	}
	ll t; cin>>t;
	while(t--){
		ll q,d; cin>>q>>d;
		while(q--){
			ll n; cin>>n;
			if(r[d][n%d]>n)cout<<"NO\n";
			else cout<<"YES\n";
		}
	}
	
	
	return 0;
}
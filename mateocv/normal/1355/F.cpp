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

ll esp(ll n){
	if(n==1)return 0;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}

ll ask(ll n){
	cout<<"? "<<n<<endl;
	ll resp; cin>>resp;
	return resp;
}

ll cont(ll n, ll p){
	ll res=0;
	while(n%p==0){
		res++;
		n/=p;
	}
	return res;
}

ll maxp(ll n){
	ll maxi=1e9;
	ll res=1;
	while(res*n<=maxi)res*=n;
	return res;
}

ll solve(vector<ll> v){
	//cout<<SZ(v)<<"\n";
	//for(auto i:v)cout<<i<<" "; cout<<"\n";
	vector<pair<ll,ll>> f;
	for(auto i:v){
		if(SZ(f)==0||f.back().fst!=i){
			f.pb({i,1});
		}else{
			f[SZ(f)-1].snd++;
		}
	}
	ll res=1;
	for(auto i:f)res*=i.snd+1;
	return max(res+7,2*res);
}

int main(){FIN;
	vector<ll> p;
	fore(i,2,1000){
		if(esp(i))p.pb(i);
	}
	ll c[2]={1,1};
	fore(i,0,15)c[0]*=p[i];
	fore(i,15,24)c[1]*=p[i];
	ll t; cin>>t;
	while(t--){
		vector<ll> pr;
		ll a=ask(c[0]);
		fore(i,0,15){
			if(a%p[i]==0){
				pr.pb(p[i]);
			}
		}
		a=ask(c[1]);
		fore(i,15,24){
			if(a%p[i]==0){
				pr.pb(p[i]);
			}
		}
		ll pos=24,maxi=1e18;
		vector<ll> prr,prp;
		for(auto i:pr){
			prp.clear();
			ll b=maxp(i);
			while(b<=maxi/p[pos]){
				b*=p[pos];
				prp.pb(p[pos]);
				pos++;
			}
			a=ask(b);
			fore(ii,0,cont(a,i))prr.pb(i);
			for(auto ii:prp){
				if(a%ii==0)prr.pb(ii);
			}
		}
		fore(it,2+SZ(pr),22){
			prp.clear();
			ll b=1;
			while(b<=maxi/p[pos]){
				b*=p[pos];
				prp.pb(p[pos]);
				pos++;
			}
			a=ask(b);
			for(auto ii:prp){
				if(a%ii==0)prr.pb(ii);
			}
		}
		sort(ALL(prr));
		cout<<"! "<<solve(prr)<<endl;
	}
	return 0;
}
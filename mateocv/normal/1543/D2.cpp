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

ll ask(ll val){
	cout<<val<<endl;
	ll resp; cin>>resp;
	assert(resp!=-1);
	return resp;
}

ll k;

vector<ll> rep(ll n){
	vector<ll> res;
	while(n){
		res.pb(n%k);
		n/=k;
	}
	return res;
}

ll conv(vector<ll> v){
	ll res=0;
	reverse(ALL(v));
	for(auto i:v)res=res*k+i;
	return res;
}

ll op(ll a, ll b){
	auto ra=rep(a),rb=rep(b);
	vector<ll> res(max(SZ(ra),SZ(rb)));
	fore(i,0,SZ(ra))res[i]=(res[i]+ra[i])%k;
	fore(i,0,SZ(rb))res[i]=(res[i]+rb[i])%k;
	//cout<<"op "<<a<<" "<<b<<" "<<conv(res)<<"\n";
	return conv(res);
}

ll inv(ll n){
	auto res=rep(n);
	fore(i,0,SZ(res)){
		res[i]=(k-res[i])%k;
	}
	//cout<<"inv "<<n<<" "<<conv(res)<<"\n";
	return conv(res);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n>>k;
		fore(i,0,n){
			ll val=0;
			if(i){
				if(i&1)val=op(inv(i),i-1);
				else val=op(inv(i-1),i);
			}
			ll a=ask(val);
			if(a==1)break;
		}
	}
	
	
	return 0;
}
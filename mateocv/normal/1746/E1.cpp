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

vector<vector<ll>> part(vector<ll> v, ll k){
	vector<vector<ll>> res(k);
	fore(i,0,SZ(v))res[i%k].pb(v[i]);
	return res;
}

vector<ll> join(vector<vector<ll>> v){
	vector<ll> res;
	for(auto i:v){
		for(auto j:i)res.pb(j);
	}
	return res;
}

bool ask(vector<ll> v){
	cout<<"? "<<SZ(v)<<" ";
	for(auto i:v)cout<<i<<" ";
	cout<<endl;
	string res; cin>>res;
	return res=="YES";
}

void ans(ll x){
	cout<<"! "<<x<<endl;
	string res; cin>>res;
	if(res==":)")exit(0);
}

int main(){FIN;
	ll n; cin>>n;
	vector<ll> v;
	fore(i,1,n+1)v.pb(i);
	ll it=38;
	while(it--&&SZ(v)>=4){
		auto p=part(v,4);
		auto a=ask(join({p[0],p[1]}));
		if(a){
			auto b=ask(p[2]);
			if(b){
				v=join({p[0],p[1],p[2]});
			}else{
				v=join({p[0],p[1],p[3]});
			}
		}else{
			auto b=ask(p[0]);
			if(b){
				v=join({p[0],p[2],p[3]});
			}else{
				v=join({p[1],p[2],p[3]});
			}
		}
		
	}
	assert(SZ(v)<=3);
	if(SZ(v)<=2){
		ans(v[0]);
		ans(v[1]);
		return 0;
	}
	ll ul=-1;
	fore(i,0,SZ(v)-1){
		auto a=ask({v[i]});
		if(a){
			ul=i; break;
		}
		a=ask({v[i]});
		if(a){
			ul=i; break;
		}
	}
	if(ul==-1){
		ans(v.back());
		return 0;
	}
	auto a=ask({v[(ul+1)%SZ(v)]});
	if(a){
		ans(v[ul]);
		ans(v[(ul+1)%SZ(v)]);
	}else{
		ans(v[ul]);
		ans(v[(ul+2)%SZ(v)]);
	}
	return 0;
}
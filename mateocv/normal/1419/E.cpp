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

vector<ll> div(ll n){
	vector<ll> res;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			if(i!=1)res.pb(i);
			if(n/i!=i)res.pb(n/i);
		}
	}
	return res;
}

vector<ll> pr(ll n){
	vector<ll> res;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			res.pb(i);
			while(n%i==0)n/=i;
		}
	}
	if(n>1)res.pb(n);
	return res;
}

vector<vector<ll>> res;
set<ll> vis;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		auto d=div(n),p=pr(n);
		//for(auto i:d)cout<<i<<" "; cout<<endl;
		//for(auto i:p)cout<<i<<" "; cout<<endl;
		ll resv=-1;
		if(SZ(p)==1){
			res.resize(SZ(p));
			resv=0;
			for(auto i:d)res[0].pb(i);
		}else if(SZ(p)>=3){
			res.resize(SZ(p));
			fore(i,0,SZ(p)){
				res[i].pb(p[i]*p[(i-1+SZ(p))%SZ(p)]);
				vis.insert(p[i]*p[(i-1+SZ(p))%SZ(p)]);
			}
			for(auto i:d){
				if(!vis.count(i)){
					fore(j,0,SZ(p)){
						if(i%p[j]==0){
							res[j].pb(i);
							break;
						}
					}
				}
			}
			resv=0;
		}else{
			res.resize(SZ(p));
			ll pq=p[0]*p[1];
			vector<ll> mul;
			for(auto i:d){
				if(i%pq==0)mul.pb(i);
			}
			if(SZ(mul)>=2){
				fore(k,0,2)res[k].pb(mul[k]),vis.insert(mul[k]);
				resv=0;
			}else{
				assert(SZ(mul)>=1);
				res[0].pb(mul[0]);
				vis.insert(mul[0]);
				resv=1;
			}
			for(auto i:d){
				if(!vis.count(i)){
					fore(j,0,SZ(p)){
						if(i%p[j]==0){
							res[j].pb(i);
							break;
						}
					}
				}
			}
		}
		for(auto i:res){
			for(auto j:i){
				cout<<j<<" ";
			}
		}
		cout<<"\n"<<resv<<"\n";
		res.clear(); vis.clear();
	}
	
	return 0;
}
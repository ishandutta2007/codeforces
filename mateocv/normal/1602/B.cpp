#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

vector<ll> trans(vector<ll> v){
	vector<ll> c(SZ(v)+1);
	for(auto i:v)c[i]++;
	fore(i,0,SZ(v))v[i]=c[v[i]];
	return v;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<vector<ll>> vv={a};
		while(1){
			auto na=trans(vv.back());
			if(na!=vv.back())vv.pb(na);
			else break;
		}
		/*
		for(auto i:vv){
			for(auto j:i){
				cout<<j<<" ";
			}
			cout<<endl;
		}
		*/
		ll q; cin>>q;
		while(q--){
			ll x,k; cin>>x>>k; x--;
			k=min(k,SZ(vv)-1);
			cout<<vv[k][x]<<"\n";
		}
	}
	
	return 0;
}
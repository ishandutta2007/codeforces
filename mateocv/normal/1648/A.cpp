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

const int MAXN=100005;

vector<ll> gl[MAXN],gc[MAXN];

ll calc(vector<ll> v){
	sort(ALL(v));
	vector<ll> sump={0};
	for(auto i:v)sump.pb(sump.back()+i);
	ll res=0;
	fore(i,0,SZ(v)){
		res+=v[i]*i-sump[i];
	}
	return res;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,n){
		fore(j,0,m){
			ll x; cin>>x; x--;
			gl[x].pb(i);
			gc[x].pb(j);
		}
	}
	ll res=0;
	fore(i,0,MAXN){
		res+=calc(gl[i]);
		res+=calc(gc[i]);
	}
	cout<<res<<"\n";
	
	return 0;
}
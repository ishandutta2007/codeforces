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

ll a[505],aa[505],x;
vector<ll> v,va;

ll INF=2020;

ll solve(ll pos){
	va.clear();
	fore(i,0,SZ(v)){
		if(pos!=i)va.pb(v[i]);
	}
	ll res=0;
	ll xx=x;
	fore(i,0,SZ(v)-1)aa[i]=a[i];
	fore(i,0,SZ(v)-1){
		if(aa[i]!=va[i]){
			if(aa[i]<=xx||xx!=va[i])return INF;
			swap(aa[i],xx);
			res++;
		}
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n>>x;
		fore(i,0,n)cin>>a[i];
		v.clear();
		fore(i,0,n)v.pb(a[i]);
		v.pb(x);
		sort(ALL(v));
		ll res=INF;
		fore(i,0,n+1)res=min(res,solve(i));
		if(res==INF)cout<<"-1\n";
		else cout<<res<<"\n";
	}
	
	return 0;
}
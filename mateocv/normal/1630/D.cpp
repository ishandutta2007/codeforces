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

ll solve(vector<ll> a, ll m){
	vector<ll> mini(m,1e18),s(m),p(m);
	fore(i,0,SZ(a)){
		mini[i%m]=min(mini[i%m],abs(a[i]));
		s[i%m]+=abs(a[i]);
		if(a[i]<0)p[i%m]^=1;
	}
	//cout<<mini[0]<<" "<<s[0]<<" "<<p[0]<<"\n";
	ll res=0;
	fore(i,0,m){
		res+=s[i];
		if(p[i])res-=2ll*mini[i];
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll> b(m);
		fore(i,0,m)cin>>b[i];
		ll g=0;
		fore(i,0,m)g=__gcd(g,b[i]);
		ll res=solve(a,g);
		fore(i,0,g)a[i]=-a[i];
		res=max(res,solve(a,g));
		cout<<res<<"\n";
	}
	
	return 0;
}
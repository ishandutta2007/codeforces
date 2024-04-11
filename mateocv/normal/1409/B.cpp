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

ll solve(ll a, ll b, ll x, ll y, ll n){
	ll d=min(a-x,n);
	a-=d; n-=d;
	d=min(b-y,n);
	b-=d;
	return a*b;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll a,b,x,y,n; cin>>a>>b>>x>>y>>n;
		cout<<min(solve(a,b,x,y,n),solve(b,a,y,x,n))<<"\n";
		
	}
	
	return 0;
}
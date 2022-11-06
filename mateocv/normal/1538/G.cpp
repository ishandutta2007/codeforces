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

bool can(ll x, ll y, ll a, ll b, ll m){
	x-=m*a;
	y-=m*a;
	if(min(x,y)<0)return 0;
	if(a==b)return 1;
	return x/(b-a)+y/(b-a)>=m;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll x,y,a,b; cin>>x>>y>>a>>b;
		if(a>b)swap(a,b);
		ll l=0,r=x;
		while(r>=l){
			ll m=(l+r)/2;
			if(can(x,y,a,b,m))l=m+1;
			else r=m-1;
		}
		cout<<r<<"\n";
	}
	
	return 0;
}
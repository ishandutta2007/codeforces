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

vector<ll> tob(ll x){
	vector<ll> v;
	fore(i,0,30){
		if((1ll<<i)&x)v.pb(1);
		else v.pb(0);
	}
	return v;
}

ll sumv(vector<ll> v){
	ll sum=0;
	for(auto i:v)sum+=i;
	return sum;
}

bool solve(ll x, ll y){
	if(x>y)return false;
	auto tx=tob(x),ty=tob(y);
	ll c=0,d=0,dt=0;
	fore(i,0,30){
		c+=tx[i];
		if(ty[i]){
			if(c==0)return false;
			c--;
		}
		d=(d+c)/2;
		dt+=d;
	}
	return c<=dt;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll x,y; cin>>x>>y;
		auto res=solve(x,y);
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
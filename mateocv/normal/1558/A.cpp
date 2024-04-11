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

vector<ll> solve(ll a, ll b, ll d){
	if(b>a)swap(a,b);
	vector<ll> res={a-(a+b)/2+d};
	fore(i,0,b)res.pb(res.back()+2);
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll a,b; cin>>a>>b;
		set<ll> res;
		if((a+b)&1){
			vector<ll> v[4];
			if(a)v[0]=solve(a-1,b,0);
			if(b)v[1]=solve(a,b-1,1);
			if(a)v[2]=solve(a-1,b,1);
			if(b)v[3]=solve(a,b-1,0);
			fore(k,0,4)for(auto i:v[k])res.insert(i);
		}else{
			vector<ll> v=solve(a,b,0);
			for(auto i:v)res.insert(i);
		}
		cout<<SZ(res)<<"\n";
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}
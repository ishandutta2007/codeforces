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

bool can(vector<ll> &a, vector<ll> &b, ll mk){
	map<ll,ll> mpa,mpb;
	for(auto i:a)mpa[i&mk]++;
	for(auto i:b)mpb[i&mk]++;
	for(auto i:mpa){
		if(i.snd!=mpb[mk^i.fst])return 0;
	}
	return 1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		ll res=0;
		for(ll k=30;k>=0;k--){
			res+=(1ll<<k);
			if(!can(a,b,res))res-=(1ll<<k);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
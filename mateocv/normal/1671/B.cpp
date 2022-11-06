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

bool solve(ll s, vector<ll> a){
	for(auto i:a){
		s++;
		if(abs(i-s)>1)return 0;
	}
	return 1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n-1);
		ll s; cin>>s;
		fore(i,0,n-1)cin>>a[i];
		ll res=(solve(s-1,a)||solve(s,a)||solve(s+1,a));
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
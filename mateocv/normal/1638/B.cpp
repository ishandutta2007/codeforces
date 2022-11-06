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

bool iss(vector<ll> v){
	auto vs=v;
	sort(ALL(vs));
	return vs==v;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll> v[2];
		fore(i,0,n)v[a[i]&1].pb(a[i]);
		if(iss(v[0])&&iss(v[1]))cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
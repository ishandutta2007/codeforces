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

ll cont(vector<ll> v){
	map<ll,ll> mp;
	for(auto i:v)mp[i]++;
	ll maxi=0;
	for(auto i:mp){
		maxi=max(maxi,i.snd);
	}
	return max(0ll,maxi-SZ(v)/2);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		ll res=0;
		sort(ALL(a));
		fore(i,0,n-2*k)res+=a[i];
		vector<ll> v;
		fore(i,0,2*k)v.pb(a[n-1-i]);
		res+=cont(v);
		cout<<res<<"\n";
	}
	
	return 0;
}
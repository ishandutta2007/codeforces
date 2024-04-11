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

ll solve(vector<ll> v){
	ll val=0,res=0;
	for(auto i:v){
		ll c=(val+i)/i;
		res+=c;
		val=i*c;
	}
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	ll res=9e18;
	fore(i,0,n){
		vector<ll> v[2];
		fore(j,0,i)v[0].pb(a[j]);
		fore(j,i+1,n)v[1].pb(a[j]);
		reverse(ALL(v[0]));
		res=min(res,solve(v[0])+solve(v[1]));
	}
	cout<<res<<"\n";
	
	return 0;
}
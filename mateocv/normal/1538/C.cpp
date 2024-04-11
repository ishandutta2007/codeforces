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

ll solve(vector<ll> a, ll k){
	ll res=0;
	for(auto i:a){
		auto it=lower_bound(ALL(a),k-i+1);
		res+=it-a.begin();
		if(2*i<=k)res--;
	}
	return res/2;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,l,r; cin>>n>>l>>r;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		cout<<solve(a,r)-solve(a,l-1)<<"\n";
	}
	
	return 0;
}
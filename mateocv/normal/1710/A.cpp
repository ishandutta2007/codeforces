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

ll maxc(ll n){
	return n-(n==1);
}

bool solve(ll n, ll m, vector<ll> a){
	ll c=0,ya=0;
	for(auto i:a){
		c+=maxc(i/n);
		ya+=(i>=3*n);
	}
	if(m%2==0)return c>=m;
	return c>=m&&ya;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		vector<ll> a(k);
		fore(i,0,k)cin>>a[i];
		ll res=0;
		res=(res||solve(n,m,a));
		res=(res||solve(m,n,a));
		if(res)cout<<"Yes\n";
		else cout<<"No\n";
	}
	
	return 0;
}
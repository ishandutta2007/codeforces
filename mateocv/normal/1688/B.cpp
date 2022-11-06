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

ll v2(ll n){
	ll res=0;
	while(n%2==0)res++,n/=2;
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll c=0,mini=100;
		fore(i,0,n){
			ll x; cin>>x;
			mini=min(mini,v2(x));
			c+=(x%2==0);
		}
		c=min(c,n-1);
		cout<<mini+c<<"\n";
	}
	
	return 0;
}
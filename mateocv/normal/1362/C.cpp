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

map<ll,ll> mp;

ll solve(ll n){
	assert(n>=0);
	//cout<<n<<"\n";
	if(n<=1)return n;
	if(mp.count(n))return mp[n];
	fore(j,0,63){
		if((1ll<<(62-j))&n){
			mp[n]=solve(n%(1ll<<(62-j)))+solve((1ll<<(62-j))-1)+63-j;
			return mp[n];
		}
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		mp.clear();
		cout<<solve(n)<<"\n";
	}
	
	return 0;
}
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

ll solve(ll l, ll r){
	if(l==r)return 0;
	return r-l+solve(l/10,r/10);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll l,r; cin>>l>>r;
		cout<<solve(l,r)<<"\n";
	}
	
	return 0;
}
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

ll op(ll x, ll b){
	if(!b)return x/2+10;
	return x-10;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll x,n,m; cin>>x>>n>>m;
		fore(i,0,n){
			if(op(x,0)<x)x=op(x,0);
		}
		fore(i,0,m)x=op(x,1);
		if(x<=0)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
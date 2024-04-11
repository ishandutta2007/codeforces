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

int main(){FIN;
	vector<ll> v={1};
	fore(i,0,9)v.pb(10ll*v.back());
	ll t; cin>>t;
	while(t--){
		ll m; cin>>m;
		ll res=m;
		for(auto i:v){
			if(i<=m)res=min(res,m-i);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}
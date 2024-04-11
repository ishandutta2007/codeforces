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
	ll t; cin>>t;
	while(t--){
		ll a,b,c,x,y; cin>>a>>b>>c>>x>>y;
		x=max(0ll,x-a);
		y=max(0ll,y-b);
		if(x+y<=c)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
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
		vector<ll> v(3);
		fore(i,0,3)cin>>v[i];
		sort(ALL(v));
		if(v[0]+v[1]==v[2])cout<<"YES\n";
		else cout<<"NO\n";	
	}
	
	return 0;
}
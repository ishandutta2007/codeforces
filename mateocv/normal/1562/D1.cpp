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
		ll n,q; cin>>n>>q;
		string s; cin>>s;
		vector<ll> sump={0};
		fore(i,0,SZ(s)){
			ll val=((s[i]=='+')?1:-1);
			sump.pb(sump.back()+((i&1)?-val:val));
		}
		while(q--){
			ll l,r; cin>>l>>r; l--;
			if((r-l)&1)cout<<"1\n";
			else{
				if(sump[r]==sump[l])cout<<"0\n";
				else cout<<"2\n";
			}
		}
	}
	
	return 0;
}
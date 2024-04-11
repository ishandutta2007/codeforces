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
	ll n,q; cin>>n>>q;
	string s; cin>>s;
	vector<ll> sump(n+1);
	fore(i,0,n){
		sump[i+1]=sump[i]+s[i]-'a'+1;
	}
	while(q--){
		ll l,r; cin>>l>>r; l--;
		cout<<sump[r]-sump[l]<<"\n";
	}
	
	return 0;
}